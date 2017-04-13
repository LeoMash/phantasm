#pragma once
#ifndef _IMAGE_SAVER_H_
#define _IMAGE_SAVER_H_

#include <string>

#include "phm_core.h"

#include "image_storage\image_storage.h"

PHM_CORE_API void SaveImageToJpeg (const IMAGE_STORAGE & img, std::string fileName);

#endif // _IMAGE_SAVER_H_
