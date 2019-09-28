#ifndef OBJECT_MEDIATOR_H
#define OBJECT_MEDIATOR_H
#include "objects/base_object.h"
//#include "scene/scene_object.h"

class ObjectMediator
{
private:
    BaseObject *obj;
   //SceneObject *sc;
public:
    ObjectMediator() { this->obj = nullptr; }
    ObjectMediator(BaseObject *obj);

    ~ObjectMediator() { }

    BaseObject *getObj();
    //SceneObject& getSceneObj();
};

#endif // OBJECT_MEDIATOR_H
