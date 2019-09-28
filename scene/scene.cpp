#include "scene.h"

Scene::Scene()
{
    objects->addObj(new Camera());
}

void Scene::addMdl(BaseObject *mdl)
{
    objects->addObj(mdl);

    Point c;
    BaseTransformMatrix tm;
    scene_objects.append(SceneObject(c, tm, mdl));
}

void Scene::addCam(BaseObject *cam)
{
    objects->addObj(cam);
}

void Scene::delMdl(int i)
{
    int ind = -1, ind1 = i;
    for(Iterator<BaseObject*> it = begin(); it != end() && i != -1; it++)
    {
        if ((*it)->is_display() == true)
            i--;
        ind++;
    }

    if (i == -1)
    {
        objects->removeObj(ind);
        scene_objects.remove(ind1);
    }
    else
        throw SceneError::WrongMdlIndex("in delMdl()");
}

void Scene::delCam(int i)
{
    int ind = -1;
    for(Iterator<BaseObject*> it = begin(); it != end() && i != -1; it++)
    {
        if ((*it)->is_display() == false)
            i--;
        ind++;
    }

    if (i == -1)
        objects->removeObj(ind);
    else
        throw SceneError::WrongCamIndex("in delCam()");
}

SceneObject& Scene::getSceneObj(int i)
{
    return this->scene_objects[i];
}

BaseCamera* Scene::getCamera(int i)
{
    int ind = -1;
    for(Iterator<BaseObject*> it = begin(); it != end() && i != -1; it++)
    {
        if ((*it)->is_display() == false)
            i--;
        ind++;
    }

    if (i == -1)
        return (BaseCamera*) this->objects->getChild(ind);
    else
    {
        throw SceneError::WrongCamIndex("in getCamera()");
        return nullptr;
    }
}

Iterator<BaseObject*> Scene::begin()
{
    return objects->begin();
}

Iterator<BaseObject*> Scene::end()
{
    return objects->end();
}

Iterator<SceneObject> Scene::begin_sc()
{
    return scene_objects.begin();
}

Iterator<SceneObject> Scene::end_sc()
{
    return scene_objects.end();
}
