#ifndef ITERATOR_CPP
#define ITERATOR_CPP
#include "iterator.h"

template <typename T>
BaseIterator<T>::BaseIterator(Vector<T> &vec, int curr)
{
    this->iter = &vec;
    this->curr = curr;
}

template <typename T>
BaseIterator<T>::BaseIterator(const BaseIterator<T> &it)
{
    this->iter = it.iter;
    this->curr = it.curr;
}

template <typename T>
BaseIterator<T>::~BaseIterator()
{
    this->iter = nullptr;
    this->curr = 0;
}

template <typename T>
BaseIterator<T>& BaseIterator<T>::operator ++()
{
    ++(this->curr);

    return *this;
}

template <typename T>
BaseIterator<T> BaseIterator<T>::operator ++(int)
{
    BaseIterator<T> t(*this);
    this->operator ++();

    return t;
}

template <typename T>
BaseIterator<T> BaseIterator<T>::operator +(int n) const
{
    BaseIterator<T> t(*this);
    t += n;

    return t;
}

template <typename T>
BaseIterator<T>& BaseIterator<T>::operator +=(int n)
{
    if (n >= 0)
        while (n--)
            ++(*this);
    else
        while (n++)
            --(*this);

    return *this;
}

template <typename T>
BaseIterator<T>& BaseIterator<T>::operator --()
{
    --(this->curr);

    return *this;
}

template <typename T>
BaseIterator<T> BaseIterator<T>::operator --(int)
{
    BaseIterator<T> t(*this);
    this->operator --();

    return t;
}

template <typename T>
BaseIterator<T> BaseIterator<T>::operator -(int n) const
{
    BaseIterator<T> t(*this);
    t -= n;

    return t;
}

template <typename T>
BaseIterator<T>& BaseIterator<T>::operator -=(int n)
{
    if (n > 0)
        while (n--)
            ++(*this);
    else
        while (n++)
            --(*this);

    return *this;
}

template <typename T>
BaseIterator<T>& BaseIterator<T>::operator =(const BaseIterator &it)
{
    this->iter = it.iter;
    this->curr = it.curr;

    return *this;
}

template <typename T>
bool BaseIterator<T>::operator !=(const BaseIterator<T>& it) const
{
    if (this->iter != it.iter)
        throw IteratorError::cmpIterErr("in !=");

    return this->curr != it.curr;
}

template <typename T>
bool BaseIterator<T>::operator ==(const BaseIterator<T>& it) const
{
    if (this->iter != it.iter)
        throw IteratorError::cmpIterErr("in ==");

    return this->curr == it.curr;
}

template <typename T>
Iterator<T>::Iterator(Vector<T> &vec, int curr):BaseIterator<T>(vec, curr) {}

template <typename T>
Iterator<T>::Iterator(const Iterator<T> &it):BaseIterator<T>(it) {}

template <typename T>
T& Iterator<T>::operator *()
{
    return this->iter->operator [](this->curr);
}

template <typename T>
T* Iterator<T>::operator ->()
{
    return this->iter->addres(this->curr);
}

template <typename T>
const_Iterator<T>::const_Iterator(Vector<T> &vec, int curr):BaseIterator<T>(vec, curr) {}

template <typename T>
const_Iterator<T>::const_Iterator(const const_Iterator<T> &it):BaseIterator<T>(it) {}

template <typename T>
const T& const_Iterator<T>::operator *()
{
    return this->iter->operator [](this->curr);
}

template <typename T>
const T* const_Iterator<T>::operator ->()
{
    return this->iter->addres(this->curr);
}

#endif // ITERATOR_CPP
