#include "..\common.h"

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
   for (int i = 0; i < img.w; i++) {
      for (int j = 0; j < img.h; j++) {
         RGB * pixelColor = reinterpret_cast<RGB *>(img.data + 3 * (j * img.w + i));
         pixelColor->R = 0;
         pixelColor->G = 0;
         pixelColor->B = 0;

         RAY ray(VEC(static_cast<double>(i) - img.w / 2.0, static_cast<double>(j) - img.h / 2.0, 1000.0), 
            VEC(0.0, 0.0, -1.0));

         std::vector<INTERSECT_PARAMS> prms;

         scn.IntersectAll(ray, prms);
         double minDist = 1000000.0;
         std::for_each(prms.begin(), prms.end(),
            [&minDist, pixelColor](INTERSECT_PARAMS prm) { 
              if (prm.isIntersect && prm.nearDistance < minDist) {
                minDist = prm.nearDistance;
                (*pixelColor) = prm.color;
              } 
            });

      }
   }
}
