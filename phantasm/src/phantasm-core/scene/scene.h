#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "phm_core.h"

#include "objects\object.h"
#include "objects\sphere.h"
#include "camera\camera.h"

class SCENE_ITERATOR;
class SCENE_CONST_ITERATOR;

class PHM_CORE_API SCENE {
   friend SCENE_ITERATOR;
   friend SCENE_CONST_ITERATOR;

public:
   struct IMPL;

   SCENE (void);
   ~SCENE (void);

   void SetCamera (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width, int height);
   RAY  GetRay (double x, double y) const;

   void AddObject (OBJECT * newObj);

   OBJECT * operator[] (unsigned int index);
   const OBJECT * operator[] (unsigned int index) const;

   SCENE_ITERATOR Begin (void);
   SCENE_ITERATOR End (void);
   SCENE_CONST_ITERATOR Begin (void) const;
   SCENE_CONST_ITERATOR End   (void) const;
private:
   IMPL * pImpl;
};

class SCENE_ITERATOR {
public:
   SCENE_ITERATOR  (unsigned int ind, SCENE::IMPL & scn);
   SCENE_ITERATOR  (const SCENE_ITERATOR & it);
   ~SCENE_ITERATOR (void);

   OBJECT * operator*  (void);

   SCENE_ITERATOR & operator++ (void);
   SCENE_ITERATOR operator++ (int);


   bool operator== (const SCENE_ITERATOR & it) const;
   bool operator!= (const SCENE_ITERATOR & it) const;
private:
   unsigned int index;
   SCENE::IMPL & scene;
};

class SCENE_CONST_ITERATOR {
public:
   SCENE_CONST_ITERATOR  (unsigned int ind, SCENE::IMPL & scn);
   SCENE_CONST_ITERATOR  (const SCENE_CONST_ITERATOR & it);
   ~SCENE_CONST_ITERATOR (void);

   const OBJECT * operator*  (void) const;

   SCENE_CONST_ITERATOR & operator++ (void);
   SCENE_CONST_ITERATOR   operator++ (int);

   bool operator== (const SCENE_CONST_ITERATOR & it) const;
   bool operator!= (const SCENE_CONST_ITERATOR & it) const;
private:
   unsigned int index;
  const SCENE::IMPL & scene;
};

#endif // _SCENE_H_
