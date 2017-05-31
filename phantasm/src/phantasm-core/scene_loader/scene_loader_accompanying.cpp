#include <functional>

#include "objects\sphere.h"
#include "objects\plane.h"

#include "scene_loader_accompanying.h"


int GetInt (const Json::Value & val, const std::string & name)
{
   return val[name].asInt();
}


double GetDouble (const Json::Value & val, const std::string & name)
{
   return val[name].asDouble();
}


VEC GetVec (const Json::Value & val, const std::string & name)
{
   const Json::Value res = val[name];

   return VEC(res[0].asDouble(), res[1].asDouble(), res[2].asDouble());
}


RGB GetColor (const Json::Value & val, const std::string & name)
{
   const Json::Value res = val[name];

   return RGB(res[0].asUInt(), res[1].asUInt(), res[2].asUInt());
}


MTL GetMaterial (const Json::Value & val, const std::string & material, const std::string & color)
{
   const Json::Value res = val[material];

   return  MTL(res["Ka"].asDouble(),
      res["Ks"].asDouble(),
      res["Kd"].asDouble(),
      res["Kr"].asDouble(),
      res["Kt"].asDouble(),
      res["Phong"].asDouble(),
      res["Refl"].asBool(),
      res["Refr"].asDouble(),

      GetColor(val, color));
}


CAM GetCamera (const Json::Value & val, const std::string & name)
{
   const Json::Value cam = val[name];

   return CAM(GetVec(cam, "position"),
      GetVec(cam, "lookAt"),
      GetVec(cam, "up"),
      GetDouble(cam, "viewAngle"));
}


void CallForWholeArray (SCENE & scn, const Json::Value & val, const std::string & name, std::function<void(const Json::Value & obj, SCENE & scn)> func)
{
   const Json::Value objects = val[name];
   for (unsigned int index = 0; index < objects.size(); index++) {
      func(objects[index], scn);
   }
}


void AddPlane (const Json::Value & obj, SCENE & scn)
{
   scn.AddObject(new PLANE(
      GetVec(obj, "normal"),
      GetVec(obj, "position"),
      GetMaterial(obj, "material", "color")));
}


void AddSphere (const Json::Value & obj, SCENE & scn)
{
   scn.AddObject(new SPHERE(
      GetDouble(obj, "radius"),
      GetVec(obj, "position"),
      GetMaterial(obj, "material", "color")));
}

void AddPointLight (const Json::Value & obj, SCENE & scn)
{
   scn.AddLight(new POINT_LIGHT(GetVec(obj, "position"), GetColor(obj, "color")));
}


void AddLight (const Json::Value & obj, SCENE & scn)
{
   const Json::Value type = obj["type"];

   if (!strcmp(type.asCString(), "point")) {
      AddPointLight(obj, scn);
   }
}


void AddObject (const Json::Value & obj, SCENE & scn)
{
   const Json::Value type = obj["type"];

   if (!strcmp(type.asCString(), "sphere")) {
      AddSphere(obj, scn);
   } else if (!strcmp(type.asCString(), "plane")) {
      AddPlane(obj, scn);
   }
}


void SetScene (const Json::Value & root, SCENE & scn)
{
   scn.SetMaxDepth(GetInt(root, "depth"));
   scn.SetBackgroundColor(GetColor(root, "background"));
   scn.SetCamera(GetCamera(root, "camera"));


   CallForWholeArray(scn, root, "lights", AddLight);
   CallForWholeArray(scn, root, "objects", AddObject);
}

