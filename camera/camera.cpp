#include "camera.h"

Camera::Camera()
{
    this->pos = Point(0, 0, -300);
    this->right = MathVector(1, 0, 0);
    this->up = MathVector(0, 1, 0);
    this->look = MathVector(0, 0, 1);
}

Camera::Camera(Point pos, MathVector r, MathVector u, MathVector l)
{
    this->pos = pos;
    this->right = r;
    this->up = u;
    this->look = l;
}

Camera::Camera(const Camera &cam)
{
    this->pos = cam.pos;
    this->right = cam.right;
    this->up = cam.up;
    this->look = cam.look;
}

Camera::Camera(Camera &&cam)
{
    this->pos = cam.pos;
    this->right = cam.right;
    this->up = cam.up;
    this->look = cam.look;
}

void Camera::setPos(Point &p)
{
    this->pos = p;
}

void Camera::setLook(MathVector &l)
{
    this->look = l;
}

void Camera::setRight(MathVector &r)
{
    this->right = r;
}

void Camera::setUp(MathVector &u)
{
    this->up = u;
}

void Camera::Rotate(double deg_x, double deg_y, double deg_z)
{
    RotateMatrix matr = RotateMatrix(deg_x, deg_y, deg_z);
    this->look = this->look*matr;
    this->right = this->right*matr;
    this->up = this->up*matr;
}

void Camera::Move(double shx, double shy, double shz)
{
    this->pos.setX(this->pos.X() + shx);
    this->pos.setY(this->pos.Y() + shy);
    this->pos.setZ(this->pos.Z() + shz);
}

Matrix<double> Camera::getView()
{
    this->look.normalize();

    this->up = MathVector::cross(this->look, this->right);
    this->up.normalize();

    this->right = MathVector::cross(this->up, this->look);
    this->right.normalize();

    double x = -MathVector::scalar(this->right, this->pos);
    double y = -MathVector::scalar(this->up, this->pos);
    double z = -MathVector::scalar(this->look, this->pos);

    Matrix<double> tmp(4, 4, 0.);
    tmp[0][0] = this->right.X();
    tmp[1][0] = this->right.Y();
    tmp[2][0] = this->right.Z();
    tmp[0][1] = this->up.X();
    tmp[1][1] = this->up.Y();
    tmp[2][1] = this->up.Z();
    tmp[0][2] = this->look.X();
    tmp[1][2] = this->look.Y();
    tmp[2][2] = this->look.Z();
    tmp[3][0] = x;
    tmp[3][1] = y;
    tmp[3][2] = z;
    tmp[3][3] = 1;

    return tmp;
}

Camera& Camera::operator =(const Camera &cam)
{
    this->pos = cam.pos;
    this->right = cam.right;
    this->up = cam.up;
    this->look = cam.look;

    return *this;
}

Camera& Camera::operator =(Camera &&cam)
{
    this->pos = cam.pos;
    this->right = cam.right;
    this->up = cam.up;
    this->look = cam.look;

    return *this;
}
