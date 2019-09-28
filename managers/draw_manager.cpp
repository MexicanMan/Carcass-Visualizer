#include "draw_manager.h"

void DrawManager::drawScene(Scene &scene, BaseCamera &cam)
{
    for (Iterator<SceneObject> it = scene.begin_sc(); it != scene.end_sc(); it++)
        ds->drawObj(*it, cam);
}

void DrawManager::clearScene()
{
    ds->clearScene();
}
