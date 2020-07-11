#ifndef SCENESYSTEM_H
#define SCENESYSTEM_H

#include "engine/Scene.h"

namespace SceneSystem {
    extern Scene *current;
    void Load(Scene *scene);
    void Tick();
};

#endif