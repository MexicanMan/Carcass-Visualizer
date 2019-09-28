#ifndef COMMANDS_H
#define COMMANDS_H
#define _USE_MATH_DEFINES
#include "base_command.h"
#include <cmath>
//#include "math.h"

class LoadMdlCommand : public BaseCommand
{
private:
    const char* filename;
    LoadStrategy *strategy;
public:
    LoadMdlCommand(const char *name, LoadStrategy *strat)
    {
        this->filename = name;
        this->strategy = strat;
    }

    ~LoadMdlCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.addModel(this->filename, this->strategy);
    }
};

class DelMdlCommand : public BaseCommand
{
public:
    DelMdlCommand() { }

    ~DelMdlCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.delModel(el_id);
    }
};

class AddCamCommand : public BaseCommand
{
private:
    double x;
    double y;
    double z;
public:
    AddCamCommand(double x, double y, double z) : x(x), y(y),
    z(z) { }

    ~AddCamCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.addCam(this->x, this->y, this->z);
    }
};

class DelCamCommand : public BaseCommand
{
public:
    DelCamCommand() { }

    ~DelCamCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.delCam(el_id);
    }
};

class DrawCommand : public BaseCommand
{
private:
    DrawStrategy *strategy;
public:
    DrawCommand(DrawStrategy *strat)
    {
        this->strategy = strat;
    }

    ~DrawCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.drawScene(this->strategy, el_id);
    }
};

class MoveMdlCommand : public BaseCommand
{
private:
    double shift_x;
    double shift_y;
    double shift_z;
public:
    MoveMdlCommand(double shx, double shy, double shz) : shift_x(shx),
        shift_y(shy), shift_z(shz) { }

    ~MoveMdlCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.moveModel(el_id, shift_x, shift_y, shift_z);
    }
};

class RotateMdlCommand : public BaseCommand
{
private:
    double deg_x;
    double deg_y;
    double deg_z;
public:
    RotateMdlCommand(double dx, double dy, double dz)
    {
        deg_x = dx*M_PI/180;
        deg_y = dy*M_PI/180;
        deg_z = dz*M_PI/180;
    }

    ~RotateMdlCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.rotateModel(el_id, this->deg_x, this->deg_y, this->deg_z);
    }
};

class ScaleMdlCommand : public BaseCommand
{
private:
    double k;
public:
    ScaleMdlCommand(double k) : k(k)
    { }

    ~ScaleMdlCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.scaleModel(el_id, this->k);
    }
};

class MoveCamCommand : public BaseCommand
{
private:
    double shift_x;
    double shift_y;
    double shift_z;
public:
    MoveCamCommand(double shx, double shy, double shz) : shift_x(shx),
        shift_y(shy), shift_z(shz) { }

    ~MoveCamCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.moveCam(el_id, this->shift_x, this->shift_y, this->shift_z);
    }
};

class RotateCamCommand : public BaseCommand
{
private:
    double deg_x;
    double deg_y;
    double deg_z;
public:
    RotateCamCommand(double dx, double dy, double dz)
    {
        deg_x = dx*M_PI/180;
        deg_y = dy*M_PI/180;
        deg_z = dz*M_PI/180;
    }

    ~RotateCamCommand() { }

    void execute(MainManager &manager, int el_id)
    {
        manager.rotateCam(el_id, this->deg_x, this->deg_y, this->deg_z);
    }
};

#endif // COMMANDS_H
