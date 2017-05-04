#include "material.h"

RGB::RGB (void)
{
   R = 0;
   G = 0;
   B = 0;
}

RGB::RGB (const RGB & rgb) : R(rgb.R), G(rgb.G), B(rgb.B)
{
}


RGB::RGB (BYTE r, BYTE g, BYTE b) : R(r), G(g), B(b)
{
}

RGB::~RGB (void)
{
}


BYTE RegulateColor (double c)
{
   if (c < 0) {
      c = 0;
   } else if (c > 255) {
      c = 255;
   }

   return static_cast<BYTE>(c);
}

RGB & RGB::operator= (const RGB & col)
{
   R = col.R;
   G = col.G;
   B = col.B;

   return *this;
}

RGB RGB::operator* (double d) const
{
   RGB res = *this;

   res.R = RegulateColor(static_cast<double>(res.R) * d);
   res.G = RegulateColor(static_cast<double>(res.G) * d);
   res.B = RegulateColor(static_cast<double>(res.B) * d);

   return res;
}

RGB RGB::operator+ (const RGB d) const
{
   RGB res = *this;

   res.R += d.R;
   res.G += d.G;
   res.B += d.B;

   return res;
}

RGB & RGB::operator+= (const RGB d)
{
   R += d.R;
   G += d.G;
   B += d.B;

   return *this;
}

