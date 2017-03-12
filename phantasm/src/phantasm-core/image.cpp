#include <fstream>

#include "image.h"

IMG::IMG (void) : w(0), h(0), data(NULL)
{

}

IMG::~IMG (void)
{

}

void IMG::SaveToJpeg (std::string fileName)
{
   std::ofstream out(fileName);



   out.close();
}
