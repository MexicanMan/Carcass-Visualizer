#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include "vector/iterator.h"
#include "errors.h"

class BaseObject
{
public:
    virtual void addObj(BaseObject* obj)
    {
        throw CompositeError::UnsupportedOperation("in addObj()");
    }

    virtual void removeObj(int i)
    {
        throw CompositeError::UnsupportedOperation("in removeObj()");
    }

    virtual BaseObject* getChild(int i)
    {
        throw CompositeError::UnsupportedOperation("in getChild()");
    }

    virtual BaseObject* operator [](int i)
    {
        throw CompositeError::UnsupportedOperation("in []");
    }

    virtual ~BaseObject() { }

    virtual bool is_display()
    {
        throw CompositeError::UnsupportedOperation("in is_display()");
    }

    virtual Iterator<BaseObject*> begin()
    {
        throw CompositeError::UnsupportedOperation("in begin()");
    }

    virtual Iterator<BaseObject*> end()
    {
        throw CompositeError::UnsupportedOperation("in end()");
    }
};

#endif // BASE_OBJECT_H
