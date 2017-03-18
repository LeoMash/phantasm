#include "..\common.h"

#include <vector>

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
