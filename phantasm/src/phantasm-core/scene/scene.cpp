#include "common.h"

#include <vector>
#include <algorithm>

#include "light\light.h"

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

   void AddObject (OBJECT * newObj)
   {
      objects.push_back(newObj);
   }

   size_t GetSize (void)
   {
      return objects.size();
   }

   OBJECT * operator[] (int index)
   {
      return objects[index];
   }

   const OBJECT * operator[] (int index) const
   {
      return objects[index];
   }

   void SetCamera (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width, int height)
   {
      camera = CAM(position, lookAtVec, upVec, viewAngle, width, height);
   }

   RAY GetRay (double x, double y) const
   {
      return camera.GetDirectionRay(x, y);
   }

   std::vector<OBJECT *> objects;
   std::vector<LIGHT *> lights;
   CAM camera;
};

SCENE::SCENE (void) : pImpl(new SCENE::IMPL())
{

}

SCENE::~SCENE (void)
{
   delete(pImpl);
}

void SCENE::SetCamera (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width, int height)
{
   pImpl->SetCamera(position, lookAtVec, upVec, viewAngle, width, height);
}

RAY SCENE::GetRay (double x, double y) const
{
   return pImpl->GetRay(x, y);
}

void SCENE::AddObject (OBJECT * newObj)
{
   pImpl->AddObject(newObj);
}

OBJECT * SCENE::operator[] (unsigned int index)
{
   return (*pImpl)[index];
}

const OBJECT * SCENE::operator[] (unsigned int index) const
{
   return (*pImpl)[index];
}

SCENE_ITERATOR SCENE::Begin (void)
{
   return SCENE_ITERATOR(0, *pImpl);
}

SCENE_ITERATOR SCENE::End (void)
{
   return SCENE_ITERATOR(static_cast<unsigned int>(pImpl->GetSize()), *pImpl);
}

SCENE_CONST_ITERATOR SCENE::Begin (void) const
{
   return SCENE_CONST_ITERATOR(0, *pImpl);
}

SCENE_CONST_ITERATOR SCENE::End (void) const
{
   return SCENE_CONST_ITERATOR(static_cast<unsigned int>(pImpl->GetSize()), *pImpl);
}

SCENE_ITERATOR::SCENE_ITERATOR (unsigned int ind, SCENE::IMPL & scn) : index(ind), scene(scn)
{
}

SCENE_ITERATOR::SCENE_ITERATOR (const SCENE_ITERATOR & it) : index(it.index), scene(it.scene)
{
}

SCENE_ITERATOR::~SCENE_ITERATOR (void)
{
}

OBJECT * SCENE_ITERATOR::operator* (void)
{
   return scene[index];
}

SCENE_ITERATOR & SCENE_ITERATOR::operator++ (void)
{
   index++;

   return *this;
}

SCENE_ITERATOR SCENE_ITERATOR::operator++ (int)
{
   SCENE_ITERATOR temp = *this;

   index++;

   return temp;
}

bool SCENE_ITERATOR::operator== (const SCENE_ITERATOR & it) const
{
   if (&it.scene == &scene && it.index == index) {
      return true;
   }

   return false;
}

bool SCENE_ITERATOR::operator!= (const SCENE_ITERATOR & it) const
{
   if (&it.scene != &scene || it.index != index) {
      return true;
   }

   return false;
}


SCENE_CONST_ITERATOR::SCENE_CONST_ITERATOR (unsigned int ind, SCENE::IMPL & scn) : index(ind), scene(scn)
{
}

SCENE_CONST_ITERATOR::SCENE_CONST_ITERATOR (const SCENE_CONST_ITERATOR & it) : index(it.index), scene(it.scene)
{
}

SCENE_CONST_ITERATOR::~SCENE_CONST_ITERATOR (void)
{
}

const OBJECT * SCENE_CONST_ITERATOR::operator* (void) const
{
   return scene[index];
}

SCENE_CONST_ITERATOR & SCENE_CONST_ITERATOR::operator++ (void)
{
   index++;

   return (*this);
}

SCENE_CONST_ITERATOR SCENE_CONST_ITERATOR::operator++ (int)
{
   SCENE_CONST_ITERATOR temp = *this;

   index++;

   return temp;
}

bool SCENE_CONST_ITERATOR::operator== (const SCENE_CONST_ITERATOR & it) const
{
   if (&it.scene == &scene && it.index == index) {
      return true;
   }

   return false;
}

bool SCENE_CONST_ITERATOR::operator!= (const SCENE_CONST_ITERATOR & it) const
{
   if (&it.scene != &scene || it.index != index) {
      return true;
   }

   return false;
}
