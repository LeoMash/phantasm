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



RGB & RGB::operator= (const RGB & col)
{
   R = col.R;
   G = col.G;
   B = col.B;

   return *this;
}

BYTE ClampColor (double c) 
{
   if (c < 0) {
      c = 0;
   } else if (c > 255) {
      c = 255;
   }

   return static_cast<BYTE>(c);
}

RGB RGB::operator* (double d) const
{
   RGB res = *this;

   res.R = ClampColor(static_cast<double>(res.R) * d);
   res.G = ClampColor(static_cast<double>(res.G) * d);
   res.B = ClampColor(static_cast<double>(res.B) * d);

   return res;
}

RGB RGB::operator+ (const RGB d) const
{
   RGB res = *this;

   res.R = ClampColor(static_cast<double>(res.R) + static_cast<double>(d.R));
   res.G = ClampColor(static_cast<double>(res.G) + static_cast<double>(d.G));
   res.B = ClampColor(static_cast<double>(res.B) + static_cast<double>(d.B));

   return res;
}

RGB & RGB::operator+= (const RGB d)
{
   R = ClampColor(static_cast<double>(R) + static_cast<double>(d.R));
   G = ClampColor(static_cast<double>(G) + static_cast<double>(d.G));
   B = ClampColor(static_cast<double>(B) + static_cast<double>(d.B));

   return *this;
}


BYTE ClampByte (BYTE c)
{
   if (c < 0) {
      c = 0;
   } else if (c > 255) {
      c = 255;
   }

   return c;
}


RGB & RGB::Clamp (void)
{
   R = ClampByte(R);
   G = ClampByte(G);
   B = ClampByte(B);


   return *this;
}




MTL::MTL (void) : Ka(0.5), Ks(0), Kd(0.5), phong(0.0), refl(false), refr(0.0), color(RGB(255, 255, 255))
{
}


MTL::~MTL(void)
{
}


MTL::MTL(double ka, double ks, double kd, double phon, bool reflection, double refraction, RGB col) : Ka(ka), Ks(ks), Kd(kd), phong(phon), refl(reflection), refr(refraction), color(col)
{
}
