#ifndef BASE_MODEL_H
#define BASE_MODEL_H
#include "objects/vis_object.h"
#include "vector/vector.h"
#include "point/point.h"
#include "edge/edge.h"

class BaseModel : public VisObject
{
protected:
    Vector<Point> dots;
    Vector<Edge> lines;
    const char* name;
public:
    virtual ~BaseModel() { }

    virtual int dotsNum() = 0;
    virtual int linesNum() = 0;

    virtual const char* getName() = 0;
    virtual Point& getDot(int i) = 0;
    virtual Point* getDotAddr(int i) = 0;
    virtual Edge& getLine(int i) = 0;
    virtual Point findCenter() = 0;

    virtual void addDot(Point p) = 0;
    virtual void addLine(int start, int end) = 0;
    virtual void setName(const char *name) = 0;
};

#endif // BASE_MODEL_H
