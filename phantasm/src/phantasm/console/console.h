#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <string>

struct INPUT_PARAMS {
   std::string sceneFile;
   std::string outputImage;
   int w;
   int h;
   enum class IMG_TYPE {
      JPEG,
      PNG
   } type;
};

void PrintHelp (void);
bool ParseConsole (int argc, char * argv[], INPUT_PARAMS & params);

#endif // _CONSOLE_H_
