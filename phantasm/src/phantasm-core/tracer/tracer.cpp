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

void TRACER::TraceScene (const SCENE & scn, IMAGE_STORAGE & img)
{
   for (int j = 0; j < img.h; j++) {
      for (int i = 0; i < img.w; i++) {
         RAY ray = scn.GetRay(static_cast<double>(j) / static_cast<double>(img.w), 
                              static_cast<double>(i) / static_cast<double>(img.h));

         std::vector<INTERSECTION> prms;

         /*
         std::for_each(scn.Begin(), scn.End(),
            [&prms, &ray](const OBJECT * obj) {
               INTERSECTION intersect;
               if (obj->Intersect(ray, intersect)) {
                  prms.push_back(intersect);
               }
            });
         */

         for (auto obj = scn.Begin(); obj != scn.End(); ++obj) {
            INTERSECTION intersect;

            if ((*obj)->Intersect(ray, intersect)) {
               prms.push_back(intersect);
            }
         }

         RGB color(0, 0, 0);

         double minDist = 1000000.0;
         std::for_each(prms.begin(), prms.end(),
            [&minDist, &color](INTERSECTION prm) {
              if (prm.distance < minDist) {
                minDist = prm.distance;
                color = prm.obj->GetColor();
              } 
            });

         RGB * pixelColor = reinterpret_cast<RGB *>(img.data + 3 * (j * img.w + i));
         (*pixelColor) = color;
      }
   }
}
