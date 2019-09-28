#include "transformmatrix.h"

BaseTransformMatrix::BaseTransformMatrix() : Matrix<double>(4, 4)
{
    this->makeSingle();
}

MoveMatrix::MoveMatrix(double x, double y, double z) : BaseTransformMatrix()
{
    (*this)[3][0] = x;
    (*this)[3][1] = y;
    (*this)[3][2] = z;
}

RotateMatrix::RotateMatrix() : BaseTransformMatrix()
{ }

RotateMatrix::RotateMatrix(double x_alpha, double y_alpha, double z_alpha) : BaseTransformMatrix()
{
    RotateMatrix X = RotateOXMatrix(x_alpha);
    RotateMatrix Y = RotateOYMatrix(y_alpha);
    RotateMatrix Z = RotateOZMatrix(z_alpha);

    *this = static_cast<RotateMatrix>(X*Y*Z);
}

RotateMatrix::RotateMatrix(const Matrix<double> &a)
{
    if (this->length_m() != a.length_m() || this->length_n() != a.length_n())
        throw MatrixError::dimError("in RotateMatrix(const Matrix &a)");

    for (int i = 0; i < a.length_m(); i++)
        for (int j = 0; j < a.length_n(); j++)
            (*this)[i][j] = a[i][j];
}

RotateOXMatrix::RotateOXMatrix(double alpha) : RotateMatrix()
{
    (*this)[1][1] = cos(alpha);
    (*this)[1][2] = sin(alpha);
    (*this)[2][1] = -sin(alpha);
    (*this)[2][2] = cos(alpha);
}

RotateOYMatrix::RotateOYMatrix(double alpha) : RotateMatrix()
{
    (*this)[0][0] = cos(alpha);
    (*this)[0][2] = -sin(alpha);
    (*this)[2][0] = sin(alpha);
    (*this)[2][2] = cos(alpha);
}

RotateOZMatrix::RotateOZMatrix(double alpha) : RotateMatrix()
{
    (*this)[0][0] = cos(alpha);
    (*this)[0][1] = sin(alpha);
    (*this)[1][0] = -sin(alpha);
    (*this)[1][1] = cos(alpha);
}

ScaleMatrix::ScaleMatrix(double k) : BaseTransformMatrix()
{
    (*this)[0][0] = k;
    (*this)[1][1] = k;
    (*this)[2][2] = k;
}
