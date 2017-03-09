#include "common.h"

#include "console.h"
#include "tracer.h"

int main (int argc, char * argv[])
{
   cnsINPUT params;

   if (!ParseConsole(argc, argv, params)) {
      return 0;
   }
   /*
   SCENE scn;

   LoadSceneFromJSON(&scn, params.inFile);
   
   rtrTRACER tr;
   IMG data;
   tr.TraceScene(scn, NULL);

   SaveImgToJpeg(data, params.outFile);
   */
   //tr.LoadSceneFromJSON(params.inFile);

   return 0;
}
