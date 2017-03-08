#include "common.h"

#include "vecmat.h"

void MAT::allocmat (void)
{
   data = static_cast<double **>(malloc(sizeof(double *) * n));
   for (int i = 0; i < n; ++i) {
      data[i] = static_cast<double *>(malloc(sizeof(double) * n));
   }
   assert(data != NULL);
}

void MAT::freemat (void)
{
   if (data == NULL) {
      return;
   }
   for (int i = 0; i < n; ++i) {
      free(data[i]);
   }
   free(data);
}

MAT::MAT (double el, int size)
{
   n = size;
   allocmat();

   for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
         data[i][j] = 0;
      }
      data[i][i] = el;
   }
}

MAT::MAT (void)
{
   n = 3;
   allocmat();

   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         data[i][j] = 0;
      }
   }
}

MAT::MAT (const MAT & r)
{
   n = r.n;
   allocmat();
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         data[i][j] = r.data[i][j];
      }
   }
}

MAT::~MAT (void)
{
   freemat();
}

MAT & MAT::operator= (const MAT & r)
{
   freemat();
   n = r.n;
   allocmat();

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         data[i][j] = r.data[i][j];
      }
   }

   return *this;
}

MAT & MAT::operator+= (const MAT & r)
{
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         data[i][j] += r.data[i][j];
      }
   }

   return *this;
}

MAT MAT::operator+ (const MAT & r) const
{
   MAT res(*this);

   res += r;

   return res;
}

MAT & MAT::operator-= (const MAT & r)
{
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         data[i][j] -= r.data[i][j];
      }
   }

   return *this;
}

MAT MAT::operator- (const MAT & r) const
{
   MAT res(*this);

   res -= r;

   return res;
}

MAT & MAT::operator*= (const MAT & r)
{
   MAT temp(*this);

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         data[i][j] = 0;
         for (int k = 0; k < n; ++k) {
            data[i][j] += temp.data[i][k] * r.data[k][j];
         }
      }
   }

   return (*this);
}

MAT MAT::operator* (const MAT & r) const
{
   MAT res(*this);

   res *= r;

   return res;
}

MAT & MAT::operator*= (const double & r)
{
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         data[i][j] *= r;

      }
   }

   return (*this);
}

MAT MAT::operator* (const double & r) const
{
   MAT res(*this);

   res *= r;

   return res;
}

VEC MAT::operator* (const VEC & r) const
{
   VEC res(0.0, n);

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         res[i] += data[i][j] * r[j];
      }
   }

   return res;
}

double MAT::getEl (int row, int column) const
{
   return data[row][column];
}

void MAT::setEl (int row, int column, double el)
{
   data[row][column] = el;
}

int MAT::getN (void) const
{
   return n;
}

MAT MAT::operator- (void)
{
   MAT res(*this);

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         res.data[i][j] = -res.data[i][j];
      }
   }

   return res;
}

double MAT::norm (void) const
{
   double norm = -999.0, curn;

   for (int i = 0; i < n; i++) {
      curn = 0.0;
      for (int j = 0; j < n; j++) {
         curn += fabs(data[j][i]);
      }
      if (curn > norm) {
         norm = curn;
      }
   }

   return norm;
}

MAT MAT::transpose (void) const
{
   MAT res(0, n);

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         res.data[i][j] = data[j][i];
      }
   }

   return res;
}

VEC MAT::getColumn (int column) const
{
   VEC res (0.0, n);

   for (int i = 0; i < n; ++i) {
      res[i] = data[i][column];
   }

   return res;
}
