#include "common.h"

#include <algorithm>

#include "ray.h"
#include "tracer.h"

#define INF 1e8

#define BIAS 1e-4


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
   double minDist = INF;

   for (const INTERSECTION & i : intersects) {
      
      double dist = (i.intersectPoints[0] - ray.start).Norm();
      if (dist > 0 && dist < minDist) {
         minDist = dist;
         res = i;
      }

   }

   if (minDist == INF) {
      res.obj = NULL;
   }
}



double Clamp (double x)
{
   if (x < 0.0) {
      return 0.0;
   }
   return x;
}


RGB TRACER::Trace (const RAY & ray, const SCENE & scn, int depth)
{
   std::vector<INTERSECTION> prms;

   FindObjectsIntersections(ray, scn, prms);

   INTERSECTION inter;

   FindMinIntersection(inter, ray, prms);

   if (inter.obj == NULL) {
      return scn.GetBackgroundColor();
   }

   return Shade(inter, ray, scn, depth);
}


RGB TRACER::Shade (const INTERSECTION & hitPoints, const RAY & ray, const SCENE & scn, int depth)
{
   RGB color(0, 0, 0);

   MTL mtl = hitPoints.obj->GetMaterial();


   VEC normalInHit = hitPoints.obj->GetNormal(hitPoints.intersectPoints[0]);


   if (mtl.refl && depth < scn.GetMaxDepth()) {
      return Trace(RAY(hitPoints.intersectPoints[0] + normalInHit * BIAS, -ray.dir.Reflect(normalInHit)), scn, depth + 1);
   }



   LIGHT * light = (*scn.BeginLights());

   VEC lightPos = light->GetPosition();
   VEC lightDir = (hitPoints.intersectPoints[0] - lightPos).Normalize();

   RGB ambColor = mtl.color;
   RGB diffColor;
   RGB specColor;


   RAY lightRay(hitPoints.intersectPoints[0] + normalInHit * BIAS, -lightDir);

   std::vector<INTERSECTION> lightIntersections;

   FindObjectsIntersections(lightRay, scn, lightIntersections);

   INTERSECTION lightInt;

   FindMinIntersection(lightInt, lightRay, lightIntersections);

   if (lightInt.obj == NULL) {

      double diff = Clamp(normalInHit.Dot(-lightDir));

      diffColor = mtl.color * diff;


      VEC r = lightDir.Reflect(normalInHit);
      double spec = Clamp(r.Dot(ray.dir));

      specColor = light->GetColor() * pow(spec, mtl.phong);
   }

   color = ambColor * mtl.Ka + diffColor * mtl.Kd + specColor * mtl.Ks;


   return color;
}

void TRACER::TraceScene (const SCENE & scn, IMAGE_STORAGE & img)
{
   for (int j = 0; j < img.h; j++) {
      for (int i = 0; i < img.w; i++) {
         RAY ray = scn.GetRay(static_cast<double>(i) / static_cast<double>(img.w), 
                              static_cast<double>(j) / static_cast<double>(img.h));

         RGB * pixelColor = reinterpret_cast<RGB *>(img.data + 3 * (j * img.w + i));
         (*pixelColor) = Trace(ray, scn, 0);
      }
   }
}
