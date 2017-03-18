#include <gtest\gtest.h>

#include <conio.h>

#include "phm_core_export.h"

TEST (vec, default_constructor)
{
   VEC v;
   ASSERT_EQ(0, v[1]);
}


TEST (vec, one_element_constructor)
{
   VEC v(30);
   ASSERT_EQ(30, v[1]);
}

TEST (vec, copy_constructor)
{
   VEC v(1, 2, 3);
   VEC vv(v);

   ASSERT_EQ(2, vv[1]);
}


TEST (vec, assignment)
{
   VEC v(1, 2, 3);
   VEC vv;

   vv = v;

   ASSERT_EQ(2, vv[1]);
}

TEST (vec, mul_double)
{
   VEC v(1, 2, 3);

   VEC vv = v * 5;

   ASSERT_EQ(10, vv[1]);
}

TEST (vec, div_double)
{
   VEC v(1, 2, 3);

   VEC vv = v / 4.0;

   ASSERT_EQ(0.5, vv[1]);
}

TEST (vec, assign_opers)
{
   VEC v(1, 2, 3);

   v *= 5;
   ASSERT_EQ(10, v[1]);
   v += VEC(4, 5, 6);
   ASSERT_EQ(15, v[1]);
}

TEST (vec, normal)
{
   VEC v(0, 4, 3);

   ASSERT_EQ(5, v.Norm());
}

TEST (vec, normalize)
{
   VEC v(0, 4, 3);
   v.Normalize();
   ASSERT_EQ(0.8, v[1]);
}

TEST (vec, dot)
{
   VEC a(1, 2, 3);
   VEC b(4, 5, 6);

   double res = a.Dot(b);

   ASSERT_EQ(32, res);
}  


TEST (vec, cross)
{
   VEC a(1, 2, 3);
   VEC b(4, 5, 6);

   VEC res = a.Cross(b);

   ASSERT_EQ(-3, res[0]);
   ASSERT_EQ(6, res[1]);
   ASSERT_EQ(-3, res[2]);
}

TEST (matr, vec_mul_matr)
{
   MATR A(5);
   VEC b(1, 2, 3);

   VEC c = A * b;

   ASSERT_EQ(5,  c[0]);
   ASSERT_EQ(10, c[1]);
   ASSERT_EQ(15, c[2]);
}

int main (int argc, char **argv) 
{
   testing::InitGoogleTest(&argc, argv);

   int testsResult = RUN_ALL_TESTS();

   _getch();

   return testsResult;
}
