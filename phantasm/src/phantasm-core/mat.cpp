#include "common.h"

#include "vecmat.h"

MATR::MATR (double el)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] = 0;
      }
      data[i][i] = el;
   }
}

MATR::MATR (void)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         if (i == j) {
            data[i][j] = 1;
         } else {
            data[i][j] = 0;
         }
      }
   }
}

MATR::MATR (const MATR & r)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] = r.data[i][j];
      }
   }
}

MATR::~MATR (void)
{

}

MATR & MATR::operator= (const MATR & r)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] = r.data[i][j];
      }
   }

   return *this;
}

MATR & MATR::operator+= (const MATR & r)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] += r.data[i][j];
      }
   }

   return *this;
}

MATR MATR::operator+ (const MATR & r) const
{
   MATR res(*this);

   res += r;

   return res;
}

MATR & MATR::operator-= (const MATR & r)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] -= r.data[i][j];
      }
   }

   return *this;
}

MATR MATR::operator- (const MATR & r) const
{
   MATR res(*this);

   res -= r;

   return res;
}

MATR & MATR::operator*= (const MATR & r)
{
   MATR temp(*this);

   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] = 0;
         for (int k = 0; k < 4; ++k) {
            data[i][j] += temp.data[i][k] * r.data[k][j];
         }
      }
   }

   return (*this);
}

MATR MATR::operator* (const MATR & r) const
{
   MATR res(*this);

   res *= r;

   return res;
}

MATR & MATR::operator*= (const double & r)
{
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         data[i][j] *= r;
      }
   }

   return (*this);
}

MATR MATR::operator* (const double & r) const
{
   MATR res(*this);

   res *= r;

   return res;
}

VEC MATR::operator* (const VEC & r) const
{
   VEC res(0);

   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         res[i] += data[i][j] * r[j];
      }
   }

   return res;
}

double MATR::GetEl (int row, int column) const
{
   return data[row][column];
}

void MATR::SetEl (int row, int column, double el)
{
   data[row][column] = el;
}

MATR MATR::operator- (void)
{
   MATR res(*this);

   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         res.data[i][j] = -res.data[i][j];
      }
   }

   return res;
}

MATR MATR::Transpose (void) const
{
   MATR res(0);

   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         res.data[i][j] = data[j][i];
      }
   }

   return res;
}

