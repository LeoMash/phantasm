#pragma once
#ifndef _TRACER_H_
#define _TRACER_H_

#include "scene.h"

class rtrTRACER {
public:
   rtrTRACER (void);
   ~rtrTRACER (void);
   void TraceScene (const rtrSCENE & scn, char * outFile); // IMG
private:
};

#endif // _TRACER_H_
