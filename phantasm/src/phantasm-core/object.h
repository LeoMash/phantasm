#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "phm_core.h"

#include "vecmat.h"

class PHM_CORE_API rtrOBJECT {
public:
   rtrOBJECT (void) : position(VEC(0.0, 3)) {}
   rtrOBJECT (VEC pos) : position(pos) {}
   virtual ~rtrOBJECT (void) {}
private:
   VEC position;
};

#endif // _OBJECT_H_
