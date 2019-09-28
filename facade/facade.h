#ifndef FACADE_H
#define FACADE_H
#include "commands/commands.h"
#include "managers/main_manager.h"
#include "objects/base_object.h"
#include "errors.h"

class Facade
{
private:
    MainManager manager;
    const char *error_message;
public:
    Facade();
    ~Facade();

    int CallComand(BaseCommand &comm, int el_id);
    const char* GetError();
};

#endif // FACADE_H
