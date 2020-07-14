#include <iostream>
#include <vector>
#include "engine/Object.h"
#include "engine/SceneSystem.h"

std::vector<Object *> SceneSystem::persistent_objects;
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

    for (auto *object : persistent_objects) {
        for (auto *component : object->components)
            component->Update();
    }
}

// Adds an object that will stay present across scenes.
void SceneSystem::AddPersistentObject(Object *object)
{
    persistent_objects.push_back(object);
}
