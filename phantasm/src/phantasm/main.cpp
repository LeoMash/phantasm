#include "common.h"

#include "console.h"
#include "tracer.h"

int main (int argc, char * argv[])
{
   cnsINPUT params;

   if (!ParseConsole(argc, argv, params)) {
      return 0;
   }

   rtrTRACER tr;

   tr.LoadSceneFromJSON(params.inFile);

   return 0;
}
