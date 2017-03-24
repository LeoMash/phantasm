#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "..\phm_core.h"
#include "..\objects\object.h"
#include "..\objects\sphere.h"

struct SCENE_IMPL;
class PHM_CORE_API SCENE {
public:
   SCENE (void);
   ~SCENE (void);
   void AddObject (OBJECT * newObj);
   void IntersectAll (const RAY & ray, std::vector<INTERSECT_PARAMS> & prms) const;
private:
   SCENE_IMPL * pImpl;
};

#endif // _SCENE_H_
