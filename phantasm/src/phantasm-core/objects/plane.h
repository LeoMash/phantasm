#pragma once
#ifndef _PLANE_H_
#define _PLANE_H_

#include "phm_core.h"

#include "object.h"

class PHM_CORE_API PLANE : public OBJECT {
public:
   PLANE (void);
   PLANE (const VEC & norm, const VEC & pos, const MTL & mtl);
   ~PLANE (void);

   bool Intersect (const RAY & ray, INTERSECTION & intersection) const override;

   VEC GetNormal (VEC point) const override;

private:

   VEC normal;
};

#endif // _PLANE_H_
