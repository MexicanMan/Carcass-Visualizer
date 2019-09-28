#include "main_manager.h"

MainManager::MainManager()
{ }

void MainManager::addModel(const char *filename, LoadStrategy *strat)
{
    this->lm.setStrategy(strat);
    this->sc.addMdl(this->lm.loadObj(filename));
}

void MainManager::delModel(int i)
{
    this->sc.delMdl(i);
}

void MainManager::moveModel(int el_id, double shx, double shy, double shz)
{
    tm.MoveModel(el_id, this->sc, shx, shy, shz);
}

void MainManager::rotateModel(int el_id, double deg_x, double deg_y, double deg_z)
{
    tm.RotateModel(el_id, this->sc, deg_x, deg_y, deg_z);
}

void MainManager::scaleModel(int el_id, double k)
{
    tm.ScaleModel(el_id, this->sc, k);
}

void MainManager::addCam(double x, double y, double z)
{
    Point p(x, y, z);
    BaseCamera *cam = new Camera();
    cam->setPos(p);

    this->sc.addCam(cam);
}

void MainManager::delCam(int el_id)
{
    this->sc.delCam(el_id);
}

void MainManager::rotateCam(int el_id, double deg_x, double deg_y, double deg_z)
{
    tm.RotateCam(el_id, this->sc, deg_x, deg_y, deg_z);
}

void MainManager::moveCam(int el_id, double shx, double shy, double shz)
{
    tm.MoveCam(el_id, this->sc, shx, shy, shz);
}

void MainManager::drawScene(DrawStrategy *strat, int cam_id)
{
    this->dm.setStrategy(strat);
    this->dm.clearScene();
    this->dm.drawScene(this->sc, *(this->sc.getCamera(cam_id)));
}
