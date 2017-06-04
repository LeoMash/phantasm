#include <math.h>

#include "tracer_accompanying.h"


#define INF 1e8
#define BIAS 1e-5


static void FindObjectsIntersections (const RAY & ray, const SCENE &scn, std::vector<INTERSECTION> & intersects)
{
   for (auto obj = scn.BeginObjects(); obj != scn.EndObjects(); ++obj) {
      INTERSECTION intersect;

      if ((*obj)->Intersect(ray, intersect)) {
         intersects.push_back(intersect);
      }
   }
}


static void FindMinIntersection (INTERSECTION & res, const RAY & ray, const std::vector<INTERSECTION> & intersects)
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

static double Clamp (double x)
{
   if (x < 0.0) {
      return 0.0;
   }
   return x;
}


static RGB ComputeShadows (const SCENE & scn, const VEC & hitPoint, const VEC & normalInHit, const MTL & mtl, const RAY & ray)
{
   RGB color(0, 0, 0);

   for (auto lightIter = scn.BeginLights(); lightIter != scn.EndLights(); ++lightIter)
   {
      LIGHT * light = (*lightIter);

      VEC lightPos = light->GetPosition();
      VEC lightDir = (hitPoint - lightPos).Normalize();

      RGB ambColor = mtl.color;
      RGB diffColor;
      RGB specColor;


      RAY lightRay(hitPoint + normalInHit * BIAS, -lightDir);

      std::vector<INTERSECTION> lightIntersections;

      FindObjectsIntersections(lightRay, scn, lightIntersections);

      INTERSECTION lightInt;

      FindMinIntersection(lightInt, lightRay, lightIntersections);

      if (lightInt.obj == NULL ||
         (hitPoint - lightInt.intersectPoints[0]).Norm() >
         (hitPoint - light->GetPosition()).Norm()) {

         double diff = Clamp(normalInHit.Dot(-lightDir));

         diffColor = mtl.color * diff;

         VEC r = lightDir.Reflect(normalInHit);
         double spec = Clamp(r.Dot(ray.dir));

         specColor = light->GetColor() * pow(spec, mtl.phong);
      }

      color += ambColor * mtl.Ka + diffColor * mtl.Kd + specColor * mtl.Ks;
   }

   return color;
}



static RGB Shade (const INTERSECTION & hitPoints, const RAY & ray, const SCENE & scn, int depth)
{
   RGB color(0, 0, 0);
   MTL mtl = hitPoints.obj->GetMaterial();
   VEC hitPoint = hitPoints.intersectPoints[0];
   VEC normalInHit = hitPoints.obj->GetNormal(hitPoint);


   bool isInside = false;
   if ((ray.dir).Dot(normalInHit) > 0.0) {
      normalInHit = -normalInHit;
      isInside = true;
   }


   if (mtl.refl && depth < scn.GetMaxDepth()) {
      color += Trace(RAY(hitPoint + normalInHit * BIAS, -ray.dir.Reflect(normalInHit)), scn, depth + 1) * mtl.Kr;
   }

   if (mtl.Kt > EPS && depth < scn.GetMaxDepth()) {
      double Eta = mtl.refr;
      if (!isInside) {
         Eta = 1.0 / Eta;
      }

      double cosI = -(ray.dir).Dot(normalInHit);
      double sinT2 = Eta * Eta * (1.0 - cosI * cosI);

      if (sinT2 <= 1.0) {
         RAY refractRay;
         refractRay.dir = ray.dir * Eta + normalInHit * (Eta * cosI - sqrt(1.0 - sinT2));

         refractRay.start = hitPoint - normalInHit * BIAS;

         color += Trace(refractRay, scn, depth + 1) * mtl.Kt;
      }
   }

   color += ComputeShadows(scn, hitPoint, normalInHit, mtl, ray);

   return color;
}


RGB Trace (const RAY & ray, const SCENE & scn, int depth)
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

