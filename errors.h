#ifndef ERRORS_H
#define ERRORS_H
#include "base_error.h"

namespace VectorError
{

class MemAllocError: public BaseError
{
public:
    MemAllocError(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Memory allocation error! ") + this->where).c_str();
    }
};

class rangeError: public BaseError
{
public:
    rangeError(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Index is out of range! ") + this->where).c_str();
    }
};

class emptyError : public BaseError
{
public:
    emptyError(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Object is empty! ") + this->where).c_str();
    }
};

class lenError : public BaseError
{
public:
    lenError(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Length of two vectors doesn't match! ") + this->where).c_str();
    }
};

}

namespace MatrixError
{

class DegMatrix : public BaseError
{
public:
    DegMatrix(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Matrix is degenerated! ") + this->where).c_str();
    }
};

class dimError : public BaseError
{
public:
    dimError(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Dimensions of two matrixes doesn't match! ") + this->where).c_str();
    }
};

class notSquare : public BaseError
{
public:
    notSquare(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Matrix isn't square! ") + this->where).c_str();
    }
};

}

namespace IteratorError
{

class cmpIterErr : public BaseError
{
public:
    cmpIterErr(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Diffrent type of iterators! ") + this->where).c_str();
    }
};

}

namespace FileError
{

class OpenFileError : public BaseError
{
public:
    OpenFileError(const char* wh):BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Can't open the file! ") + this->where).c_str();
    }
};

class ReadFileError : public BaseError
{
public:
    ReadFileError(const char* wh) : BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Can't read the file! Wrong data! ") + this->where).c_str();
    }
};

}

namespace ModelError
{

class EdgeIndexError : public BaseError
{
public:
    EdgeIndexError(const char* wh) : BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("Point indexes doesn't correct! ") + this->where).c_str();
    }
};

}

namespace SceneError
{

class WrongCamIndex : public BaseError
{
public:
    WrongCamIndex(const char* wh) : BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("No camera with such index! ") + this->where).c_str();
    }
};

class WrongMdlIndex : public BaseError
{
public:
    WrongMdlIndex(const char* wh) : BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("No model with such index! ") + this->where).c_str();
    }
};

}

namespace CompositeError
{

class UnsupportedOperation : public BaseError
{
public:
    UnsupportedOperation(const char* wh) : BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("This operation doesn't support! ") + this->where).c_str();
    }
};

}

namespace SceneObjError
{

class NoModelError : public BaseError
{
public:
    NoModelError(const char* wh) : BaseError(wh) {}

    virtual const char* what()
    {
        return std::string(std::string("No model! ") + this->where).c_str();
    }
};


}

#endif // ERRORS_H
