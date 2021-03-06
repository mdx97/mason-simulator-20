#include <chrono>
#include <iostream>
#include <vector>
#include "engine/Entity.h"
#include "engine/SceneSystem.h"

std::vector<Entity *> SceneSystem::persistent_entities;

Scene *SceneSystem::current = nullptr;
Scene *next = nullptr;

std::chrono::system_clock::time_point last_clock = std::chrono::system_clock::now();

// Loads a new scene to be played.
void SceneSystem::Load(Scene *scene)
{
    next = scene;
}

// Updates every entity in the current scene.
void SceneSystem::Tick()
{
    if (next != nullptr) {
        if (current != nullptr) {
            current->OnUnload();
        }
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

    for (auto *entity : current->entities) {
        for (auto *component : entity->components) {
            component->Update(elapsed);
        }
    }

    for (auto *entity : persistent_entities) {
        for (auto *component : entity->components) {
            component->Update(elapsed);
        }
    }
}

// Adds an entity that will stay present across scenes.
void SceneSystem::AddPersistentEntity(Entity *entity)
{
    persistent_entities.push_back(entity);
}
