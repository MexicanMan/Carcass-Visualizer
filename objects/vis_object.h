#ifndef VISOBJECT_H
#define VISOBJECT_H
#include "base_object.h"

class VisObject : public BaseObject
{
public:
    bool is_display()
    {
        return true;
    }
};

#endif // VISOBJECT_H
