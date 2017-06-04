#include <math.h>

#include "logger\logger.h"

#include "camera.h"

CAM::CAM (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int newWidth, int newHeight) : pos(position)
{
   dir = (lookAtVec - position).Normalize();
   right = (upVec.Cross(dir)).Normalize();
   up = (right.Cross(dir)).Normalize();

   FOVtangent = tan(viewAngle / 360.0 * M_PI);     // tan(FOV / 2)
}

void CAM::SetWH (int newWidth, int newHeight)
{
   aspectRatio = static_cast<double>(newWidth) / static_cast<double>(newHeight);
}


RAY CAM::GetDirectionRay (double x, double y) const
{
   if (x < 0.0 || x > 1.0 || y > 1.0 || y < 0.0) {
      LogError("Error in creating ray from camera check x : " + std::to_string(x) + "& y : " + std::to_string(y));
   }

   VEC xDir = right * (2.0 * x - 1.0) * aspectRatio * FOVtangent;
   VEC yDir = up * (1.0 - 2.0 * y) * FOVtangent;

   VEC resDir = (dir + xDir + yDir).Normalize();

   return RAY(pos, resDir);
}
