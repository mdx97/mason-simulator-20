#ifndef SCENESYSTEM_H
#define SCENESYSTEM_H

#include <vector>
#include "engine/Scene.h"

namespace SceneSystem {
    extern Scene *current;
    extern std::vector<Object *> persistent_objects;
    void Load(Scene *scene);
    void Tick();
    void AddPersistentObject(Object *object);
};

#endif
