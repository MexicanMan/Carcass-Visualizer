#ifndef EDGE_H
#define EDGE_H
#include "point/point.h"
#include "objects/vis_object.h"

// Edge class
class Edge : public VisObject
{
private:
    Point *beg;
    Point *end;

public:
    Edge();
    Edge(Point *beg, Point *end) : beg(beg), end(end) { }
    Edge(const Edge &edg);
    Edge(Edge &&edg);

    void setBeg(Point *beg);
    void setEnd(Point *end);

    Point Beg() const;
    Point End() const;

    Edge& operator =(const Edge &edg);
    Edge& operator =(Edge &&edg);
};

#endif // EDGE_H
