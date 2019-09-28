#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H
#include "base_manager.h"
#include "draw/qt_draw.h"
#include "scene/scene.h"

class DrawManager : public BaseManager
{
private:
    DrawStrategy *ds;
public:
    DrawManager()
    {
        this->ds = nullptr;
    }
    DrawManager(DrawStrategy *strat)
    {
        if (ds != nullptr)
            delete ds;
        this->ds = strat;
    }

    ~DrawManager()
    {
        delete ds;
    }

    void setStrategy(DrawStrategy *strat)
    {
        this->ds = strat;
    }

    void drawScene(Scene &scene, BaseCamera &cam);
    void clearScene();
};

#endif // DRAW_MANAGER_H
