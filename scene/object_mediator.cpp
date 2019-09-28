#include "object_mediator.h"

ObjectMediator::ObjectMediator(BaseObject *obj)
{
    this->obj = obj;
    //this->sc = sc;
}

BaseObject* ObjectMediator::getObj()
{
    return this->obj;
}

/*SceneObject& ObjectMediator::getSceneObj()
{
    return *(this->sc);
}*/
