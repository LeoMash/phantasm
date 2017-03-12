#pragma once
#ifndef _TRACER_H_
#define _TRACER_H_

#include "phm_core.h"
#include "scene.h"
#include "image.h"

class PHM_CORE_API TRACER {
public:
   TRACER (void);
   ~TRACER (void);
   void TraceScene (const SCENE & scn, IMG & img);
private:
};

#endif // _TRACER_H_
