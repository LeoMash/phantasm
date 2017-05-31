#include "common.h"

#include "ray.h"
#include "tracer.h"
#include "tracer_accompanying.h"


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
         RAY ray = scn.GetRay(static_cast<double>(i) / static_cast<double>(img.w), 
                              static_cast<double>(j) / static_cast<double>(img.h));

         RGB * pixelColor = reinterpret_cast<RGB *>(img.data + 3 * (j * img.w + i));
         (*pixelColor) = Trace(ray, scn, 0);
      }
   }
}
