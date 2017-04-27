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

   CAM (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width, int height);

   RAY GetDirectionRay (double x, double y) const; // x, y is in a range of [0, 1]

private:
   VEC pos;

   VEC dir;
   VEC right;
   VEC up;

   double angle;

   double tanX;
   double tanY;
};

#endif // _CAMERA_H_
