#ifndef BASE_MATRWORK_HPP
#define BASE_MATRWORK_HPP
#include "base_matrix.h"

inline BaseMatrix::BaseMatrix():m(0), n(0) {}

inline BaseMatrix::BaseMatrix(int m, int n):m(m), n(n) {}

// Rows number
inline int BaseMatrix::length_m() const
{
    return this->m;
}

// Columns number
inline int BaseMatrix::length_n() const
{
    return this->n;
}

inline bool BaseMatrix::isEmpty() const
{
    if (this->m && this->n)
        return false;
    else
        return true;
}

#endif // BASE_MATRWORK_HPP
