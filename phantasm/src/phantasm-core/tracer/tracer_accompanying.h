#pragma once
#ifndef _TRACER_ACCOMPANYING_
#define _TRACER_ACCOMPANYING_

#include "common.h" 
#include "ray.h"
#include "scene\scene.h"

RGB Trace (const RAY & ray, const SCENE & scn, int depth);

#endif // _TRACER_ACCOMPANYING_
