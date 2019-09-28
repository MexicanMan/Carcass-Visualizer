#include "scene_object.h"

Point& SceneObject::getCenter()
{
    return this->center;
}

BaseTransformMatrix& SceneObject::getTransfMatr()
{
    return this->transform_matrix;
}

void SceneObject::setCenter(const Point &c)
{
    this->center = c;
}

void SceneObject::setCenter(double x, double y, double z)
{
    this->center.setX(x);
    this->center.setY(y);
    this->center.setZ(z);
}

void SceneObject::setTransMatr(const BaseTransformMatrix &tm)
{
    this->transform_matrix = tm;
}

BaseObject* SceneObject::getModel()
{
    BaseObject *t = this->mediator.getObj();
    if (t)
        return t;
    else
    {
        throw SceneObjError::NoModelError("in getModel()");
        return nullptr;
    }
}

BaseObject* SceneObject::operator ->()
{
    BaseObject *t = this->mediator.getObj();
    if (t)
        return t;
    else
    {
        throw SceneObjError::NoModelError("in ->");
        return nullptr;
    }
}
