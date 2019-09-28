#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H
#include "matrix.h"
#include "math.h"

class BaseTransformMatrix : public Matrix<double>
{
public:
    BaseTransformMatrix();
};

class MoveMatrix : public BaseTransformMatrix
{
public:
    MoveMatrix(double x, double y, double z);
};

class RotateMatrix : public BaseTransformMatrix
{
public:
    RotateMatrix();
    RotateMatrix(double x_alpha, double y_alpha, double z_alpha);
    RotateMatrix(const Matrix<double> &a);
};

class RotateOXMatrix : public RotateMatrix
{
public:
    RotateOXMatrix(double alpha);
};

class RotateOYMatrix : public RotateMatrix
{
public:
    RotateOYMatrix(double alpha);
};

class RotateOZMatrix : public RotateMatrix
{
public:
    RotateOZMatrix(double alpha);
};

class ScaleMatrix : public BaseTransformMatrix
{
public:
    ScaleMatrix(double k);
};

#endif // TRANSFORMMATRIX_H
