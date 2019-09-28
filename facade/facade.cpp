#include "facade.h"

Facade::Facade()
{
    this->error_message = "";
}

Facade::~Facade()
{ }

int Facade::CallComand(BaseCommand &comm, int el_id)
{
    try
    {
        comm.execute(manager, el_id);
    }
    catch(BaseError &err)
    {
        this->error_message = err.what();
        return -1;
    }

    return 0;
}

const char* Facade::GetError()
{
    return this->error_message;
}
