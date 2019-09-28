#ifndef ITERATOR_H
#define ITERATOR_H
#include "errors.h"

template <typename T> class Vector;

// Base class for matrix iteration
template <typename T>
class BaseIterator
{
protected:
    int curr;
    Vector<T> *iter;
    BaseIterator(Vector<T> &vec, int curr = 0);
public:
    BaseIterator(const BaseIterator<T> &it);

    virtual ~BaseIterator();

    BaseIterator operator ++(int);
    BaseIterator& operator ++();
    BaseIterator operator +(int n) const;
    BaseIterator& operator +=(int n);
    BaseIterator operator --(int);
    BaseIterator& operator --();
    BaseIterator operator -(int n) const;
    BaseIterator& operator -=(int n);
    BaseIterator& operator =(const BaseIterator &it);

    bool operator != (const BaseIterator &it) const;
    bool operator == (const BaseIterator &it) const;

};

// Iterator for matrix
template <typename T>
class Iterator : public BaseIterator<T>
{
private:
    Iterator(Vector<T> &vec, int curr = 0);
public:
    Iterator(const Iterator<T> &it);

    T& operator *();
    T* operator ->();

    friend class Vector<T>;
};

// Iterator class for constant matrix
template <typename T>
class const_Iterator : public BaseIterator<T>
{
private:
    const_Iterator(Vector<T> &vec, int curr = 0);
public:
    const_Iterator(const const_Iterator<T> &it);

    const T& operator *();
    const T* operator ->();

    friend class Vector<T>;
};

#include "iterator.hpp"

#endif // ITERATOR_H
