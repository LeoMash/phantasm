#pragma once
#ifndef _RAY_H_
#define _RAY_H_

#include "math\vec.h"

struct RAY {
   RAY (VEC startingPoint, VEC direction);
   RAY (void) {}
   ~RAY (void) {}

   VEC start;
   VEC dir;
};

#endif // _RAY_H_
