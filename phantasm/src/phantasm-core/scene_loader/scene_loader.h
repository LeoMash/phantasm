#pragma once 
#ifndef _SCENE_LOADER_H_
#define _SCENE_LOADER_H_

#include <string>

#include "..\phm_core.h"
#include "..\scene\scene.h"

bool PHM_CORE_API LoadSceneFromJSON (SCENE & scn, std::string fileName);

#endif // _SCENE_LOADER_H_
