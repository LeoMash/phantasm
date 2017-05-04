#include "light.h"

POINT_LIGHT::POINT_LIGHT (void)
{
}

POINT_LIGHT::~POINT_LIGHT (void)
{
}

POINT_LIGHT::POINT_LIGHT (VEC position, RGB col) : pos(position), color(col)
{
}

VEC POINT_LIGHT::GetPosition (void) const
{

   return pos;
}

LIGHT::LIGHT (void)
{
}

LIGHT::~LIGHT (void)
{
}
