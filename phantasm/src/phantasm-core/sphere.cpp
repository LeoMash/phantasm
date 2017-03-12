#include "sphere.h"

SPHERE::SPHERE (void) 
   : OBJECT()
   , radius(5)
{

}

SPHERE::SPHERE (double rad, VEC pos) 
   : OBJECT(pos)
   , radius(rad)
{

}

SPHERE::~SPHERE(void)
{

}
