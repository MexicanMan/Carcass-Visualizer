#ifndef MODEL_H
#define MODEL_H
#include "base_model.h"
#include "errors.h"

class Model : public BaseModel
{
private:
    double getMaxX();
    double getMaxY();
    double getMaxZ();

    double getMinX();
    double getMinY();
    double getMinZ();

    Point *getDotAddr(int i);
public:
    Model();

    ~Model();

    int dotsNum();
    int linesNum();

    const char* getName();
    Point& getDot(int i);
    Edge& getLine(int i);
    Point findCenter();

    void addDot(Point p);
    void addLine(int beg, int end);
    void setName(const char *name);
};

#endif // MODEL_H
