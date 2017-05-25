#include "sphere.h"

SPHERE::SPHERE (void) : OBJECT() , radius(5)
{

}

SPHERE::SPHERE (const double & rad, VEC pos, const MTL & mtl) : OBJECT(pos, mtl), radius(rad)
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
