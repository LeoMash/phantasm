#include <fstream>

#include "scene_loader.h"

#include "..\objects\sphere.h"

#include "..\..\..\3rd-party\jsoncpp\json\json.h"
#include "..\..\..\3rd-party\jsoncpp\json\json-forwards.h"

bool PHM_CORE_API LoadSceneFromJSON (SCENE & scn, std::string fileName)
{
   Json::Value root;
   Json::Reader reader;

   std::ifstream inFile(fileName);

   bool parsingSuccessful = reader.parse(inFile, root);

   inFile.close();

   if (!parsingSuccessful)
   {
      std::ofstream errFile("..\\..\\bin\\error_log.txt");
      errFile << "Failed to parse JSON file : " << reader.getFormattedErrorMessages();
      errFile.close();
      return false;
   }

   const Json::Value objects = root["objects"];
   for (unsigned int index = 0; index < objects.size(); index++) {
      scn.AddObject(new SPHERE(
         objects[index].get("radius", 0.0).asDouble(),
         VEC(objects[index]["position"][0].asDouble(), 
             objects[index]["position"][1].asDouble(),
             objects[index]["position"][2].asDouble()),
         RGB(objects[index]["color"][0].asUInt(), 
             objects[index]["color"][1].asUInt(),
             objects[index]["color"][2].asUInt())));
   }

   return true;
}
