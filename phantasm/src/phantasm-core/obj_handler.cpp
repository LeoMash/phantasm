#include "common.h"

#include "obj_handler.h"

void rtrOBJ_HANDLER::AddObject (rtrOBJECT && newObj)
{
   hnd.push_back(newObj);
}

void rtrOBJ_HANDLER::AddObject (const rtrOBJECT & newObj)
{
   hnd.push_back(newObj);
}

void rtrOBJ_HANDLER::Clear (void)
{
   hnd.clear();
}
