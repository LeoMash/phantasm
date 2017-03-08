#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "phm_core.h"

#include "object.h"

class PHM_CORE_API rtrSPHERE : public rtrOBJECT {
public:
   rtrSPHERE (void) : rtrOBJECT(), radius(5) {}
   rtrSPHERE (double rad, VEC pos) : rtrOBJECT(pos), radius(rad) {}
   ~rtrSPHERE (void) {}
private:
   double radius;
};

#endif // _SPHERE_H_
