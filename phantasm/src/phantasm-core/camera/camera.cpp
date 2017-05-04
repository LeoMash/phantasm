#include <math.h>

#include "logger\logger.h"

#include "camera.h"

CAM::CAM (VEC position, VEC lookAtVec, VEC upVec, double viewAngle, int newWidth, int newHeight) : pos(position), angle(viewAngle), width(newWidth), height(newHeight)
{
   dir = (lookAtVec - position).Normalize();
   right = (upVec.Cross(dir)).Normalize();
   up = (right.Cross(dir)).Normalize();

   tanX = tan(angle);
   tanY = tan((static_cast<double>(newHeight) / static_cast<double>(newWidth)) * angle);
}

void CAM::SetWH (int newWidth, int newHeight)
{
   width = newWidth;
   height = newHeight;
   
   tanX = tan(angle);
   tanY = tan((static_cast<double>(newHeight) / static_cast<double>(newWidth)) * angle);
}


RAY CAM::GetDirectionRay (double x, double y) const
{
   if (x < 0.0 || x > 1.0 || y > 1.0 || y < 0.0) {
      LogMessage(LOGGING_LEVELS::ERROR, "Error in creating ray from camera check x & y : ");
   }

   VEC xDir = right * ((x - 0.5) * tanX);
   VEC yDir = up * ((y - 0.5) * tanY);

   VEC resDir = (dir + xDir + yDir).Normalize();

   return RAY(pos, resDir);
}
