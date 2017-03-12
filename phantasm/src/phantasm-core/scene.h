#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "phm_core.h"
#include "object.h"

struct SCENE_IMPL;
class PHM_CORE_API SCENE {
public:
   SCENE (void);
   ~SCENE (void);
   void AddObject (OBJECT * newObj);
private:
   SCENE_IMPL * pImpl;
};

#endif // _SCENE_H_
