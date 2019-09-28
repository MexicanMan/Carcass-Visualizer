#ifndef POINT_H
#define POINT_H
#include "objects/vis_object.h"
#include "matrix/matrix.h"

// Point
class Point : public VisObject
{
private:
    double x;
    double y;
    double z;

public:
    Point();
    Point(double x, double y, double z) : x(x), y(y), z(z) { }
    Point(const Point &pnt);
    Point(Point &&pnt);

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double X() const;
    double Y() const;
    double Z() const;

    Point& operator =(const Point &pnt);
    Point& operator =(Point &&pnt);

    Point operator *(const Matrix<double> &matr) const;
    Point operator +(const Point &p) const;

    bool operator ==(const Point &pnt) const;
    bool operator !=(const Point &pnt) const;
};

#endif // POINT_H
