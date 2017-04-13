#include "common.h"

#include "console\console.h"
#include "phm_core_export.h"

int main (int argc, char * argv[])
{
   INPUT_PARAMS params;

   if (!ParseConsole(argc, argv, params)) {
      return 0;
   }
   
   SCENE scn;

   LoadSceneFromJSON(scn, params.sceneFile);
   
   TRACER tr;
   IMAGE_STORAGE img;

   img.Allocate(500, 500);

   tr.TraceScene(scn, img);

   SaveImageToJpeg(img, params.outputImage);

   return 0;
}
