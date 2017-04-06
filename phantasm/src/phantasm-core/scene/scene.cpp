#include "..\common.h"

#include <vector>
#include <algorithm>

#include "scene.h"

struct SCENE::IMPL {
   IMPL (void)
   {
   
   }
   
   ~IMPL (void)
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


SCENE::SCENE (void) : pImpl(new SCENE::IMPL())
{

}

SCENE::~SCENE (void)
{
   delete(pImpl);
}

void SCENE::AddObject (OBJECT * newObj)
{
   pImpl->AddObject(newObj);
}

void SCENE::IntersectAll (const RAY & ray, std::vector<INTERSECT_PARAMS> & prms) const
{
   std::for_each(pImpl->objects.begin(), pImpl->objects.end(),
      [&prms, &ray](OBJECT * obj) {prms.push_back(obj->Intersect(ray)); });
}
