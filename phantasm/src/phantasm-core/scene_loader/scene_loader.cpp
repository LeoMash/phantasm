#include <fstream>

#include "scene_loader.h"

#include "objects\sphere.h"
#include "logger\logger.h"

#include "json\json.h"
#include "json\json-forwards.h"

PHM_CORE_API bool  LoadSceneFromJSON (SCENE & scn, std::string fileName)
{
   Json::Value root;
   Json::Reader reader;

   std::ifstream inFile(fileName);

   bool parsingSuccessful = reader.parse(inFile, root);

   if (!parsingSuccessful)
   {
      LogMessage(LOGGING_LEVELS::ERROR, "Failed to parse JSON file : " + reader.getFormattedErrorMessages());
      //LogError("Failed to parse JSON file : " + reader.getFormattedErrorMessages());

      return false;
   }

   const Json::Value bckg = root["background"];
   scn.SetBackgroundColor(RGB(bckg[0].asUInt(), bckg[1].asUInt(), bckg[2].asUInt()));

   const Json::Value cam = root["camera"];

   const Json::Value camPos    = cam["position"];
   const Json::Value lookAt    = cam["lookAt"];
   const Json::Value up        = cam["up"];
   const Json::Value viewAngle = cam["viewAngle"];

   scn.SetCamera(VEC(camPos[0].asDouble(),
      camPos[1].asDouble(),
      camPos[2].asDouble()),
      VEC(lookAt[0].asDouble(),
         lookAt[1].asDouble(),
         lookAt[2].asDouble()),
      VEC(up[0].asDouble(),
         up[1].asDouble(),
         up[2].asDouble()),
      viewAngle.asDouble());


   const Json::Value lights = root["lights"];
   for (unsigned int index = 0; index < lights.size(); index++) {
      const Json::Value obj = lights[index];

      const Json::Value pos = obj["position"];
      const Json::Value color = obj["color"];

      scn.AddLight(new POINT_LIGHT(VEC(pos[0].asDouble(),
         pos[1].asDouble(),
         pos[2].asDouble()),
         RGB(color[0].asUInt(),
            color[1].asUInt(),
            color[2].asUInt())));
   }


   const Json::Value objects = root["objects"];
   for (unsigned int index = 0; index < objects.size(); index++) {
      const Json::Value obj = objects[index];

      const Json::Value pos   = obj["position"];
      const Json::Value color = obj["color"];
      const Json::Value mtl   = obj["material"];

      scn.AddObject(new SPHERE(
         obj["radius"].asDouble(),


         VEC(pos[0].asDouble(), 
             pos[1].asDouble(),
             pos[2].asDouble()),


         MTL(mtl["Ka"].asDouble(),
             mtl["Ks"].asDouble(),
             mtl["Kd"].asDouble(),
             mtl["Phong"].asDouble(),
             mtl["Refl"].asBool(),
             mtl["Refr"].asDouble(),

             RGB(color[0].asUInt(),
                 color[1].asUInt(),
                 color[2].asUInt()))));
   }

   return true;
}
