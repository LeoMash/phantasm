#include "scene_loader.h"

#include "..\objects\sphere.h"

void PHM_CORE_API LoadSceneFromJSON (SCENE & scn, std::string fileName)
{
   scn.AddObject(new SPHERE(5.0, VEC(5.0,  0.0, 0.0), RGB(255, 0,   0)));
   scn.AddObject(new SPHERE(5.0, VEC(15.0, 5.0, 0.0), RGB(0,   255, 0)));
   scn.AddObject(new SPHERE(5.0, VEC(10.0, 5.0, 5.0), RGB(0,   0,   255)));
}
