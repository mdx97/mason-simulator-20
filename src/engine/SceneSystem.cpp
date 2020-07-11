#include <iostream>
#include "engine/SceneSystem.h"

Scene *SceneSystem::current = nullptr;
Scene *next = nullptr;

// Loads a new scene to be played.
void SceneSystem::Load(Scene *scene)
{
    next = scene;
}

// Updates every object in the current scene.
void SceneSystem::Tick()
{
    if (next != nullptr) {
        if (current != nullptr)
            current->OnUnload();
        current = next;
        current->OnLoad();
        next = nullptr;
    }

    if (current == nullptr) return;

    for (auto *object : current->objects) {
        for (auto *component : object->components)
            component->Update();
    }
}
