#include "sphere.h"

rtrSPHERE::rtrSPHERE (void) 
   : rtrOBJECT()
   , radius(5)
{

}

rtrSPHERE::rtrSPHERE (double rad, VEC pos) 
   : rtrOBJECT(pos)
   , radius(rad)
{

}

rtrSPHERE::~rtrSPHERE(void)
{

}
