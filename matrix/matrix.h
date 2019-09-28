#ifndef MATRWORK_H
#define MATRWORK_H
#include "vector/vector.h"
#include "base_matrix.h"

// Matrix class
template <typename T>
class Matrix : public BaseMatrix
{
public:
    Matrix();
    Matrix(int m, int n);
    Matrix(int m, int n, const T &val);
    Matrix(int m, const Vector<T> &vector);
    Matrix(int m, int n, void *mat);
    explicit Matrix(const Matrix<T> &matrix);
    Matrix(Matrix<T> &&matrix);

    ~Matrix();

    void append_row(const Vector<T> &vec);
    void append_column(const Vector<T> &vec);

    void set_row(int i, const Vector<T> &vec);
    void set_column(int i, const Vector<T> &vec);

    T& value(int i, int j);
    const T& value(int i, int j) const;
    const T* addres(int i, int j) const;

    double determinant() const;
    bool isDegenerate() const;
    Matrix<T>& makeSingle();
    Matrix<T>& transposeSquare();

    Vector<T>& operator [](int i);
    const Vector<T>& operator [](int i) const;
    T& operator ()(int i, int j);
    const T& operator ()(int i, int j) const;
    bool operator !=(const Matrix<T> &second) const;
    bool operator ==(const Matrix<T> &second) const;
    Matrix<T> operator +(const Matrix<T> &second) const;
    Matrix<T>& operator +=(const Matrix<T> &second);
    Matrix<T> operator -(const Matrix<T> &second) const;
    Matrix<T>& operator -=(const Matrix<T> &second);
    Matrix<T> operator *(const Matrix<T> &second) const;
    Matrix<T>& operator *=(const Matrix<T> &second);
    Matrix<T> operator *(const T &val) const;
    Matrix<T>& operator *=(const T &val);
    Matrix<T> operator /(const T &val) const;
    Matrix<T>& operator /=(const T &val);
    Matrix<T>& operator =(const Matrix<T> &second);
    Matrix<T>& operator =(Matrix<T> &&second);
    Matrix<T> operator -() const;

    friend std::ostream& operator <<(std::ostream &s, const Matrix<T> &matr)
    {
        for (int i=0; i<matr.m; i++)
        {
            for (int j=0; j<matr.n; j++)
                s << matr[i][j] << " ";
            s << std::endl;
        }

        return s;
    }
private:
    Vector<Vector<T>> matr;

    Matrix<T> makeUpTriangle() const;
    Matrix<T> makeDiagonal() const;

    Matrix<T> plus(const Matrix<T> &second) const;
    Matrix<T> minus(const Matrix<T> &second) const;
    Matrix<T> multiply(const Matrix<T> &second) const;
    Matrix<T> multiply(const T &val) const;
    Matrix<T> divide(const T &val) const;
};

template <typename T>
Matrix<T> operator *(const T &val, const Matrix<T> &matrix);

#include "matrix.hpp"
#endif // MATRWORK_H
