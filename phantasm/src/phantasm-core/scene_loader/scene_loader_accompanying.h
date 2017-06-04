#pragma once
#ifndef _SCENE_LOADER_ACCOMPANYING_
#define _SCENE_LOADER_ACCOMPANYING_

#include <json\json.h>
#include <json\json-forwards.h>

#include "scene\scene.h"

void SetScene (const Json::Value & root, SCENE & scn);

#endif // _SCENE_LOADER_ACCOMPANYING_
