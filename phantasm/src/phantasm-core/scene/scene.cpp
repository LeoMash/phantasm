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
      for (auto & o : objects) {
         delete o;
      }

      for (auto & l : lights) {
         delete l;
      }
   }


   std::vector<OBJECT *> objects;
   std::vector<LIGHT *> lights;

   CAM camera;
   RGB backgroundColor;
   int maxDepth;
};


SCENE::SCENE (void) : pImpl(new SCENE::IMPL())
{

}


SCENE::~SCENE (void)
{
   delete pImpl;
}


void SCENE::SetCamera (const CAM & cam)
{
   pImpl->camera = cam;
}


void SCENE::SetCameraWH (int W, int H)
{
   pImpl->camera.SetWH(W, H);
}


RAY SCENE::GetRay (double x, double y) const
{
   return pImpl->camera.GetDirectionRay(x, y);
}

void SCENE::SetBackgroundColor (const RGB & color)
{
   pImpl->backgroundColor = color;
}

RGB SCENE::GetBackgroundColor(void) const
{
   return pImpl->backgroundColor;
}


void SCENE::SetMaxDepth (int depth)
{
   pImpl->maxDepth = depth;
}


int SCENE::GetMaxDepth (void) const
{
   return pImpl->maxDepth;
}


void SCENE::AddObject (OBJECT * newObj)
{
   pImpl->objects.push_back(newObj);
}


void SCENE::AddLight (LIGHT * newLight)
{
   pImpl->lights.push_back(newLight);
}



SCENE::SCENE_LIGHTS_ITERATOR SCENE::BeginLights (void)
{
   return SCENE_LIGHTS_ITERATOR(pImpl->lights.begin(), &pImpl->lights);
}

SCENE::SCENE_LIGHTS_ITERATOR SCENE::EndLights (void)
{
   return SCENE_LIGHTS_ITERATOR(pImpl->lights.end(), &pImpl->lights);
}

SCENE::SCENE_CONST_LIGHTS_ITERATOR SCENE::BeginLights (void) const
{
   return SCENE_CONST_LIGHTS_ITERATOR(pImpl->lights.begin(), &pImpl->lights);
}

SCENE::SCENE_CONST_LIGHTS_ITERATOR SCENE::EndLights (void) const
{
   return SCENE_CONST_LIGHTS_ITERATOR(pImpl->lights.end(), &pImpl->lights);
}



SCENE::SCENE_OBJECTS_ITERATOR SCENE::BeginObjects (void)
{
   return SCENE_OBJECTS_ITERATOR(pImpl->objects.begin(), &pImpl->objects);
}

SCENE::SCENE_OBJECTS_ITERATOR SCENE::EndObjects (void)
{
   return SCENE_OBJECTS_ITERATOR(pImpl->objects.end(), &pImpl->objects);
}

SCENE::SCENE_CONST_OBJECTS_ITERATOR SCENE::BeginObjects (void) const
{
   return SCENE_CONST_OBJECTS_ITERATOR(pImpl->objects.begin(), &pImpl->objects);
}

SCENE::SCENE_CONST_OBJECTS_ITERATOR SCENE::EndObjects (void) const
{
   return SCENE_CONST_OBJECTS_ITERATOR(pImpl->objects.end(), &pImpl->objects);
}


