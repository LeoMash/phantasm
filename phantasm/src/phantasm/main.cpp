#include "common.h"

#include "console.h"
#include "phm_core_export.h"

int main (int argc, char * argv[])
{
   PARAM params;

   if (!ParseConsole(argc, argv, params)) {
      return 0;
   }
   
   SCENE scn;

   LoadSceneFromJSON(scn, params.inFile);
   
   TRACER tr;
   IMAGE_STORAGE data;
   tr.TraceScene(scn, data);

   //SaveImgToJpeg(data, params.outFile);

   //tr.LoadSceneFromJSON(params.inFile);

   return 0;
}
