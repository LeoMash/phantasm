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

bool SPHERE::Intersect (const RAY & ray, INTERSECTION & intersection) const
{
   VEC dist = (GetPosition() - ray.start);
   double b = ray.dir.Dot(dist);
   double d = b * b - dist.Dot(dist) + radius * radius;

   static double eps = 0.001;

   if (d < eps) {
      return false;
   }

   intersection.distance = b - sqrt(d);
   intersection.obj = this;

   return true;
}
