#include <algorithm>
#include "engine/Scene.h"

// Adds a new entity to the scene.
void Scene::AddEntity(Entity *entity)
{
    entities.push_back(entity);
}

void Scene::RemoveEntity(Entity *entity)
{
    auto iter = std::find(entities.begin(), entities.end(), entity);
    
    if (iter != entities.end()) {
        entities.erase(iter);
    }
}
