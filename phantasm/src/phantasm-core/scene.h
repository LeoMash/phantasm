#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "phm_core.h"
#include "object.h"
#include "obj_handler.h"

class PHM_CORE_API rtrSCENE {
public:
   rtrSCENE (void) { objects = new rtrOBJ_HANDLER; };
   ~rtrSCENE (void) { delete(objects); };
   void AddObject (const rtrOBJECT & newObj);
   void AddObject (rtrOBJECT && newObj);
private:
   rtrOBJ_HANDLER * objects;
};

#endif // _SCENE_H_
