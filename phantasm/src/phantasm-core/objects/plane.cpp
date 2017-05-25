#include "plane.h"


PLANE::PLANE (void) : OBJECT(), normal(VEC(0, 1, 0))
{

}


PLANE::PLANE (const VEC & norm, const VEC & pos, const MTL & mtl) : OBJECT(pos, mtl), normal(norm)
{
}


PLANE::~PLANE (void)
{
}


bool PLANE::Intersect (const RAY & ray, INTERSECTION & intersection) const
{
   double scalProd = normal.Dot(ray.dir);

   if (scalProd > 0.0) {
      VEC p = GetPosition() - ray.start;

      double t = p.Dot(normal) / scalProd;

      if (t >= 0) {
         intersection.intersectPoints.push_back(ray.start + ray.dir * t);
         intersection.obj = this;
         return true;
      }
   }

   return false;
}


VEC PLANE::GetNormal (VEC point) const
{
   return normal;
}
