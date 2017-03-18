#include <fstream>

#include "image_saver.h"

void SaveImageToJpeg (const IMAGE_STORAGE & img, std::string fileName)
{
   std::ofstream out(fileName);



   out.close();
}
