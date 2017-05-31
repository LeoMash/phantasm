#pragma once
#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "phm_core.h"

#include "common.h"

struct PHM_CORE_API RGB {
   RGB (void);
   RGB (const RGB & rgb);
   RGB (BYTE r, BYTE g, BYTE b);
   ~RGB (void);

   RGB & operator=  (const RGB & col);
   RGB   operator*  (double d) const;
   RGB   operator+  (const RGB d) const;
   RGB & operator+= (const RGB d);


   RGB & RGB::Clamp (void);

   BYTE R;
   BYTE G;
   BYTE B;
};

struct PHM_CORE_API MTL {
   MTL (void);
   ~MTL (void);

   MTL (double ka, double ks, double kd, double kr, double kt, double phon, bool reflection, double refraction, RGB col);


   double Ka;
   double Ks;
   double Kd;
   double Kr;
   double Kt;
   double phong;

   bool refl;
   double refr;


   RGB color;
};

#endif // _MATERIAL_H_
