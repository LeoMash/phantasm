#pragma once
#ifndef _TRACER_H_
#define _TRACER_H_

#include "phm_core_export.h"

class rtrTRACER {
public:
   rtrTRACER (void) {}
   ~rtrTRACER (void) {}
   void LoadSceneFromJSON (std::string fileName);
private:
   rtrSCENE scn;
};

#endif // _TRACER_H_
