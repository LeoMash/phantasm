#include "common.h"

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

   void AddObject(rtrOBJECT * newObj)
   {
      objects.push_back(newObj);
   }

   std::vector<rtrOBJECT *> objects;
 
};


rtrSCENE::rtrSCENE (void) : pImpl(new SCENE_IMPL())
{

}

rtrSCENE::~rtrSCENE (void)
{
   pImpl->Clear();
   delete(pImpl);
}

void rtrSCENE::AddObject (rtrOBJECT * newObj)
{
   pImpl->AddObject(newObj);
}
