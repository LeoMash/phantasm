#pragma once
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "phm_core.h"
#include "common.h"

struct PHM_CORE_API IMAGE_STORAGE {
public:
   IMAGE_STORAGE (void);
   ~IMAGE_STORAGE (void);

   void Allocate(int newW, int newH);

   int w;
   int h;
   BYTE * data;
};

#endif // _IMAGE_H_

