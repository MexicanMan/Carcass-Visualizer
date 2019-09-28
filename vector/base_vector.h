#ifndef BASE_VECTORWORK_H
#define BASE_VECTORWORK_H

// Base vector class
class BaseVector
{
protected:
    int len;
    int allocated;
    int step = 2;
public:
    int length() const;
    bool isEmpty() const;
};

#include "base_vector.hpp"

#endif // BASE_VECTORWORK_H
