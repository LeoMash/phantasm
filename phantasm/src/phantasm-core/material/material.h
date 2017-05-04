#pragma once
#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "phm_core.h"

#include "common.h"

struct PHM_CORE_API RGB {
   RGB (void);
   RGB (const RGB & rgb);
   RGB (BYTE r, BYTE g, BYTE b);
   ~RGB (void);

   RGB & operator=  (const RGB & col);
   RGB   operator*  (double d) const;
   RGB   operator+  (const RGB d) const;
   RGB & operator+= (const RGB d);

   BYTE R;
   BYTE G;
   BYTE B;
};

#endif // _MATERIAL_H_
