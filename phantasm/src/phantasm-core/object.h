#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "phm_core.h"

#include "vecmat.h"

class PHM_CORE_API rtrOBJECT {
public:
   rtrOBJECT (void);
   rtrOBJECT (VEC pos);
   virtual ~rtrOBJECT (void);
private:
   VEC position;
};

#endif // _OBJECT_H_
