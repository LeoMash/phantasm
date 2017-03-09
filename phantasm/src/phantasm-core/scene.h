#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "phm_core.h"
#include "object.h"

struct SCENE_IMPL;
class PHM_CORE_API rtrSCENE {
public:
   rtrSCENE (void);
   ~rtrSCENE (void);
   void AddObject (rtrOBJECT * newObj);
private:
   SCENE_IMPL * pImpl;
};

#endif // _SCENE_H_
