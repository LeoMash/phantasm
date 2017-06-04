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
   
   int W = params.w;
   int H = params.h;

   scn.SetCameraWH(W, H);

   TRACER tr;
   IMAGE_STORAGE img;

   img.Allocate(W, H);

   tr.TraceScene(scn, img);

   switch (params.type) {

   case INPUT_PARAMS::IMG_TYPE::JPEG:
      SaveImageToJpeg(img, params.outputImage);
      break;

   default:
      SaveImageToPng(img, params.outputImage);
      break;

   }

   EndLogging();

   return 0;
}
