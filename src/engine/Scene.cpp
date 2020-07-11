#include "engine/Scene.h"

// Adds a new object to the scene.
void Scene::AddObject(Object *object)
{
    objects.push_back(object);
}
