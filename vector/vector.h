#ifndef VECTORWORK_H
#define VECTORWORK_H
#include "errors.h"
#include <iostream>
#include "base_vector.h"
#include "iterator.h"

// Vector class
template <typename T>
class Vector : public BaseVector
{
public:
    Vector();
    explicit Vector(int len);
    Vector(int len, const T &val);
    Vector(int len, T *vector);
    explicit Vector(const Vector<T> &vector);
    Vector(Vector<T> &&vector);

    ~Vector();

    void resize(const int new_size);
    void setSize(const int new_size);
    void append(const T &val);
    void remove(int i);
    void clear();
    T& first();
    const T& first() const;
    T& last();
    const T& last() const;
    T& value(int i);
    const T& value(int i) const;
    T* addres(int i) const;

    Iterator<T> begin();
    const_Iterator<T> cbegin() const;
    Iterator<T> end();
    const_Iterator<T> cend() const;

    T& operator [](int i);
    const T& operator [](int i) const;

    bool operator !=(const Vector<T> &second) const;
    bool operator ==(const Vector<T> &second) const;

    Vector<T> operator +(const Vector<T> &second) const;
    Vector<T>& operator +=(const Vector<T> &second);
    Vector<T> operator -(const Vector<T> &second) const;
    Vector<T>& operator -=(const Vector<T> &second);
    Vector<T> operator *(const T &sym) const;
    Vector<T>& operator *=(const T &sym);
    Vector<T> operator /(const T &sym) const;
    Vector<T>& operator /=(const T &sym);

    Vector<T>& operator =(const Vector<T> &second);
    Vector<T>& operator =(Vector<T> &&second);

    Vector<T> operator -() const;

    friend std::ostream& operator <<(std::ostream &s, const Vector<T> &vec)
    {
        for (int i=0; i<vec.len; i++)
            s << vec[i] << " ";
        s << std::endl;

        return s;
    }
private:
    T* vec;

    Vector<T> plus(const Vector<T> &second) const;
    Vector<T> minus(const Vector<T> &second) const;
    Vector<T> multiply(const T &sym) const;
    Vector<T> divide(const T &sym) const;
};

template <typename T>
Vector<T> operator *(T& sym, const Vector<T> &vector);

#include "vector.hpp"
#endif // VECTORWORK_H
