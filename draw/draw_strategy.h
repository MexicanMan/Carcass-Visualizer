#ifndef DRAW_STRATEGY_H
#define DRAW_STRATEGY_H
#include "model/model.h"
#include "scene/scene_object.h"
#include "camera/camera.h"

class DrawStrategy
{
public:
    DrawStrategy() { }

    virtual ~DrawStrategy() { }

    virtual void drawObj(SceneObject &so, BaseCamera &cam) = 0;
    virtual void clearScene() = 0;
};

#endif // DRAW_STRATEGY_H
