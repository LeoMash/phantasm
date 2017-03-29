#pragma once
#ifndef _RAY_H_
#define _RAY_H_

#include "..\math\vecmat.h"

struct RAY {
   RAY (VEC startingPoint, VEC direction) : startingPnt(startingPoint), dir(direction) {}
   RAY (void) {}
   ~RAY (void) {}

   VEC startingPnt;
   VEC dir;
};

#endif // _RAY_H_
