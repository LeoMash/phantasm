#include "common.h"

#include "object.h"

OBJECT::OBJECT (void) : position(VEC())
{

}

OBJECT::OBJECT (VEC pos, MTL mtl) : position(pos), material(mtl)
{

}

OBJECT::~OBJECT (void)
{

}

