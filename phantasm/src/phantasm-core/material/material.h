#pragma once
#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "phm_core.h"

#include "common.h"

struct PHM_CORE_API RGB {
   RGB (void) = default;
   RGB (BYTE r, BYTE g, BYTE b) : R(r), G(g), B(b) {}
   ~RGB (void) = default;
   BYTE R;
   BYTE G;
   BYTE B;
};

#endif // _MATERIAL_H_
