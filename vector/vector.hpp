#ifndef VECTORWORK_CPP
#define VECTORWORK_CPP
#include "vector.h"
//#include <cstring>

// Vector addition
template <typename T>
Vector<T> Vector<T>::plus(const Vector<T> &second) const
{
    if (this->len != second.len)
        throw VectorError::lenError("in plus();");

    Vector<T> result(this->len);
    result.len = this->len;
    result.allocated = this->len;
    for (int i=0; i < this->len; i++)
        result.vec[i] = this->vec[i]+second.vec[i];

    return result;
}

// Vector subtraction
template <typename T>
Vector<T> Vector<T>::minus(const Vector<T> &second) const
{
    if (this->len != second.len)
        throw VectorError::lenError("in minus()");

    Vector<T> result(this->len);
    result.len = this->len;
    result.allocated = this->len;
    for (int i=0; i < this->len; i++)
        result.vec[i] = this->vec[i]-second.vec[i];

    return result;
}

// Vector multiplication by an element (number)
template <typename T>
Vector<T> Vector<T>::multiply(const T &val) const
{
    Vector<T> result(this->len);
    result.len = this->len;
    result.allocated = this->len;
    for (int i=0; i < this->len; i++)
        result.vec[i] = this->vec[i]*val;

    return result;
}

// Vector division by an element (number)
template <typename T>
Vector<T> Vector<T>::divide(const T &val) const
{
    Vector<T> result(this->len);
    result.len = this->len;
    result.allocated = this->len;
    for (int i=0; i < this->len; i++)
        result.vec[i] = this->vec[i]/val;

    return result;
}

// Empty constructor
template <typename T>
Vector<T>::Vector()
{
    this->vec = new T[1]();
    this->len = 0;
    this->allocated = 1;
}

// Constructor allocating memory
template <typename T>
Vector<T>::Vector(int len)
{
    this->vec = new T[len]();
    if (!this->vec)
        throw VectorError::MemAllocError("in Vecor(int)");

    this->len = len;
    this->allocated = len;
}

// Constructor allocating memory and filling vector with an element
template <typename T>
Vector<T>::Vector(int len, const T &val)
{
    this->vec = new T[len];
    if (!this->vec)
        throw VectorError::MemAllocError("in Vector(int, T&)");
    for (int i=0; i < len; i++)
        this->vec[i] = val;

    this->len = len;
    this->allocated = len;
}

// Constructor converting an array to the vector
template <typename T>
Vector<T>::Vector(int len, T *vector)
{
    this->vec = new T[len];
    if (!this->vec)
        throw VectorError::MemAllocError("in Vector(int, T*)");

    for (int i=0; i < len; i++)
        this->vec[i] = vector[i];

    this->len = len;
    this->allocated = len;
}

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector<T> &vector)
{
    this->vec = new T[vector.allocated];
    if (!this->vec)
        throw VectorError::MemAllocError("in copy constructor");

    this->len = vector.len;
    this->allocated = vector.allocated;
    for (int i = 0; i < this->len; i++)
        this->vec[i] = vector.vec[i];
    //memcpy(this->vec, vector.vec, this->len*sizeof(T));
}

// Move constructor
template <typename T>
Vector<T>::Vector(Vector<T> &&vector)
{
    this->vec = vector.vec;
    this->len = vector.len;
    this->allocated = vector.allocated;

    vector.vec = nullptr;
    vector.len = 0;
    vector.allocated = 0;
}

// Destructor
template <typename T>
Vector<T>::~Vector()
{
    if (this->vec)
        delete [] this->vec;

    this->vec = nullptr;
    this->len = 0;
    this->allocated = 0;
}

///
//
template <typename T>
void Vector<T>::resize(const int new_size)
{
    int l = (this->len < new_size) ? (this->len) : (new_size);

    Vector<T> tmp(*this);
    if (this->vec)
        delete [] this->vec;
    this->allocated = new_size;
    this->vec = new T[new_size]();
    if (!this->vec)
        throw VectorError::MemAllocError("in resize()");

    for(int i = 0; i<l; i++)
        this->vec[i] = tmp.vec[i];
}

//
template <typename T>
void Vector<T>::setSize(const int new_size)
{
    clear();
    this->allocated = new_size;
    this->len = new_size;

    this->vec = new T[new_size]();
    if (!this->vec)
        throw VectorError::MemAllocError("in setSize()");
}

//
template <typename T>
void Vector<T>::append(const T &val)
{
    if (this->allocated <= this->len)
    {
        this->allocated *= this->step;
        this->resize(this->allocated);
    }

    this->vec[this->len] = val;
    this->len++;
}

template <typename T>
void Vector<T>::remove(int i)
{
    memmove(this->vec+i, this->vec+i+1, (this->len-i-1)*sizeof(T));
    this->len--;
}

//
template <typename T>
void Vector<T>::clear()
{
    if (this->vec)
        delete this->vec;

    this->vec = nullptr;
    this->len = 0;
    this->allocated = 0;
}

// First element
template <typename T>
T& Vector<T>::first()
{
    if (this->isEmpty())
        throw VectorError::emptyError("in first()");

    return this->vec[0];
}

// First element for const vector
template <typename T>
const T& Vector<T>::first() const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in first() c");

    return this->vec[0];
}

// Last element
template <typename T>
T& Vector<T>::last()
{
    if (this->isEmpty())
        throw VectorError::emptyError("in last()");

    return this->vec[this->len-1];
}

// Last element for const vector
template <typename T>
const T& Vector<T>::last() const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in last() c");

    return this->vec[this->len-1];
}

// Vector element value
template <typename T>
T& Vector<T>::value(int i)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in value");
    if (i < 0 || i >= this->len)
        throw VectorError::rangeError("in value");

    return this->vec[i];
}

// Vector element value for const vector
template <typename T>
const T& Vector<T>::value(int i) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in value() c");
    if (i < 0 || i >= this->len)
        throw VectorError::rangeError("in value() c");

    return this->vec[i];
}

template <typename T>
T *Vector<T>::addres(int i) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in addres()");
    if (i < 0 || i >= this->len)
        throw VectorError::rangeError("in addres()");

    return this->vec+i;
}

template <typename T>
Iterator<T> Vector<T>::begin()
{
    return Iterator<T>(*this, 0);
}

template <typename T>
const_Iterator<T> Vector<T>::cbegin() const
{
    return const_Iterator<T>(const_cast<Vector&>(*this), 0);
}

template <typename T>
Iterator<T> Vector<T>::end()
{
    return Iterator<T>(*this, this->length());
}

template <typename T>
const_Iterator<T> Vector<T>::cend() const
{
    return const_Iterator<T>(const_cast<Vector&>(*this), this->length());
}

template <typename T>
T& Vector<T>::operator [](int i)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in []");
    if (i < 0 || i >= this->len)
        throw VectorError::rangeError("in []");

    return this->vec[i];
}

template <typename T>
const T& Vector<T>::operator [](int i) const
{
    if (this->isEmpty())
        throw VectorError::emptyError("in []");
    if (i < 0 || i >= this->len)
        throw VectorError::rangeError("in []");

    return this->vec[i];
}

template <typename T>
bool Vector<T>::operator !=(const Vector<T> &second) const
{
    bool flag = true;
    if (this->len == second.len)
    {
        flag = false;
        for (int i=0; i<this->len && !flag; i++)
            if (this->vec[i] != second.vec[i])
                flag = true;
    }

    return flag;
}

template <typename T>
bool Vector<T>::operator ==(const Vector<T> &second) const
{
    bool flag = false;
    if (this->len == second.len)
    {
        flag = true;
        for (int i=0; i<this->len && flag; i++)
            if (this->vec[i] != second.vec[i])
                flag = false;
    }

    return flag;
}

template <typename T>
Vector<T> Vector<T>::operator +(const Vector<T> &second) const
{
    return plus(second);
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const Vector<T> &second)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in +=");
    if (this->len != second.len)
        throw VectorError::lenError("int +=");

    T *result = new T[this->allocated];
    if (!result)
        throw VectorError::MemAllocError("in +=");

    for (int i=0; i < this->len; i++)
        result[i] = this->vec[i]+second.vec[i];

    if (this->vec)
        delete [] this->vec;
    this->vec = result;

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator -(const Vector<T> &second) const
{
    return minus(second);
}

template <typename T>
Vector<T>& Vector<T>::operator -=(const Vector<T> &second)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in -=");
    if (this->len != second.len)
        throw VectorError::lenError("in -=");

    T *result = new T[this->allocated];
    if (!result)
        throw VectorError::MemAllocError("in -=");

    for (int i=0; i < this->len; i++)
        result[i] = this->vec[i]-second.vec[i];

    if (this->vec)
        delete [] this->vec;
    this->vec = result;

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator *(const T &sym) const
{
    return multiply(sym);
}

template <typename T>
Vector<T>& Vector<T>::operator *=(const T &sym)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in *=");

    T *result = new T[this->allocated];
    if (!result)
        throw VectorError::MemAllocError("in *=");

    for (int i=0; i < this->len; i++)
        result[i] = this->vec[i]*sym;

    if (this->vec)
        delete [] this->vec;
    this->vec = result;

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator /(const T &sym) const
{
    return divide(sym);
}

template <typename T>
Vector<T>& Vector<T>::operator /=(const T &sym)
{
    if (this->isEmpty())
        throw VectorError::emptyError("in /=");

    T *result = new T[this->allocated];
    if (!result)
        throw VectorError::MemAllocError("in /=");

    for (int i=0; i < this->len; i++)
        result[i] = this->vec[i]/sym;

    if (this->vec)
        delete [] this->vec;
    this->vec = result;

    return *this;
}

template <typename T>
Vector<T>&  Vector<T>::operator =(const Vector<T> &second)
{
    T *result = new T[second.allocated];
    if (!result)
        throw VectorError::MemAllocError("in =");

    this->len = second.len;
    this->allocated = second.allocated;
    for (int i=0; i < this->len; i++)
        result[i] = second.vec[i];

    if (this->vec)
        delete [] this->vec;
    this->vec = result;

    return *this;
}

template <typename T>
Vector<T>&  Vector<T>::operator =(Vector<T> &&second)
{
    if (this->vec)
        delete [] this->vec;

    this->vec = second.vec;
    this->len = second.len;
    this->allocated = second.allocated;

    second.vec = nullptr;
    second.len = 0;
    second.allocated = 0;

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator -() const
{
    Vector<T> result(this->len);
    result.len = this->len;

    for (int i=0; i < result.len; i++)
        result.vec[i] = -this->vec[i];

    return result;
}

template <typename T>
Vector<T> operator *(T sym, const Vector<T> &vector)
{
    return vector.multi(sym);
}

#endif // VECTORWORK_CPP
