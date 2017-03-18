#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "..\phm_core.h"

#include "..\math\vecmat.h"

class PHM_CORE_API OBJECT {
public:
   OBJECT (void);
   OBJECT (VEC pos);
   virtual ~OBJECT (void);
private:
   VEC position;
};

#endif // _OBJECT_H_
