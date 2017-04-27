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
   
   scn.SetCamera(VEC(10, 10, 10), VEC(0, 0, 0), VEC(0, 1, 0), 3.14 * 2.0 / 3.0, 500, 500);

   TRACER tr;
   IMAGE_STORAGE img;

   img.Allocate(500, 500);

   tr.TraceScene(scn, img);

   SaveImageToJpeg(img, params.outputImage);

   LogMessage(std::string("The work is done!"));

   return 0;
}
