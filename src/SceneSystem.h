#ifndef SCENESYSTEM_H
#define SCENESYSTEM_H

#include "Scene.h"

namespace SceneSystem {
    extern Scene *current;
    void Load(Scene *scene);
    void Tick();
};

#endif