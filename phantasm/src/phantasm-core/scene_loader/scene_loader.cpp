#include <fstream>

#include "logger/logger.h"

#include "scene_loader.h"
#include "scene_loader_accompanying.h"

PHM_CORE_API bool LoadSceneFromJSON (SCENE & scn, std::string fileName)
{
   Json::Value root;
   Json::Reader reader;

   std::ifstream inFile(fileName);

   bool parsingSuccessful = reader.parse(inFile, root);

   if (!parsingSuccessful)
   {
      LogError("Failed to parse JSON file : " + reader.getFormattedErrorMessages());

      return false;
   }

   SetScene(root, scn);

   return true;
}
