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


   void AddLight (LIGHT * newObj)
   {
      lights.push_back(newObj);
   }

   size_t GetSize (void)
   {
      return objects.size();
   }



   std::vector<LIGHT *> & GetLightsVector (void)
   {
      return lights;
   }

   const std::vector<LIGHT *> & GetLightsVector (void) const
   {
      return lights;
   }

   std::vector<OBJECT *> & GetObjectsVector (void)
   {
      return objects;
   }

   const std::vector<OBJECT *> & GetObjectsVector (void) const
   {
      return objects;
   }



   void SetCamera (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width, int height)
   {
      camera = CAM(position, lookAtVec, upVec, viewAngle, width, height);
   }

   void SetCameraWH (int W, int H)
   {
      camera.SetWH(W, H);
   }

   RAY GetRay (double x, double y) const
   {
      return camera.GetDirectionRay(x, y);
   }



   std::vector<OBJECT *> objects;
   std::vector<LIGHT *> lights;
   CAM camera;
   RGB backgroundColor;
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


void SCENE::SetCameraWH (int W, int H)
{
   pImpl->SetCameraWH(W, H);
}


RAY SCENE::GetRay (double x, double y) const
{
   return pImpl->GetRay(x, y);
}

void SCENE::SetBackgroundColor (const RGB & color)
{
   pImpl->backgroundColor = color;
}

RGB SCENE::GetBackgroundColor(void) const
{
   return pImpl->backgroundColor;
}


void SCENE::AddObject (OBJECT * newObj)
{
   pImpl->AddObject(newObj);
}


void SCENE::AddLight (LIGHT * newLight)
{
   pImpl->AddLight(newLight);
}



SCENE::SCENE_LIGHTS_ITERATOR SCENE::BeginLights (void)
{
   return SCENE_LIGHTS_ITERATOR(pImpl->GetLightsVector().begin(), &pImpl->GetLightsVector());
}

SCENE::SCENE_LIGHTS_ITERATOR SCENE::EndLights (void)
{
   return SCENE_LIGHTS_ITERATOR(pImpl->GetLightsVector().end(), &pImpl->GetLightsVector());
}

SCENE::SCENE_CONST_LIGHTS_ITERATOR SCENE::BeginLights (void) const
{
   return SCENE_CONST_LIGHTS_ITERATOR(pImpl->GetLightsVector().begin(), &pImpl->GetLightsVector());
}

SCENE::SCENE_CONST_LIGHTS_ITERATOR SCENE::EndLights (void) const
{
   return SCENE_CONST_LIGHTS_ITERATOR(pImpl->GetLightsVector().end(), &pImpl->GetLightsVector());
}



SCENE::SCENE_OBJECTS_ITERATOR SCENE::BeginObjects (void)
{
   return SCENE_OBJECTS_ITERATOR(pImpl->GetObjectsVector().begin(), &pImpl->GetObjectsVector());
}

SCENE::SCENE_OBJECTS_ITERATOR SCENE::EndObjects (void)
{
   return SCENE_OBJECTS_ITERATOR(pImpl->GetObjectsVector().end(), &pImpl->GetObjectsVector());
}

SCENE::SCENE_CONST_OBJECTS_ITERATOR SCENE::BeginObjects (void) const
{
   return SCENE_CONST_OBJECTS_ITERATOR(pImpl->GetObjectsVector().begin(), &pImpl->GetObjectsVector());
}

SCENE::SCENE_CONST_OBJECTS_ITERATOR SCENE::EndObjects (void) const
{
   return SCENE_CONST_OBJECTS_ITERATOR(pImpl->GetObjectsVector().end(), &pImpl->GetObjectsVector());
}


