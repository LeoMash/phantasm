#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <string>

struct CONSOLE_PARAMETERS {
   std::string sceneFile;
   std::string outputImage;
};

void PrintHelp (void);
bool ParseConsole (int argc, char * argv[], CONSOLE_PARAMETERS & params);

#endif // _CONSOLE_H_
