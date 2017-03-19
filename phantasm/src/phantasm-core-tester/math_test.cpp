#include <gtest\gtest.h>

#include <conio.h>

#include "phm_core_export.h"

TEST (vec, default_constructor)
{
   VEC v;
   EXPECT_EQ(0, v[0]);
   EXPECT_EQ(0, v[1]);
   EXPECT_EQ(0, v[2]);
}

TEST (vec, copy_constructor)
{
   VEC v(1, 2, 3);
   VEC vv(v);

   EXPECT_EQ(1, vv[0]);
   EXPECT_EQ(2, vv[1]);
   EXPECT_EQ(3, vv[2]);
}


TEST (vec, assignment)
{
   VEC v(1, 2, 3);
   VEC vv;

   vv = v;

   EXPECT_EQ(1, vv[0]);
   EXPECT_EQ(2, vv[1]);
   EXPECT_EQ(3, vv[2]);
}

TEST (vec, mul_double)
{
   VEC v(1, 2, 3);

   VEC vv = v * 5;

   EXPECT_EQ(5, vv[0]);
   EXPECT_EQ(10, vv[1]);
   EXPECT_EQ(15, vv[2]);
}

TEST (vec, div_double)
{
   VEC v(1, 2, 3);

   VEC vv = v / 4.0;

   EXPECT_EQ(0.25, vv[0]);
   EXPECT_EQ(0.50, vv[1]);
   EXPECT_EQ(0.75, vv[2]);
}

TEST (vec, assign_opers)
{
   VEC v(1, 2, 3);

   v *= 5;

   EXPECT_EQ(5,  v[0]);
   EXPECT_EQ(10, v[1]);
   EXPECT_EQ(15, v[2]);

   v += VEC(4, 5, 6);

   EXPECT_EQ(9, v[0]);
   EXPECT_EQ(15, v[1]);
   EXPECT_EQ(21, v[2]);
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

   EXPECT_EQ(0,   v[0]);
   EXPECT_EQ(0.8, v[1]);
   EXPECT_EQ(0.6,  v[2]);
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

   EXPECT_EQ(-3, res[0]);
   EXPECT_EQ(6,  res[1]);
   EXPECT_EQ(-3, res[2]);
}

TEST (matr, vec_mul_matr)
{
   MATR A(5);
   VEC b(1, 2, 3);

   VEC c = A * b;

   EXPECT_EQ(5,  c[0]);
   EXPECT_EQ(10, c[1]);
   EXPECT_EQ(15, c[2]);
}

int main (int argc, char **argv) 
{
   testing::InitGoogleTest(&argc, argv);

   int testsResult = RUN_ALL_TESTS();

   _getch();

   return testsResult;
}
