#include "..\common.h"

#include <vector>
#include <algorithm>

#include "scene.h"

struct SCENE_IMPL {
   SCENE_IMPL (void)
   {
   
   }
   
   ~SCENE_IMPL (void)
   {
      Clear();
   }

   void Clear (void)
   {
      objects.clear();
   }

   void AddObject(OBJECT * newObj)
   {
      objects.push_back(newObj);
   }

   std::vector<OBJECT *> objects;
 
};


SCENE::SCENE (void) : pImpl(new SCENE_IMPL())
{

}

SCENE::~SCENE (void)
{
   pImpl->Clear();
   delete(pImpl);
}

void SCENE::AddObject (OBJECT * newObj)
{
   pImpl->AddObject(newObj);
}

void SCENE::IntersectAll (const RAY & ray, std::vector<INTERSECT_PARAMS> & prms) const
{
   std::for_each(pImpl->objects.begin(), pImpl->objects.end(),
      [&](OBJECT * obj) {prms.push_back(obj->Intersect(ray)); });
}
