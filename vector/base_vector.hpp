#ifndef BASE_VECTORWORK_HPP
#define BASE_VECTORWORK_HPP
#include "base_vector.h"

// Real vector length
inline int BaseVector::length() const
{
    return this->len;
}

// Vector emptiness check
inline bool BaseVector::isEmpty() const
{
    if (this->len)
        return false;
    else
        return true;
}

#endif // BASE_VECTORWORK_HPP
