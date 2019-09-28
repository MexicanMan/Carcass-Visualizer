#ifndef LOAD_STRATEGY_H
#define LOAD_STRATEGY_H
#include "objects/base_object.h"
#include "model/model.h"
#include "errors.h"

class LoadStrategy
{
public:
    LoadStrategy() { }

    virtual ~LoadStrategy() { }

    virtual int Load(const char *filename, BaseModel &mdl) = 0;
};

#endif // LOAD_STRATEGY_H
