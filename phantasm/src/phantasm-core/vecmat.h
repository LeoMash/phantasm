#pragma once
#ifndef _VECMAT_H_
#define _VECMAT_H_

#include "phm_core.h"

class VEC;

class PHM_CORE_API MAT {
public:
   void allocmat (void);
   void freemat (void);
   MAT (void);
   MAT (double el, int size);
   MAT (const MAT & r);
   ~MAT (void);

   MAT & operator= (const MAT & r);

   MAT & operator+= (const MAT & r);
   MAT operator+ (const MAT & r) const;

   MAT & operator-= (const MAT & r);
   MAT operator- (const MAT & r) const;

   MAT & operator*= (const MAT & r);
   MAT operator* (const MAT & r) const;

   MAT & operator*= (const double & r);
   MAT operator* (const double & r) const;

   VEC operator* (const VEC & r) const;

   MAT operator- (void);

   double getEl (int row, int column) const;
   void setEl (int row, int column, double el);
   int getN (void) const;
   double norm (void) const;
   MAT transpose (void) const;
   VEC getColumn (int column) const;
private:
   int n;
   double ** data;
};

class PHM_CORE_API VEC {
public:
   VEC (void);
   VEC (double el, int size);
   VEC (const double * dat, int size);
   VEC (const VEC & r);
   ~VEC (void);

   VEC & operator= (const VEC & r);
   double & operator[] (int index);
   double operator[] (int index) const;
   VEC operator* (double d);
   VEC operator/ (double d) const;

   VEC & operator*= (double d);
   VEC operator+ (const VEC & r) const;
   VEC operator+= (const VEC & r);
   VEC operator- (const VEC & r);
   double scalProd (const VEC & r) const;
   double norm (void);
private:
   int n;
   double * data;
};

#endif // _VECMAT_H_
