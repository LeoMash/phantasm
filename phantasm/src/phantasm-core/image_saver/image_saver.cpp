#include <fstream>

#include <jpge.h>
#include <lodepng.h>

#include "logger/logger.h"

#include "image_saver.h"

void SaveImageToJpeg (const IMAGE_STORAGE & img, std::string fileName)
{
   jpge::compress_image_to_jpeg_file(fileName.c_str(), img.w, img.h, 3, img.data);
}


PHM_CORE_API void SaveImageToPng (const IMAGE_STORAGE & img, std::string fileName)
{
   
   lodepng::State state;
   // input color type
   state.info_raw.colortype = LCT_RGB;
   state.info_raw.bitdepth = 8;
   // output color type
   state.info_png.color.colortype = LCT_RGBA;
   state.info_png.color.bitdepth = 8;
   state.encoder.auto_convert = 0; 


   std::vector<unsigned char> buffer;
   unsigned error = lodepng::encode(buffer, img.data, img.w, img.h, state);

   if (error) {
      LogError("PNG encoder error :" + std::to_string(error) + ": " + lodepng_error_text(error));
   } else {
      lodepng::save_file(buffer, fileName);
   }

   
}
