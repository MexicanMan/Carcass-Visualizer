#ifndef BASE_CAMERA_H
#define BASE_CAMERA_H
#include "objects/invis_obj.h"
#include "point/point.h"
#include "math_vector/math_vector.h"

class BaseCamera : public InvisObj
{
protected:
    Point pos;  // Camera position
    MathVector right;  // Screen width vector
    MathVector up;  // Screen height vector
    MathVector look;  // Camera look vector
public:
    virtual Point getPos() = 0;
    virtual MathVector getLook() = 0;
    virtual MathVector getRight() = 0;
    virtual MathVector getUp() = 0;

    virtual void setPos(Point &pos) = 0;
    virtual void setLook(MathVector &l) = 0;
    virtual void setRight(MathVector &r) = 0;
    virtual void setUp(MathVector &u) = 0;

    virtual void Rotate(double deg_x, double deg_y, double deg_z) = 0;
    virtual void Move(double shx, double shy, double shz) = 0;

    virtual Matrix<double> getView() = 0;
};

#endif // BASE_CAMERA_H
