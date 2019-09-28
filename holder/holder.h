#ifndef HOLDER_H
#define HOLDER_H

template <typename T>
class Holder
{
private:
    T *ptr;
public:
    Holder(T *p) : ptr(p) { }
    ~Holder() { delete ptr; }
    Holder<T>& operator =(Holder<T> &) = delete;

    T& operator *() const { return *ptr; }
    T* operator ->() const { return ptr; }
};

#endif // HOLDER_H
