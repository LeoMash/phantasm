#include "common.h"

#include "console.h"

void PrintHelp (void)
{
   puts("Phantasm is console raytracer");
   puts("Usage: ");
   puts("   -i for input file with scene");
   puts("   -u for output file");
}

bool ParseConsole (int argc, char * argv[], cnsINPUT & params)
{
   if (argc < 5) {
      PrintHelp();
      return false;
   }

   if (!strncmp(argv[1], "-i", 2)) {
      params.inFile = std::string(argv[2]);
   } else if (!strncmp(argv[1], "-o", 2)) {
      params.outFile = std::string(argv[2]);
   }

   if (!strncmp(argv[3], "-i", 2)) {
      params.inFile = std::string(argv[4]);
   } else if (!strncmp(argv[3], "-o", 2)) {
      params.outFile = std::string(argv[4]);
   }

   if (params.outFile.length() && params.inFile.length()) {
      return true;
   }

   puts("Something goes wrong");
   puts("Try to follow this instructions:");
   PrintHelp();
   return false;
}
