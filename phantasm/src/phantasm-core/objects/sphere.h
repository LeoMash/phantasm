#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "phm_core.h"

#include "object.h"

class PHM_CORE_API SPHERE : public OBJECT {
public:
   SPHERE (void);
   SPHERE (double rad, VEC pos, RGB color);
   ~SPHERE (void);

   bool Intersect (const RAY & ray, INTERSECTION & intersection) const override;
private:
   double radius;
};

#endif // _SPHERE_H_
