#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "phm_core.h"

#include "object.h"

class PHM_CORE_API rtrSPHERE : public rtrOBJECT {
public:
   rtrSPHERE (void);
   rtrSPHERE (double rad, VEC pos);
   ~rtrSPHERE (void);
private:
   double radius;
};

#endif // _SPHERE_H_
