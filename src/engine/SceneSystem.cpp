#include <chrono>
#include <iostream>
#include <vector>
#include "engine/Object.h"
#include "engine/SceneSystem.h"

std::vector<Object *> SceneSystem::persistent_objects;

Scene *SceneSystem::current = nullptr;
Scene *next = nullptr;

std::chrono::system_clock::time_point last_clock = std::chrono::system_clock::now();

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

    auto clock = std::chrono::system_clock::now();
    std::chrono::duration<float> diff = clock - last_clock;
    last_clock = clock;

    float elapsed = diff.count();

    current->Update(elapsed);

    for (auto *object : current->objects) {
        for (auto *component : object->components)
            component->Update(elapsed);
    }

    for (auto *object : persistent_objects) {
        for (auto *component : object->components)
            component->Update(elapsed);
    }
}

// Adds an object that will stay present across scenes.
void SceneSystem::AddPersistentObject(Object *object)
{
    persistent_objects.push_back(object);
}
