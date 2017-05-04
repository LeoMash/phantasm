#pragma once
#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "math\vec.h"
#include "material\material.h"

class LIGHT {
public:
   LIGHT (void);
   virtual ~LIGHT (void) = 0;

   virtual VEC GetPosition (void) const = 0;
};

class POINT_LIGHT : public LIGHT {
public:
   POINT_LIGHT (void);
   ~POINT_LIGHT (void);

   POINT_LIGHT (VEC position, RGB col);

   VEC GetPosition (void) const override;

private:
   VEC pos;
   RGB color;
};

#endif // _LIGHT_H_
