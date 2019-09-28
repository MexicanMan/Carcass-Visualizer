#ifndef MATRWORK_CPP
#define MATRWORK_CPP
#include "matrix.h"
#include "errors.h"
#include <math.h>

// Matrix addition
template <typename T>
Matrix<T> Matrix<T>::plus(const Matrix<T> &second) const
{
    if (this->m != second.m && this->n != second.n)
        throw MatrixError::dimError("in plus()");

    Matrix<T> result(this->m, this->n);
    result.m = this->m;
    result.n = this->n;
    for (int i=0; i < this->m; i++)
        result.matr[i] = this->matr[i]+second.matr[i];

    return result;
}

// Matrix subtraction
template <typename T>
Matrix<T> Matrix<T>::minus(const Matrix<T> &second) const
{
    if (this->m != second.m && this->n != second.n)
        throw MatrixError::dimError("in minus()");

    Matrix<T> result(this->m, this->n);
    result.m = this->m;
    result.n = this->n;
    for (int i=0; i < this->m; i++)
        result.matr[i] = this->matr[i]-second.matr[i];

    return result;
}

// Matrices multiplication
template <typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T> &second) const
{
    if (this->n != second.m)
        throw MatrixError::dimError("in multiply()");

    Matrix<T> result(this->m, second.n);
    result.m = this->m;
    result.n = second.n;
    for (int i=0; i<this->m; i++)
        for (int j=0; j<second.n; j++)
            for (int k=0; k<this->n; k++)
                result[i][j] += this->matr[i][k] * second.matr[k][j];

    return result;
}

// Matrix multiplication by an element (number)
template <typename T>
Matrix<T> Matrix<T>::multiply(const T &val) const
{
    Matrix<T> result(this->m, this->n);
    result.m = this->m;
    result.n = this->n;
    for (int i=0; i < this->m; i++)
        for (int j=0; j<this->n; j++)
            result.matr[i][j] = this->matr[i][j]*val;

    return result;
}

// Matrix division by an element (number)
template <typename T>
Matrix<T> Matrix<T>::divide(const T &val) const
{
    Matrix<T> result(this->m, this->n);
    result.m = this->m;
    result.n = this->n;
    for (int i=0; i < this->m; i++)
        for (int j=0; j<this->n; j++)
            result.matr[i][j] = this->matr[i][j]/val;

    return result;
}

template <typename T>
Matrix<T>::Matrix() : Matrix<T>(0, 0)
{ }

template <typename T>
Matrix<T>::Matrix(int m, int n)
{
    this->matr.setSize(m);
    for (int i = 0; i < m; i++)
        this->matr[i].setSize(n);

    this->m = m;
    this->n = n;
}

template <typename T>
Matrix<T>::Matrix(int m, int n, const T &val)
{
    this->matr.setSize(m);
    for (int i = 0; i < m; i++)
    {
        Vector<T> t(n, val);
        this->matr[i] = t;
    }

    this->m = m;
    this->n = n;
}

// Constructor allocating memory and filling matrix with given vector
template <typename T>
Matrix<T>::Matrix(int m, const Vector<T> &vector)
{
    this->matr.setSize(m);
    for (int i = 0; i < m; i++)
        this->matr[i] = vector;

    this->m = m;
    this->n = vector.length();
}

template <typename T>
Matrix<T>::Matrix(int m, int n, void *mat)
{
    T (*mat1)[m] = static_cast<T (*)[m]>(mat);
    this->matr.setSize(m);

    for (int i = 0; i < m; i++)
    {
        Vector<T> t(n);
        this->matr[i] = t;
        for (int j=0; j < n; j++)
            this->matr[i][j] = mat1[i][j];
    }

    this->m = m;
    this->n = n;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &matrix) : BaseMatrix()
{
    this->matr.setSize(matrix.m);

    this->m = matrix.m;
    this->n = matrix.n;
    for (int i = 0; i < this->m; i++)
        this->matr[i] = matrix.matr[i];
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &&matrix)
{
    this->matr = matrix.matr;
    this->m = matrix.m;
    this->n = matrix.n;

    //matrix.matr.setSize(0);
    matrix.m = 0;
    matrix.n = 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
    this->m = 0;
    this->n = 0;
}

///
//
template <typename T>
void Matrix<T>::append_row(const Vector<T> &vec)
{
    if(vec.length() != this->n)
        throw MatrixError::dimError("in append_row()");

    this->matr.append(vec);
    this->m++;
}

//
template <typename T>
void Matrix<T>::append_column(const Vector<T> &vec)
{
    if(vec.length() != this->m)
        throw MatrixError::dimError("in append_column()");

    for(int i = 0; i<this->m; i++)
        this->matr[i].append(vec[i]);
    this->n++;
}

//
template <typename T>
void Matrix<T>::set_row(int i, const Vector<T> &vec)
{
    if (i < 0 || i >= this->m)
        throw VectorError::rangeError("in set_row()");
    if(vec.length() != this->n)
        throw MatrixError::dimError("in set_row()");

    for(int j = 0; j<this->n; j++)
        this->matr[i][j] = vec[j];
}

//
template <typename T>
void Matrix<T>::set_column(int i, const Vector<T> &vec)
{
    if (i < 0 || i >= this->n)
        throw VectorError::rangeError("in set_column()");
    if(vec.length() != this->m)
        throw MatrixError::dimError("in set_column()");

    for(int j = 0; j<this->m; j++)
        this->matr[j][i] = vec[j];
}

template <typename T>
T& Matrix<T>::value(int i, int j)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in value(int, int)");
    if (i < 0 || i >= this->m || j < 0 || j >= this->n)
        throw VectorError::rangeError("in value(int, int)");

    return this->matr[i][j];
}

template <typename T>
const T& Matrix<T>::value(int i, int j) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in value(int, int) c");
    if (i < 0 || i >= this->m || j < 0 || j >= this->n)
        throw VectorError::rangeError("in value(int, int) c");

    return this->matr[i][j];
}

template <typename T>
const T* Matrix<T>::addres(int i, int j) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in addres(int, int)");
    if (i < 0 || i >= this->m || j < 0 || j >= this->n)
        throw VectorError::rangeError("in addres(int, int)");

    return (this->matr+i)->addres(j);
}

// Matrix determinant
template <typename T>
double Matrix<T>::determinant() const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in determinant()");
    if (this->m != this->n)
        throw MatrixError::notSquare("in determinant()");

    double det = 1;
    try
    {
        Matrix<T> tmp = this->makeDiagonal();
        //std::cout << tmp;
        for (int i=0; i < this->m; i++)
            det *= tmp.matr[i][i];
    }
    catch (MatrixError::DegMatrix &e)
    {
        det = 0;
    }

    return det;
}

// Matrix degeneration checking
template <typename T>
bool Matrix<T>::isDegenerate() const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in isDegenerate()");
    if (this->m != this->n)
        throw MatrixError::notSquare("in isDegenerate()");

    double det = this->determinant();
    if (det == 0)
        return true;
    else
        return false;
}

// Creation of upper triangular matrix
template <typename T>
Matrix<T> Matrix<T>::makeUpTriangle() const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in makeUpTriangle()");
    if (this->m != this->n)
        throw MatrixError::notSquare("in makeUpTriangle()");

    int maxM;
    T max_value, value;
    double koef;
    Vector<T> tmp;
    Matrix<T> result(*this);

    for (int i=0; i<result.m-1; i++)  // All rows except the last one
     {
         maxM = i;
         max_value = abs(result.matr[i][i]);
         for (int j=i+1; j<result.m; j++)  // Look for row with max element
         {
             value = result.matr[j][i];
             if (value > max_value)
             {
                 maxM = j;
                 max_value = value;
             }
         }

         if (maxM > i)  // If we need to exchange rows
         {
             tmp = result.matr[i];
             result.matr[i] = result.matr[maxM];
             result.matr[maxM] = tmp;
         }
         else  // Else comparing with 0
             if (abs(max_value) <= 1e-6)
                 throw MatrixError::DegMatrix("in makeUpTriangle()");

         value = result.matr[i][i];
         for (int j=i+1; j<result.m; j++)  // Subtracting row from every other
         {
             koef = result.matr[j][i]/value;
             for (int k=0; k<result.m; k++)
             {
                 result.matr[j][k] -= result.matr[i][k]*koef;
             }
         }
     }

     if (fabs(result.matr[result.m-1][result.n-1]) <= 1e-6)
         throw MatrixError::DegMatrix("in makeUpTriangle()");

     return result;
}

// Creation of diagonal matrix
template <typename T>
Matrix<T> Matrix<T>::makeDiagonal() const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in makeDiagonal()");
    if (this->m != this->n)
        throw MatrixError::notSquare("in makeDiagonal()");

    T value;
    double koef;
    Matrix<T> result = this->makeUpTriangle();

    for (int i=result.m-1; i>0; i--)  // All rows except the first one
    {
        value = result.matr[i][i];
        if (abs(value) <= 1e-6)
            throw MatrixError::DegMatrix("in makeDiagonal()");

        for (int j=i-1; j>=0; j--)  // Subtracting row from every prev
        {
            koef = result.matr[j][i]/value;
            for (int k=result.m-1; k>=0; k--)
                result.matr[j][k] -= result.matr[i][k]*koef;
        }
    }

    if (abs(result.matr[0][0]) <= 1e-6)
        throw MatrixError::DegMatrix("in makeDiagonal()");

    return result;
}

// Make matrix singular
template <typename T>
Matrix<T> &Matrix<T>::makeSingle()
{
    if (this->isEmpty())
        throw VectorError::emptyError("in makeSingle()");
    if (this->m != this->n)
        throw MatrixError::notSquare("in makeSingle()");

    for (int i=0; i<this->m; i++)
        for(int j=0; j<this->m; j++)
            if (i == j)
                this->matr[i][j] = 1;
            else
                this->matr[i][j] = 0;

    return *this;
}

// Square matrix transpose
template <typename T>
Matrix<T> &Matrix<T>::transposeSquare()
{
    if (this->isEmpty())
        throw VectorError::emptyError("in transposeSquare()");
    if (this->m != this->n)
        throw MatrixError::notSquare("in transposeSquare()");

    for (int i=0; i<this->m; i++)
        for(int j=0; j < i; j++)
        {
            T t = this->matr[i][j];
            this->matr[i][j] = this->matr[j][i];
            this->matr[j][i] = t;
        }

    return *this;
}

template <typename T>
Vector<T>& Matrix<T>::operator [](int i)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in []");
    if (i < 0 || i >= this->m)
        throw VectorError::rangeError("in []");
    return this->matr[i];
}

template <typename T>
const Vector<T>& Matrix<T>::operator [](int i) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in [] c");
    if (i < 0 || i >= this->m)
        throw VectorError::rangeError("in [] c");
    return this->matr[i];
}

template <typename T>
T& Matrix<T>::operator ()(int i, int j)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in ()");
    if (i < 0 || i >= this->m || j < 0 || j >= this->n)
        throw VectorError::rangeError("in ()");
    return this->matr[i][j];
}

template <typename T>
const T& Matrix<T>::operator ()(int i, int j) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in () c");
    if (i < 0 || i >= this->m || j < 0 || j >= this->n)
        throw VectorError::rangeError("in () c");
    return this->matr[i][j];
}

template <typename T>
bool Matrix<T>::operator !=(const Matrix<T> &second) const
{
    bool flag = true;
    if (this->m == second.m && this->n == second.n)
    {
        flag = false;
        for (int i=0; i<this->m && !flag; i++)
            for (int j=0; j<this->n && !flag; j++)
                if (this->matr[i][j] != second.matr[i][j])
                    flag = true;
    }

    return flag;
}

template <typename T>
bool Matrix<T>::operator ==(const Matrix<T> &second) const
{
    bool flag = false;
    if (this->m == second.m && this->n == second.n)
    {
        flag = true;
        for (int i=0; i<this->m && flag; i++)
            for (int j=0; j<this->n && flag; j++)
                if (this->matr[i][j] != second.matr[i][j])
                    flag = false;
    }

    return flag;
}

template <typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &second) const
{
    return plus(second);
}

template <typename T>
Matrix<T>& Matrix<T>::operator +=(const Matrix<T> &second)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in +=");
    if (this->m != second.m && this->n != second.n)
        throw MatrixError::dimError("in +=");

    Vector<Vector<T>> result(this->m);

    for (int i=0; i < this->m; i++)
        result[i] = this->matr[i]+second.matr[i];

    this->matr = result;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator -(const Matrix<T> &second) const
{
    return minus(second);
}

template <typename T>
Matrix<T>& Matrix<T>::operator -=(const Matrix<T> &second)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in -=");
    if (this->m != second.m && this->n != second.n)
        throw MatrixError::dimError("in -=");

    Vector<Vector<T>> result(this->m);

    for (int i=0; i < this->m; i++)
        result[i] = this->matr[i]-second.matr[i];

    this->matr = result;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T> &second) const
{
    return multiply(second);
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(const Matrix<T> &second)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in *=");
    if (this->n != second.m)
        throw MatrixError::dimError("in *=");

    Vector<Vector<T>> result(this->m);

    for (int i=0; i < this->m; i++)
    {
        Vector<T> t(second.n, (T) 0);
        result[i] = t;
        for (int j=0; j<second.n; j++)
            for (int k=0; k<this->n; k++)
                result[i][j] += this->matr[i][k] * second.matr[k][j];
    }

    this->matr = result;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator *(const T &val) const
{
    return multiply(val);
}

template <typename T>
Matrix<T>& Matrix<T>::operator *=(const T &val)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in *= T");

    Vector<Vector<T>> result(this->m);

    for (int i=0; i < this->m; i++)
    {
        Vector<T> t(this->n);
        result[i] = t;
        for (int j=0; j<this->n; j++)
            result[i][j] = this->matr[i][j]*val;
    }

    this->matr = result;

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator /(const T &val) const
{
    return divide(val);
}

template <typename T>
Matrix<T>& Matrix<T>::operator /=(const T &val)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in /= T");

    Vector<Vector<T>> result(this->m);

    for (int i=0; i < this->m; i++)
    {
        Vector<T> t(this->n);
        result[i] = t;
        for (int j=0; j<this->n; j++)
            result[i][j] = this->matr[i][j]/val;
    }

    this->matr = result;

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T> &second)
{
    Vector<Vector<T>> result(second.m);

    this->m = second.m;
    this->n = second.n;
    for (int i=0; i < this->m; i++)
        result[i] = second.matr[i];

    this->matr.clear();
    this->matr = result;

    return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator =(Matrix<T> &&second)
{
    this->matr = second.matr;
    this->m = second.m;
    this->n = second.n;

    //second.matr.setSize(0);
    //second.matr.clear();
    second.m = 0;
    second.n = 0;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator -() const
{
    Matrix<T> result(this->m, this->n);
    result.m = this->m;
    result.n = this->n;

    for (int i=0; i < result.m; i++)
        result.matr[i] = -this->matr[i];

    return result;
}

template <typename T>
Matrix<T> operator *(const T &val, const Matrix<T> &matrix)
{
    return matrix.multi(val);
}

#endif // MATRWORK_CPP
