#include "common.h"

#include "vecmat.h"

VEC::VEC (double el, int size)
{
   n = size;
   data = static_cast<double *>(malloc(sizeof(double) * size));
   for (int i = 0; i < size; i++) {
      data[i] = el;
   }
}

VEC::VEC (void)
{
   n = 3;
   data = static_cast<double *>(malloc(sizeof(double) * 3));
   for (int i = 0; i < 3; i++) {
      data[i] = 0;
   }
}


VEC::VEC (const double * dat, int size)
{
   n = size;
   data = static_cast<double *>(malloc(sizeof(double) * size));
   for (int i = 0; i < size; i++) {
      data[i] = dat[i];
   }
}

VEC::VEC (const VEC & r)
{
   n = r.n;
   data = static_cast<double *>(malloc(sizeof(double) * n));
   for (int i = 0; i < n; ++i) {
      data[i] = r.data[i];
   }
}

VEC::~VEC (void)
{
   free(data);
}

VEC & VEC::operator= (const VEC & r)
{
   free(data);
   n = r.n;
   data = static_cast<double *>(malloc(sizeof(double) * n));
   for (int i = 0; i < n; ++i) {
      data[i] = r.data[i];
   }

   return *this;
}

double & VEC::operator[] (int index)
{
   return data[index];
}

double VEC::operator[] (int index) const
{
   return data[index];
}

VEC VEC::operator* (double d)
{
   VEC res = *this;

   for (int i = 0; i < n; ++i) {
      res.data[i] *= d;
   }

   return res;
}

VEC & VEC::operator*= (double d)
{

   for (int i = 0; i < n; ++i) {
      data[i] *= d;
   }

   return *this;
}

VEC VEC::operator+ (const VEC & r) const
{

   VEC res(*this);

   for (int i = 0; i < n; ++i) {
      res[i] += r[i];
   }

   return res;
}

VEC VEC::operator+= (const VEC & r)
{
   for (int i = 0; i < n; ++i) {
      data[i] += r.data[i];
   }

   return (*this);
}

double VEC::scalProd (const VEC & r) const
{
   double res = 0.0;

   for (int i = 0; i < n; ++i) {
      res += r[i] * data[i];
   }

   return res;
}

VEC VEC::operator- (const VEC & r)
{
   VEC res(*this);

   for (int i = 0; i < n; ++i) {
      res[i] -= r[i];
   }

   return res;
}

double VEC::norm (void)
{
   double res = 0.0;

   for (int i = 0; i < n; ++i) {
      res += fabs(data[i]);
   }

   return res;
}

VEC VEC::operator/ (double d) const
{
   VEC res(*this);

   for (int i = 0; i < n; ++i) {
      res[i] /= d;
   }

   return res;
}
