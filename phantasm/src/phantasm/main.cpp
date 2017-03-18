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
   tr.TraceScene(scn, img);

   SaveImageToJpeg(img, params.outputImage);

   //tr.LoadSceneFromJSON(params.inFile);

   return 0;
}
