#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include "matrix/matrix.h"
#include "point/point.h"

class MathVector
{
private:
    double x;
    double y;
    double z;
public:
    MathVector();
    MathVector(double x, double y, double z) : x(x), y(y), z(z) { }
    MathVector(const MathVector &vec);
    MathVector(MathVector &&vec);

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double X() const;
    double Y() const;
    double Z() const;

    MathVector& normalize();
    static MathVector cross(MathVector v1, MathVector v2);
    static double scalar(MathVector v1, MathVector v2);
    static double scalar(MathVector v, Point p);

    MathVector operator *(const Matrix<double> &matr) const;

    MathVector& operator =(const MathVector &vec);
    MathVector& operator =(MathVector &&vec);
};

#endif // MATH_VECTOR_H
