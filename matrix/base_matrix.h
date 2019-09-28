#ifndef BASE_MATRWORK_H
#define BASE_MATRWORK_H

// Base matrix class
class BaseMatrix
{
protected:
    int m;
    int n;

public:
    BaseMatrix();
    BaseMatrix(int m, int n);
    BaseMatrix(const BaseMatrix &matrix) = delete;

    virtual ~BaseMatrix() {}

    int length_m() const;
    int length_n() const;
    bool isEmpty() const;
};

#include "base_matrix.hpp"

#endif // BASE_MATRWORK_H
