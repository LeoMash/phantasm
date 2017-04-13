#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <string>

struct INPUT_PARAMS {
   std::string sceneFile;
   std::string outputImage;
};

void PrintHelp (void);
bool ParseConsole (int argc, char * argv[], INPUT_PARAMS & params);

#endif // _CONSOLE_H_
