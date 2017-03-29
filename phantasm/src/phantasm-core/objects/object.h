#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "..\phm_core.h"

#include "..\math\vecmat.h"
#include "..\tracer\ray.h"
#include "..\common.h"
#include "..\material\material.h"

struct INTERSECT_PARAMS {
   bool   isIntersect;
   double distantDistance;
   double nearDistance;
   RGB    color;
};

class PHM_CORE_API OBJECT {
public:
   OBJECT (void);
   OBJECT (VEC pos, RGB clr);
   virtual ~OBJECT (void);

   virtual INTERSECT_PARAMS Intersect (const RAY & ray);

   RGB GetColor    (void) const { return color; }
   VEC GetPosition (void) const { return position; }
private:
   VEC position;
   RGB color;
};

#endif // _OBJECT_H_
