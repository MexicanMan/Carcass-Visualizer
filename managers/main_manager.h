#ifndef MAIN_MANAGER_H
#define MAIN_MANAGER_H
#include "base_manager.h"
#include "load_manager.h"
#include "draw_manager.h"
#include "transform_manager.h"
#include "scene/scene.h"

class MainManager : public BaseManager
{
private:
    LoadManager lm;
    DrawManager dm;
    TransformManager tm;
    Scene sc;
public:
    MainManager();

    void addModel(const char *filename, LoadStrategy *strat);
    void delModel(int i);
    void moveModel(int el_id, double shx, double shy, double shz);
    void rotateModel(int el_id, double deg_x, double deg_y, double deg_z);
    void scaleModel(int el_id, double k);
    void addCam(double x, double y, double z);
    void delCam(int el_id);
    void rotateCam(int el_id, double deg_x, double deg_y, double deg_z);
    void moveCam(int el_id, double shx, double shy, double shz);

    void drawScene(DrawStrategy *strat, int cam_id);
};

#endif // MAIN_MANAGER_H
