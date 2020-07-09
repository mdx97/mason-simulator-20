#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.h"

class Scene {
public:
    virtual void OnLoad() = 0;
    virtual void OnUnload() = 0;
    std::vector<Object *> objects;
    void AddObject(Object *object);
};

#endif
