#ifndef SCENE_H
#define SCENE_H
#include "scene_object.h"
#include "vector/iterator.h"
#include "vector/vector.h"
#include "objects/composite_object.h"
#include "camera/camera.h"
#include "holder/holder.h"

class Scene
{
private:
    Vector<SceneObject> scene_objects;
    Holder<BaseObject> objects = new CompositeObject();
public:
    Scene();
    ~Scene() { }

    void addMdl(BaseObject *mdl);
    void addCam(BaseObject *cam);
    void delMdl(int i);
    void delCam(int i);

    Iterator<BaseObject*> begin();
    Iterator<BaseObject*> end();
    Iterator<SceneObject> begin_sc();
    Iterator<SceneObject> end_sc();

    SceneObject& getSceneObj(int i);
    BaseCamera* getCamera(int i);
};

#endif // SCENE_H
