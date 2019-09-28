#include "model.h"

Model::Model()
{ }

Model::~Model()
{
    delete this->name;
}

int Model::dotsNum()
{
    return this->dots.length();
}

int Model::linesNum()
{
    return this->lines.length();
}

const char* Model::getName()
{
    return this->name;
}

Point& Model::getDot(int i)
{
    return this->dots[i];
}

Point* Model::getDotAddr(int i)
{
    return this->dots.addres(i);
}

Edge& Model::getLine(int i)
{
    return this->lines[i];
}

Point Model::findCenter()
{
    double x = (getMaxX()+getMinX())/2;
    double y = (getMaxY()+getMinY())/2;
    double z = (getMaxZ()+getMinZ())/2;

    return Point(x, y, z);
}

void Model::addDot(Point p)
{
    this->dots.append(p);
}

void Model::addLine(int beg, int end)
{
    if (beg >= dotsNum() || end >= dotsNum() || beg < 0 || end < 0)
        throw ModelError::EdgeIndexError("in addLine()");

    Edge l(getDotAddr(beg), getDotAddr(end));
    this->lines.append(l);
}

void Model::setName(const char *name)
{
    this->name = name;
}

double Model::getMaxX()
{
    double max = this->dots[0].X();
    for (int i=1; i < this->dots.length(); i++)
    {
        if (max < this->dots[i].X())
            max = this->dots[i].X();
    }

    return max;
}

double Model::getMaxY()
{
    double max = this->dots[0].Y();
    for (int i=1; i < this->dots.length(); i++)
    {
        if (max < this->dots[i].Y())
            max = this->dots[i].Y();
    }

    return max;
}

double Model::getMaxZ()
{
    double max = this->dots[0].Z();
    for (int i=1; i < this->dots.length(); i++)
    {
        if (max < this->dots[i].Z())
            max = this->dots[i].Z();
    }

    return max;
}

double Model::getMinX()
{
    double min = this->dots[0].X();
    for (int i=1; i < this->dots.length(); i++)
    {
        if (min > this->dots[i].X())
            min = this->dots[i].X();
    }

    return min;
}

double Model::getMinY()
{
    double min = this->dots[0].Y();
    for (int i=1; i < this->dots.length(); i++)
    {
        if (min > this->dots[i].Y())
            min = this->dots[i].Y();
    }

    return min;
}

double Model::getMinZ()
{
    double min = this->dots[0].Z();
    for (int i=1; i < this->dots.length(); i++)
    {
        if (min > this->dots[i].Z())
            min = this->dots[i].Z();
    }

    return min;
}
