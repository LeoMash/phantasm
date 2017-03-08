#pragma once
#ifndef _OBJ_HANDLER_H_
#define _OBJ_HANDLER_H_

#include "object.h"

#include <vector>

class rtrOBJ_HANDLER {
public:
   rtrOBJ_HANDLER (void) {};
   ~rtrOBJ_HANDLER (void) {};
   void AddObject (rtrOBJECT && newObj);
   void AddObject (const rtrOBJECT & newObj);
   void Clear     (void);
private:
   std::vector<rtrOBJECT> hnd;
};

#endif // _OBJ_HANDLER_H_
