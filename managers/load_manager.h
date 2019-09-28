#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H
#include "base_manager.h"
#include "load/file_load.h"

class LoadManager : public BaseManager
{
private:
    LoadStrategy *ls;
public:
    LoadManager()
    {
        this->ls = new FileLoad();
    }
    LoadManager(LoadStrategy *strat)
    {
        delete ls;
        this->ls = strat;
    }

    ~LoadManager()
    {
        delete ls;
    }

    void setStrategy(LoadStrategy *strat)
    {
        this->ls = strat;
    }

    BaseObject* loadObj(const char *filename)
    {
        BaseModel *mdl = new Model();
        this->ls->Load(filename, *mdl);

        return (BaseObject*) mdl;
    }
};

#endif // LOAD_MANAGER_H
