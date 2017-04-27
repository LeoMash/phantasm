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
      LogMessage("Failed to parse JSON file : " + reader.getFormattedErrorMessages());
      
      return false;
   }

   const Json::Value objects = root["objects"];
   for (unsigned int index = 0; index < objects.size(); index++) {
      const Json::Value obj = objects[index];

      const Json::Value pos =   obj["position"];
      const Json::Value color = obj["color"];

      scn.AddObject(new SPHERE(
         obj["radius"].asDouble(),
         VEC(pos[0].asDouble(), 
             pos[1].asDouble(),
             pos[2].asDouble()),
         RGB(color[0].asUInt(), 
             color[1].asUInt(),
             color[2].asUInt())));
   }

   return true;
}
