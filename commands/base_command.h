#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H
#include "managers/main_manager.h"

class BaseCommand
{
public:    
    virtual void execute(MainManager &manager, int el_id) = 0;
};

#endif // BASE_COMMAND_H
