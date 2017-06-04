#include "image_storage.h"

IMAGE_STORAGE::IMAGE_STORAGE (void) : w(0), h(0), data(NULL)
{

}

IMAGE_STORAGE::~IMAGE_STORAGE (void)
{
   if (data != NULL) {
      delete[](data);
   }
}

void IMAGE_STORAGE::Allocate (int newW, int newH)
{
   if (data != NULL) {
      delete[](data);
   }
   w = newW;
   h = newH;

   data = new BYTE[newW * newH * 3]();
}
