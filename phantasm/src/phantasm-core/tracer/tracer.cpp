#include "..\common.h"

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
         RGB * pnt = reinterpret_cast<RGB *>(img.data + 3 * (j * img.w + i));
         pnt->R = 255 / img.w * i;
         pnt->G = 255 / img.h * j;
         pnt->B = 0;
      }
   }
}
