#include "..\common.h"

#include "object.h"

OBJECT::OBJECT (void) : position(VEC())
{

}

OBJECT::OBJECT (VEC pos, RGB clr) : position(pos), color(clr)
{

}

OBJECT::~OBJECT (void)
{

}

