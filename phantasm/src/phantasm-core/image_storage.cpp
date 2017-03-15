#include <fstream>

#include "image_storage.h"

IMAGE_STORAGE::IMAGE_STORAGE (void) : w(0), h(0), data(NULL)
{

}

IMAGE_STORAGE::~IMAGE_STORAGE (void)
{

}

void IMAGE_STORAGE::SaveToJpeg (std::string fileName)
{
   std::ofstream out(fileName);



   out.close();
}
