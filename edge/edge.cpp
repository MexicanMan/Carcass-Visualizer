#include "edge.h"

Edge::Edge()
{
    this->beg = this->end = nullptr;
}

Edge::Edge(const Edge &edg)
{
    this->beg = edg.beg;
    this->end = edg.end;
}

Edge::Edge(Edge &&edg)
{
    this->beg = edg.beg;
    this->end = edg.end;
}

void Edge::setBeg(Point *beg)
{
    this->beg = beg;
}

void Edge::setEnd(Point *end)
{
    this->end = end;
}

Point Edge::Beg() const
{
    return *this->beg;
}

Point Edge::End() const
{
    return *this->end;
}

Edge& Edge::operator =(const Edge &edg)
{
    this->beg = edg.beg;
    this->end = edg.end;

    return *this;
}

Edge& Edge::operator =(Edge &&edg)
{
    this->beg = edg.beg;
    this->end = edg.end;

    return *this;
}
