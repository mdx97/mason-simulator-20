#include <iostream>
#include "SceneSystem.h"

Scene *SceneSystem::current = NULL;

void SceneSystem::Load(Scene *scene)
{
    if (current != NULL)
        current->OnUnload();
    current = scene;
    scene->OnLoad();
}

void SceneSystem::Tick()
{
    if (current == NULL) return;
    for (auto object : current->objects) {
        object->Update();
    }
}
