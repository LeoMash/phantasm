#include "common.h"

#include <algorithm>

#include "ray.h"
#include "tracer.h"

TRACER::TRACER (void)
{

}


TRACER::~TRACER (void)
{

}



void FindObjectsIntersections (const RAY & ray, const SCENE &scn, std::vector<INTERSECTION> & intersects)
{
   for (auto obj = scn.BeginObjects(); obj != scn.EndObjects(); ++obj) {
      INTERSECTION intersect;

      if ((*obj)->Intersect(ray, intersect)) {
         intersects.push_back(intersect);
      }
   }
}

void FindMinIntersection (INTERSECTION & res, const RAY & ray, const std::vector<INTERSECTION> & intersects)
{
   double minDist = 1000000.0;

   for (const INTERSECTION & i : intersects) {
      
      if ((i.intersectPoints[0] - ray.start).Norm() < minDist) {
         minDist = (i.intersectPoints[0] - ray.start).Norm();
         res = i;
      }

   }

   if (minDist == 1000000.0) {
      res.obj = NULL;
   }
}

void TRACER::TraceScene (const SCENE & scn, IMAGE_STORAGE & img)
{
   for (int j = 0; j < img.h; j++) {
      for (int i = 0; i < img.w; i++) {
         RAY ray = scn.GetRay(static_cast<double>(j) / static_cast<double>(img.w), 
                              static_cast<double>(i) / static_cast<double>(img.h));

         std::vector<INTERSECTION> prms;

         FindObjectsIntersections(ray, scn, prms);

         RGB color(0, 0, 0);

         INTERSECTION inter;
         
         FindMinIntersection(inter, ray, prms);

         if (inter.obj != NULL) {
            color = (inter.obj->GetColor() * 0.125);


            for (auto lights = scn.BeginLights(); lights != scn.EndLights(); ++lights) {

               RAY lightRay((*lights)->GetPosition(), inter.intersectPoints[0] - (*lights)->GetPosition());

               std::vector<INTERSECTION> lightIntersections;

               FindObjectsIntersections(lightRay, scn, lightIntersections);

               INTERSECTION lightInt;

               FindMinIntersection(lightInt, lightRay, lightIntersections);

               if (lightInt.obj == inter.obj) {
                  color += inter.obj->GetColor() * 0.125;
               }
            }
         }

         RGB * pixelColor = reinterpret_cast<RGB *>(img.data + 3 * (j * img.w + i));
         (*pixelColor) = color;
      }
   }
}
