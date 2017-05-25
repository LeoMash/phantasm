#include "common.h"

#include "console.h"

void PrintHelp (void)
{
   puts("Phantasm is console raytracer");
   puts("Usage: ");
   puts("   -input-file   -i  for input file with scene");
   puts("   -output-file  -o  for output file");
   puts("   -width        -w  for image width");
   puts("   -height       -h  for image height");
}

bool ParseConsole (int argc, char * argv[], INPUT_PARAMS & params)
{
   if (argc < 5) {
      PrintHelp();
      return false;
   }    

   argv++;
   argc--;

   for (int i = 0; i < argc; i += 2) {
      if (!strcmp(argv[i], "-i") || !strcmp(argv[i], "-input")) {
         params.sceneFile = std::string(argv[i + 1]);

      } else if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "-output")) {
         params.outputImage = std::string(argv[i + 1]);

      } else if (!strcmp(argv[i], "-w") || !strcmp(argv[i], "-width")) {
         params.w = atoi(argv[i + 1]);

      } else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "-height")) {
         params.h = atoi(argv[i + 1]);
      }
   }


   if (params.w > 3000 || params.w < 0) {
      params.w = 500;
   }
   if (params.h > 3000 || params.h < 0) {
      params.h = 500;
   }



   if (params.outputImage.length() && params.sceneFile.length()) {
      return true;
   }

   puts("Something goes wrong");
   puts("Try to follow this instructions:");
   PrintHelp();
   return false;
}
