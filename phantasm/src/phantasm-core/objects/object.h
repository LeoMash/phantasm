#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "phm_core.h"

#include <vector>

#include "math\vec.h"
#include "tracer\ray.h"
#include "common.h"
#include "material\material.h"

class OBJECT;

struct INTERSECTION {
   std::vector<VEC> intersectPoints;
   const OBJECT * obj;
};

class PHM_CORE_API OBJECT {
public:
   OBJECT (void);
   OBJECT (VEC pos, MTL mtl);
   virtual ~OBJECT (void);

   virtual bool Intersect (const RAY & ray, INTERSECTION & intersection) const  = 0;

   virtual VEC GetNormal (VEC point) const = 0;

   MTL GetMaterial (void) const { return material; }
   VEC GetPosition (void) const { return position; }
private:
   VEC position;
   MTL material;
};

#endif // _OBJECT_H_
