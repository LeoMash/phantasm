#include "ray.h"

RAY::RAY (VEC startingPoint, VEC direction) : start(startingPoint)
{
   dir = direction.Normalize();
}
