#ifndef TRANSFORM_MANAGER_H
#define TRANSFORM_MANAGER_H
#include "base_manager.h"
#include "scene/scene.h"

class TransformManager : public BaseManager
{
public:
    TransformManager();
    ~TransformManager() { }

    void RotateModel(int i, Scene &sc, double deg_x, double deg_y, double deg_z);
    void MoveModel(int i, Scene &sc, double shx, double shy, double shz);
    void ScaleModel(int i, Scene &sc, double k);
    void MoveCam(int i, Scene &sc, double shx, double shy, double shz);
    void RotateCam(int i, Scene &sc, double deg_x, double deg_y, double deg_z);
};

#endif // TRANSFORM_MANAGER_H
