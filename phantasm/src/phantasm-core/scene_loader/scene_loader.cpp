#include "scene_loader.h"

#include "..\objects\sphere.h"

void PHM_CORE_API LoadSceneFromJSON (SCENE & scn, std::string fileName)
{
   scn.AddObject(new SPHERE());
}
