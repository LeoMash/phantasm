#pragma once
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "..\phm_core.h"
#include "..\common.h"

class PHM_CORE_API IMAGE_STORAGE {
public:
   IMAGE_STORAGE (void);
   ~IMAGE_STORAGE (void);
private:
   int w;
   int h;
   BYTE * data;
};

#endif // _IMAGE_H_

