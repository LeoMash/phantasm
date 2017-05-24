#include "sphere.h"

SPHERE::SPHERE (void) : OBJECT() , radius(5)
{

}

SPHERE::SPHERE (double rad, VEC pos, MTL mtl) : OBJECT(pos, mtl) , radius(rad)
{

}

SPHERE::~SPHERE(void)
{

}

bool SPHERE::Intersect (const RAY & ray, INTERSECTION & intersection) const
{
   VEC dist = (GetPosition() - ray.start);
   double b = ray.dir.Dot(dist);

   if (b < 0) {
      return false;
   }

   double d = b * b - dist.Dot(dist) + radius * radius;

   static double eps = 1e-8;

   if (d < 0) {
      return false;
   }

   intersection.intersectPoints.push_back(ray.start + VEC(ray.dir) * (b - sqrt(d)));
   intersection.intersectPoints.push_back(ray.start + VEC(ray.dir) * (b + sqrt(d)));
   intersection.obj = this;

   return true;
}

VEC SPHERE::GetNormal (VEC point) const
{
   return (point - GetPosition()).Normalize();
}
