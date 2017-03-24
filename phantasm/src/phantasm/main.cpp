#include "common.h"

#include "console\console.h"
#include "phm_core_export.h"

int main (int argc, char * argv[])
{
   CONSOLE_PARAMETERS params;

   if (!ParseConsole(argc, argv, params)) {
      return 0;
   }
   
   SCENE scn;

   LoadSceneFromJSON(scn, params.sceneFile);
   
   TRACER tr;
   IMAGE_STORAGE img;

   img.w = 500;
   img.h = 500;

   img.data = new BYTE[500 * 500 * 3]();

   tr.TraceScene(scn, img);

   SaveImageToJpeg(img, params.outputImage);

   delete[] (img.data);

   return 0;
}
