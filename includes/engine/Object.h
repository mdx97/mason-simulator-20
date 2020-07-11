#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "Component.h"
#include "SDL.h"

class Object
{
public:
    std::vector<Component *> components;

    // todo: create source file? may not be worth if this is our only function.
    void AddComponent(Component *component)
    {
        components.push_back(component);
        component->object = this;
    }
};

#endif
