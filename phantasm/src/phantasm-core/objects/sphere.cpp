#include "sphere.h"

SPHERE::SPHERE (void) : OBJECT() , radius(5)
{

}

SPHERE::SPHERE (double rad, VEC pos, RGB color) : OBJECT(pos, color) , radius(rad)
{

}

SPHERE::~SPHERE(void)
{

}

INTERSECT_PARAMS SPHERE::Intersect(const RAY & ray)
{
   INTERSECT_PARAMS returnParams;

   VEC dist = (GetPosition() - ray.startingPnt);
   double b = ray.dir.Dot(dist);
   double d = b * b - dist.Dot(dist) + radius * radius;

   static double eps = 0.001;

   if (d < eps) {
      returnParams.isIntersect = false;
      return returnParams;
   }

   returnParams.distantDistance = b - sqrt(d);
   returnParams.nearDistance = b + sqrt(d);

   returnParams.isIntersect = true;

   returnParams.color = GetColor();

   return returnParams;
}
