#include "transform_manager.h"

TransformManager::TransformManager()
{ }

void TransformManager::RotateModel(int i, Scene &sc, double deg_x, double deg_y, double deg_z)
{
    RotateMatrix matr(deg_x, deg_y, deg_z);
    if (i == -1)
        for (Iterator<SceneObject> it = sc.begin_sc(); it != sc.end_sc(); it++)
            (*it).getTransfMatr() *= matr;
    else
        sc.getSceneObj(i).getTransfMatr() *= matr;
}

void TransformManager::MoveModel(int i, Scene &sc, double shx, double shy, double shz)
{
    if (i == -1)
        for (Iterator<SceneObject> it = sc.begin_sc(); it != sc.end_sc(); it++)
        {
            Point t = (*it).getCenter();
            (*it).setCenter(t.X()+shx, t.Y()+shy, t.Z()+shz);
        }
    else
    {
        Point t = sc.getSceneObj(i).getCenter();
        sc.getSceneObj(i).setCenter(t.X()+shx, t.Y()+shy, t.Z()+shz);
    }
}

void TransformManager::ScaleModel(int i, Scene &sc, double k)
{
    ScaleMatrix matr(k);
    if (i == -1)
        for (Iterator<SceneObject> it = sc.begin_sc(); it != sc.end_sc(); it++)
            (*it).getTransfMatr() *= matr;
    else
        sc.getSceneObj(i).getTransfMatr() *= matr;
}

void TransformManager::MoveCam(int i, Scene &sc, double shx, double shy, double shz)
{
    BaseCamera* cam = sc.getCamera(i);
    cam->Move(shx, shy, shz);
}

void TransformManager::RotateCam(int i, Scene &sc, double deg_x, double deg_y, double deg_z)
{
    BaseCamera* cam = sc.getCamera(i);
    cam->Rotate(deg_x, deg_y, deg_z);
}
