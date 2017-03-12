#pragma once
#ifndef _VECMAT_H_
#define _VECMAT_H_

#include "phm_core.h"

class PHM_CORE_API VEC {
public:
   VEC  (void);
   VEC  (double el);
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

class PHM_CORE_API MATR {
public:
   MATR  (void);
   MATR  (double el);
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

#endif // _VECMAT_H_
