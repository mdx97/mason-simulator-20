#include <iostream>
#include "SceneSystem.h"

Scene *SceneSystem::current = NULL;

// Loads a new scene to be played.
void SceneSystem::Load(Scene *scene)
{
    if (current != NULL) {
        current->OnUnload();
        delete current;
    }
    current = scene;
    scene->OnLoad();
}

// Updates every object in the current scene.
void SceneSystem::Tick()
{
    if (current == NULL) return;
    for (auto object : current->objects) {
        object->Update();
    }
}
