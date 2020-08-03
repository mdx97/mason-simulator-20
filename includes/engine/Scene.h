#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "engine/Object.h"

class Scene {
public:
    virtual void OnLoad() = 0;
    virtual void OnUnload() = 0;
    virtual void Update(float elapsed) = 0;
    std::vector<Object *> objects;
    void AddObject(Object *object);
    void RemoveObject(Object *object);
};

#endif
