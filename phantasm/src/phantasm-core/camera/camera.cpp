#include <math.h>
#include <assert.h>

#include "camera.h"

CAM::CAM (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int width, int height) : pos(position), angle(viewAngle)
{
   dir = (lookAtVec - position).Normalize();
   right = (upVec.Cross(dir)).Normalize();
   up = (right.Cross(dir)).Normalize();

   tanX = tan(angle);
   tanY = tan((static_cast<double>(height) / static_cast<double>(width)) * angle);
}

RAY CAM::GetDirectionRay (double x, double y) const
{
   assert(x <= 1.0 && x >= 0.0);
   assert(y <= 1.0 && y >= 0.0);

   VEC xDir = right * ((x - 0.5) * tanX);
   VEC yDir = up * ((y - 0.5) * tanY);

   VEC resDir = (dir + xDir + yDir).Normalize();

   return RAY(pos, resDir);
}
