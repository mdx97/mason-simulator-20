#include <algorithm>
#include "engine/Scene.h"

// Adds a new object to the scene.
void Scene::AddObject(Object *object)
{
    objects.push_back(object);
}

void Scene::RemoveObject(Object *object)
{
    auto iter = std::find(objects.begin(), objects.end(), object);
    
    if (iter != objects.end()) {
        objects.erase(iter);
    }
}
