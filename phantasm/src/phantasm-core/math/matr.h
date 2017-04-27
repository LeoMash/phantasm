#pragma once
#ifndef _VECMAT_H_
#define _VECMAT_H_

#include "phm_core.h"

#include "vec.h"

class PHM_CORE_API MATR {
public:
            MATR  (void);
   explicit MATR  (double diagEl);
            MATR  (const MATR & r);
            ~MATR (void);

   MATR & operator=  (const MATR & r);

   MATR & operator+= (const MATR & r);
   MATR   operator+  (const MATR & r) const;

   MATR & operator-= (const MATR & r);
   MATR   operator-  (const MATR & r) const;

   MATR & operator*= (const MATR & r);
   MATR   operator*  (const MATR & r) const;

   MATR & operator*= (const double & r);
   MATR   operator*  (const double & r) const;
          
   VEC    operator*  (const VEC & r) const;
          
   MATR   operator-  (void);

   double GetEl (int row, int column) const;
   void SetEl (int row, int column, double el);
   MATR Transpose (void) const;
private:
   double data[4][4];
};

PHM_CORE_API extern const MATR MATR_IDENTITY;

#endif // _VECMAT_H_
