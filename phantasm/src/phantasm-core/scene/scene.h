#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <vector>

#include "..\phm_core.h"
#include "..\objects\object.h"
#include "..\objects\sphere.h"

class PHM_CORE_API SCENE {
public:
   struct IMPL;

   SCENE (void);
   ~SCENE (void);
   void AddObject (OBJECT * newObj);
   void IntersectAll (const RAY & ray, std::vector<INTERSECT_PARAMS> & prms) const;
private:
   IMPL * pImpl;
};

#endif // _SCENE_H_
