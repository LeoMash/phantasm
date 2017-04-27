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

LIGHT::LIGHT (void)
{
}

LIGHT::~LIGHT (void)
{
}
