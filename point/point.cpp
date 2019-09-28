#include "point.h"

Point::Point()
{
    this->x = this->y = this->z = 0;
}

Point::Point(const Point &pnt)
{
    this->x = pnt.x;
    this->y = pnt.y;
    this->z = pnt.z;
}

Point::Point(Point &&pnt)
{
    this->x = pnt.x;
    this->y = pnt.y;
    this->z = pnt.z;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

double Point::X() const
{
    return this->x;
}

double Point::Y() const
{
    return this->y;
}

double Point::Z() const
{
    return this->z;
}

Point& Point::operator =(const Point &pnt)
{
    this->x = pnt.x;
    this->y = pnt.y;
    this->z = pnt.z;

    return *this;
}

Point& Point::operator =(Point &&pnt)
{
    this->x = pnt.x;
    this->y = pnt.y;
    this->z = pnt.z;

    return *this;
}

Point Point::operator *(const Matrix<double> &matr) const
{
    if (matr.length_m() != 4 || matr.length_n() != 4)
        throw MatrixError::dimError("in Point * Matrix");

    Point res;

    res.setX(this->x*matr[0][0]+this->y*matr[1][0]+this->z*matr[2][0]+matr[3][0]);
    res.setY(this->x*matr[0][1]+this->y*matr[1][1]+this->z*matr[2][1]+matr[3][1]);
    res.setZ(this->x*matr[0][2]+this->y*matr[1][2]+this->z*matr[2][2]+matr[3][2]);

    return res;
}

Point Point::operator +(const Point &p) const
{
    double tx = this->x+p.X();
    double ty = this->y+p.Y();
    double tz = this->z+p.Z();

    return Point(tx, ty, tz);
}

bool Point::operator ==(const Point &pnt) const
{
    if(this->x != pnt.x || this->y != pnt.y || this->z != pnt.z)
        return false;

    return true;
}

bool Point::operator !=(const Point &pnt) const
{
    if(this->x == pnt.x || this->y == pnt.y || this->z == pnt.z)
        return false;

    return true;
}
