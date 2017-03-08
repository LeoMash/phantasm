#include "common.h"

#include "obj_handler.h"
#include "scene.h"

void rtrSCENE::AddObject (const rtrOBJECT & newObj)
{
   objects->AddObject(newObj);
}
void rtrSCENE::AddObject (rtrOBJECT && newObj)
{
   objects->AddObject(newObj);
}
