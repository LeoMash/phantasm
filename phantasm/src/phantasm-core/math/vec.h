#pragma once
#ifndef _VEC_H_
#define _VEC_H_

#include "phm_core.h"

class PHM_CORE_API VEC {
public:
   VEC  (void);
   VEC  (double x, double y, double z);
   VEC  (const VEC & r);
   ~VEC (void);

   VEC &     operator=   (const VEC & r);
   double &  operator[]  (int index);
   double    operator[]  (int index) const;
   VEC       operator*   (double d) const;
   VEC       operator/   (double d) const;
   VEC &     operator*=  (double d);
   VEC       operator+   (const VEC & r) const;
   VEC &     operator+=  (const VEC & r);
   VEC       operator-   (const VEC & r) const;

   double Norm (void) const;
   VEC &  Normalize (void);

   double Dot   (const VEC & r) const;
   VEC    Cross (const VEC & r) const;
private:
   double data[3];
};

PHM_CORE_API extern const VEC VEC_UNIT_X;
PHM_CORE_API extern const VEC VEC_UNIT_Y;
PHM_CORE_API extern const VEC VEC_UNIT_Z;
PHM_CORE_API extern const VEC VEC_IDENTITY;
PHM_CORE_API extern const VEC VEC_NULL;


#endif // _VEC_H_
