#pragma once
#ifndef _SCENE_LOADER_ACCOMPANYING_
#define _SCENE_LOADER_ACCOMPANYING_

#include <functional>

#include <json\json.h>
#include <json\json-forwards.h>

#include "scene\scene.h"


int GetInt (const Json::Value & val, const std::string & name);
double GetDouble (const Json::Value & val, const std::string & name);

VEC GetVec (const Json::Value & val, const std::string & name);
RGB GetColor (const Json::Value & val, const std::string & name);
MTL GetMaterial (const Json::Value & val, const std::string & material, const std::string & color);
CAM GetCamera (const Json::Value & val, const std::string & name);

void CallForWholeArray (SCENE & scn, const Json::Value & val, const std::string & name, std::function<void(const Json::Value & obj, SCENE & scn)> func);

void AddPlane  (const Json::Value & obj, SCENE & scn);
void AddSphere (const Json::Value & obj, SCENE & scn);

void AddPointLight (const Json::Value & obj, SCENE & scn);

void AddLight  (const Json::Value & obj, SCENE & scn);
void AddObject (const Json::Value & obj, SCENE & scn);


void SetScene (const Json::Value & root, SCENE & scn);

#endif // _SCENE_LOADER_ACCOMPANYING_
