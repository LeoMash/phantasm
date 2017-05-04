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
   
   scn.SetCameraWH(1500, 1500);

   TRACER tr;
   IMAGE_STORAGE img;

   img.Allocate(1500, 1500);

   tr.TraceScene(scn, img);

   SaveImageToJpeg(img, params.outputImage);

   LogMessage(LOGGING_LEVELS::INFO, "The work is done!\n");

   return 0;
}
