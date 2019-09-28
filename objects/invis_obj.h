#ifndef INVISOBJ_H
#define INVISOBJ_H
#include "base_object.h"

class InvisObj : public BaseObject
{
public:
    bool is_display()
    {
        return false;
    }
};

#endif // INVISOBJ_H
