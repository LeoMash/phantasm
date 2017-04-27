#pragma once
#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "math\vec.h"
#include "material\material.h"

class LIGHT {
public:
   LIGHT (void);
   virtual ~LIGHT (void);
};

class POINT_LIGHT : public LIGHT {
public:
   POINT_LIGHT (void);
   ~POINT_LIGHT (void);

   POINT_LIGHT (VEC position, RGB col);

private:
   VEC pos;
   RGB color;
};

#endif // _LIGHT_H_
