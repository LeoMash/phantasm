#include <fstream>

#include "jpeg-compressor\jpge.h"

#include "image_saver.h"

void SaveImageToJpeg (const IMAGE_STORAGE & img, std::string fileName)
{
   jpge::compress_image_to_jpeg_file(fileName.c_str(), img.w, img.h, 3, img.data);
}
