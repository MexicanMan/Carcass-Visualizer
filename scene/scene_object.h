#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H
#include "matrix/transformmatrix.h"
#include "point/point.h"
#include "object_mediator.h"

class SceneObject
{
private:
    Point center;
    BaseTransformMatrix transform_matrix;
    ObjectMediator mediator;
public:
    SceneObject() { }
    explicit SceneObject(const Point &c, const BaseTransformMatrix &tm, BaseObject *obj) : center(c),
        transform_matrix(tm), mediator(obj) { }

    Point& getCenter();
    BaseTransformMatrix& getTransfMatr();

    void setCenter(const Point &c);
    void setCenter(double x, double y, double z);
    void setTransMatr(const BaseTransformMatrix &tm);
    BaseObject *getModel();
    BaseObject* operator ->();
};

#endif // SCENE_OBJECT_H
