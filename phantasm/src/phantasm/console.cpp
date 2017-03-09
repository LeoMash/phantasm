#include "common.h"

#include "console.h"

void PrintHelp (void)
{
   puts("Phantasm is console raytracer");
   puts("Usage: ");
   puts("   --input-file -i for input file with scene");
   puts("   --output-file -o for output file");
}

bool ParseConsole (int argc, char * argv[], cnsINPUT & params)
{
   if (argc < 5) {
      PrintHelp();
      return false;
   }    

   argv++;
   argc--;

   for (int i = 0; i < argc; i += 2) {
      /*
      if (!strncmp(argv[i + 1], "-i", 2)) {  // compare
         params.inFile = std::string(argv[i + 2]);
      } else if (!strncmp(argv[i + 1], "-o", 2)) {
         params.outFile = std::string(argv[i + 2]);
      } else if (!strncmp(argv[i + 1], "-output", 7)) {
         params.outFile = std::string(argv[i + 2]);
      } else if (!strncmp(argv[i + 1], "-input", 6)) {
         params.outFile = std::string(argv[i + 2]);
      }
      */
   }

   if (params.outFile.length() && params.inFile.length()) {
      return true;
   }

   puts("Something goes wrong");
   puts("Try to follow this instructions:");
   PrintHelp();
   return false;
}
