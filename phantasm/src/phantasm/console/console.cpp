#include "common.h"

#include "console.h"

void PrintHelp (void)
{
   puts("Phantasm is console raytracer");
   puts("Usage: ");
   puts("   --input-file -i for input file with scene");
   puts("   --output-file -o for output file");
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
      } 
   }

   if (params.outputImage.length() && params.sceneFile.length()) {
      return true;
   }

   puts("Something goes wrong");
   puts("Try to follow this instructions:");
   PrintHelp();
   return false;
}
