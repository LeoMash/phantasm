#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "phm_core.h"

#include "objects\object.h"
#include "objects\sphere.h"
#include "camera\camera.h"
#include "light\light.h"


template <typename SCENE_ITERATOR_TYPE>
class SCENE_ITERATOR;

template <typename SCENE_ITERATOR_TYPE>
class SCENE_CONST_ITERATOR;



class PHM_CORE_API SCENE {

   using SCENE_LIGHTS_ITERATOR  = SCENE_ITERATOR<LIGHT *>;
   using SCENE_OBJECTS_ITERATOR = SCENE_ITERATOR<OBJECT *>;

   using SCENE_CONST_LIGHTS_ITERATOR  = SCENE_CONST_ITERATOR<LIGHT *>;
   using SCENE_CONST_OBJECTS_ITERATOR = SCENE_CONST_ITERATOR<OBJECT *>;

public:
   struct IMPL;

   SCENE (void);
   ~SCENE (void);

   void SetCamera (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width = 500, int height = 500);

   void SetCameraWH (int W, int H);

   RAY  GetRay (double x, double y) const;

   void SetBackgroundColor (const RGB & color);
   RGB GetBackgroundColor (void) const;

   void AddObject (OBJECT * newObj);

   void AddLight (LIGHT * newLight);

   SCENE_LIGHTS_ITERATOR BeginLights (void);
   SCENE_LIGHTS_ITERATOR EndLights (void);

   SCENE_CONST_LIGHTS_ITERATOR BeginLights (void) const;
   SCENE_CONST_LIGHTS_ITERATOR EndLights   (void) const;


   SCENE_OBJECTS_ITERATOR BeginObjects (void);
   SCENE_OBJECTS_ITERATOR EndObjects (void);

   SCENE_CONST_OBJECTS_ITERATOR BeginObjects (void) const;
   SCENE_CONST_OBJECTS_ITERATOR EndObjects   (void) const;


private:
   IMPL * pImpl;
};


template <typename SCENE_ITERATOR_TYPE>
class SCENE_ITERATOR {
public:
   SCENE_ITERATOR  (typename std::vector<SCENE_ITERATOR_TYPE>::iterator iterator, std::vector<SCENE_ITERATOR_TYPE> * objects);
   SCENE_ITERATOR  (const SCENE_ITERATOR & iter);
   ~SCENE_ITERATOR (void);

   SCENE_ITERATOR_TYPE operator*  (void);

   SCENE_ITERATOR & operator++ (void);
   SCENE_ITERATOR operator++ (int);


   bool operator== (const SCENE_ITERATOR & iter) const;
   bool operator!= (const SCENE_ITERATOR & iter) const;
private:
   typename std::vector<SCENE_ITERATOR_TYPE>::iterator it;
   std::vector<SCENE_ITERATOR_TYPE> * obj;
};


template <typename SCENE_ITERATOR_TYPE>
class SCENE_CONST_ITERATOR {
public:
   SCENE_CONST_ITERATOR  (typename std::vector<SCENE_ITERATOR_TYPE>::const_iterator iterator, const std::vector<SCENE_ITERATOR_TYPE> * objects);
   SCENE_CONST_ITERATOR  (const SCENE_CONST_ITERATOR & iter);
   ~SCENE_CONST_ITERATOR (void);

   const SCENE_ITERATOR_TYPE operator*  (void) const;

   SCENE_CONST_ITERATOR & operator++ (void);
   SCENE_CONST_ITERATOR   operator++ (int);

   bool operator== (const SCENE_CONST_ITERATOR & iter) const;
   bool operator!= (const SCENE_CONST_ITERATOR & iter) const;
private:
   typename std::vector<SCENE_ITERATOR_TYPE>::const_iterator it;
   const std::vector<SCENE_ITERATOR_TYPE> * obj;
};

#include "scene.hpp"

#endif // _SCENE_H_
