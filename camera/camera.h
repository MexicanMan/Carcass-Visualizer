#ifndef CAMERA_H
#define CAMERA_H
#include "base_camera.h"
#include "matrix/transformmatrix.h"

class Camera : public BaseCamera
{
public:
    Camera();
    Camera(Point pos, MathVector r, MathVector u, MathVector l);
    Camera(const Camera &cam);
    Camera(Camera &&cam);

    ~Camera() { }

    Point getPos() { return this->pos; }
    MathVector getLook() { return this->look; }
    MathVector getRight() { return this->right; }
    MathVector getUp() { return this->up; }

    void setPos(Point &p);
    void setLook(MathVector &l);
    void setRight(MathVector &r);
    void setUp(MathVector &u);

    void Rotate(double deg_x, double deg_y, double deg_z);
    void Move(double shx, double shy, double shz);

    Matrix<double> getView();

    Camera& operator =(const Camera &cam);
    Camera& operator =(Camera &&cam);
};

#endif // CAMERA_H
