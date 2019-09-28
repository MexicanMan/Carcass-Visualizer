#ifndef COMPOSITE_OBJECT_H
#define COMPOSITE_OBJECT_H
#include "base_object.h"
#include "vector/vector.h"

class CompositeObject : public BaseObject
{
private:
    Vector<BaseObject*> objects;
public:
    void addObj(BaseObject *obj)
    {
        objects.append(obj);
    }

    void removeObj(int i)
    {
        objects.remove(i);
    }

    BaseObject* getChild(int i)
    {
        return objects[i];
    }

    BaseObject* operator [](int i)
    {
        return objects[i];
    }

    ~CompositeObject()
    { }

    Iterator<BaseObject*> begin()
    {
        return this->objects.begin();
    }

    Iterator<BaseObject*> end()
    {
        return this->objects.end();
    }
};

#endif // COMPOSITE_OBJECT_H
