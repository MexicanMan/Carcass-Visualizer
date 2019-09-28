#include "math_vector.h"

MathVector::MathVector()
{
    this->x = this->y = this->z = 0;
}

MathVector::MathVector(const MathVector &vec)
{
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
}

MathVector::MathVector(MathVector &&vec)
{
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
}

void MathVector::setX(double x)
{
    this->x = x;
}

void MathVector::setY(double y)
{
    this->y = y;
}

void MathVector::setZ(double z)
{
    this->z = z;
}

double MathVector::X() const
{
    return this->x;
}

double MathVector::Y() const
{
    return this->y;
}

double MathVector::Z() const
{
    return this->z;
}

MathVector& MathVector::normalize()
{
    double len = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
    double norm = 1/len;

    this->x *= norm;
    this->y *= norm;
    this->z *= norm;

    return (*this);
}

MathVector MathVector::cross(MathVector v1, MathVector v2)
{
    MathVector tmp;
    tmp.x = v1.Z()*v2.Y() - v1.Y()*v2.Z();
    tmp.y = v1.X()*v2.Z() - v1.Z()*v2.X();
    tmp.z = v1.Y()*v2.X() - v1.X()*v2.Y();

    return tmp;
}

double MathVector::scalar(MathVector v1, MathVector v2)
{
    return v1.X()*v2.X() + v1.Y()*v2.Y() + v1.Z()*v2.Z();
}

double MathVector::scalar(MathVector v, Point p)
{
    return v.X()*p.X() + v.Y()*p.Y() + v.Z()*p.Z();
}

MathVector MathVector::operator *(const Matrix<double> &matr) const
{
    if (matr.length_m() != 4 || matr.length_n() != 4)
        throw MatrixError::dimError("in MathVector * Matrix");

    MathVector res;

    res.setX(this->x*matr[0][0]+this->y*matr[1][0]+this->z*matr[2][0]+matr[3][0]);
    res.setY(this->x*matr[0][1]+this->y*matr[1][1]+this->z*matr[2][1]+matr[3][1]);
    res.setZ(this->x*matr[0][2]+this->y*matr[1][2]+this->z*matr[2][2]+matr[3][2]);

    return res;
}

MathVector& MathVector::operator =(const MathVector &vec)
{
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;

    return *this;
}

MathVector& MathVector::operator =(MathVector &&vec)
{
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;

    return *this;
}
