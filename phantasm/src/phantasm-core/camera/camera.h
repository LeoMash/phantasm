#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "phm_core.h"

#include "math\vec.h"
#include "tracer\ray.h"

class PHM_CORE_API CAM {
public:
   CAM (void) {}
   ~CAM (void) {}

   CAM (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int newWidth = 500, int newHeight = 500);

   void SetWH (int newWidth, int newHeight);

   RAY GetDirectionRay (double x, double y) const;

private:
   VEC pos;

   VEC dir;
   VEC right;
   VEC up;

   double FOVtangent;
   double aspectRatio;
};

#endif // _CAMERA_H_
