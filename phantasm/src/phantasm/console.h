#pragma once
#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <string>

struct PARAM {
   std::string inFile;
   std::string outFile;

};

void PrintHelp (void);
bool ParseConsole (int argc, char * argv[], PARAM & params);

#endif // _CONSOLE_H_
