#include <iostream>
#include "engine/SceneSystem.h"

Scene *SceneSystem::current = NULL;

// Loads a new scene to be played.
void SceneSystem::Load(Scene *scene)
{
    if (current != NULL) {
        current->OnUnload();
        // todo: we need to free this memory, but for some reason doing it like this is causing an error.
        //delete current;
    }
    current = scene;
    scene->OnLoad();
}

// Updates every object in the current scene.
void SceneSystem::Tick()
{
    if (current == NULL) return;
    for (auto object : current->objects) {
        for (auto component : object->components)
            component->Update();
    }
}
