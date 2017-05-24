#include "common.h"

#include "console\console.h"
#include "phm_core_export.h"

int main (int argc, char * argv[])
{
   StartLogging();

   INPUT_PARAMS params;

   if (!ParseConsole(argc, argv, params)) {
      return 0;
   }
   
   SCENE scn;

   LoadSceneFromJSON(scn, params.sceneFile);
   
   int W = 1500;
   int H = 500;

   scn.SetCameraWH(W, H);

   TRACER tr;
   IMAGE_STORAGE img;

   img.Allocate(W, H);

   tr.TraceScene(scn, img);

   SaveImageToJpeg(img, params.outputImage);

   LogMessage(LOGGING_LEVELS::INFO, "The work is done!\n");

   return 0;
}
