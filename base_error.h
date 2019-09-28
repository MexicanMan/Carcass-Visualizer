#ifndef BASE_ERRORS_H
#define BASE_ERRORS_H
#include <exception>
#include <string>

class BaseError : public std::exception
{
protected:
    std::string where;
public:
    BaseError(const char *wh) { this->where = wh; }

    virtual ~BaseError()
    {
        where.clear();
    }

    virtual const char* what()
    {
        return "Unknown error!";
    }
};

#endif // BASE_ERRORS_H
