#include "..\common.h"

#include "vecmat.h"

VEC::VEC (double el)
{
   for (int i = 0; i < 3; i++) {
      data[i] = el;
   }
}

VEC::VEC (double x, double y, double z)
{
   data[0] = x;
   data[1] = y;
   data[2] = z;
}

VEC::VEC (void)
{
   for (int i = 0; i < 3; i++) {
      data[i] = 0;
   }
}

VEC::VEC (const VEC & r)
{
   for (int i = 0; i < 3; ++i) {
      data[i] = r.data[i];
   }
}

VEC::~VEC (void)
{
}

VEC & VEC::operator= (const VEC & r)
{
   for (int i = 0; i < 3; ++i) {
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

VEC VEC::operator* (double d) const
{
   VEC res = *this;

   for (int i = 0; i < 3; ++i) {
      res.data[i] *= d;
   }

   return res;
}

VEC & VEC::operator*= (double d)
{

   for (int i = 0; i < 3; ++i) {
      data[i] *= d;
   }

   return *this;
}

VEC VEC::operator+ (const VEC & r) const
{

   VEC res(*this);

   for (int i = 0; i < 3; ++i) {
      res[i] += r[i];
   }

   return res;
}

VEC & VEC::operator+= (const VEC & r)
{
   for (int i = 0; i < 3; ++i) {
      data[i] += r.data[i];
   }

   return *this;
}

VEC VEC::operator- (const VEC & r) const
{
   VEC res(*this);

   for (int i = 0; i < 3; ++i) {
      res[i] -= r[i];
   }

   return res;
}

double VEC::Norm (void) const
{
   double res = 0.0;

   for (int i = 0; i < 3; ++i) {
      res += data[i] * data[i];
   }

   res = sqrt(fabs(res));

   return res;
}

VEC & VEC::Normalize (void)
{
   double n = Norm();

   for (int i = 0; i < 3; ++i) {
      data[i] /= n;
   }

   return *this;
}

double VEC::Dot (const VEC & r) const
{
   double res = 0.0;

   for (int i = 0; i < 3; ++i) {
      res += r.data[i] * data[i];
   }

   return res;
}

VEC VEC::Cross (const VEC & r) const
{
   return VEC(data[1] * r.data[2] - data[2] * r.data[1], 
              data[2] * r.data[0] - data[0] * r.data[2],
              data[0] * r.data[1] - data[1] * r.data[0]);
}

VEC VEC::operator/ (double d) const
{
   VEC res(*this);

   for (int i = 0; i < 3; ++i) {
      res[i] /= d;
   }

   return res;
}
