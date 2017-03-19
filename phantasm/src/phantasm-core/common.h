#pragma once
#ifndef _COMMON_CORE_H_
#define _COMMON_CORE_H_

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string>

#ifndef   NULL
#define   NULL nullptr
#endif // NULL

#ifndef   BYTE
#define   BYTE unsigned char
#endif // BYTE

struct RGB {
   RGB (void) = default;
   RGB (BYTE r, BYTE g, BYTE b) : R(r), G(g), B(b) {}
   ~RGB (void) = default;
   BYTE R;
   BYTE G;
   BYTE B;
};

#endif // _COMMON_CORE_H_
