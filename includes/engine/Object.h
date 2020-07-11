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

    template <typename T>T* GetComponent()
    {
        T *casted = nullptr;
        for (auto component : components) {
            casted = dynamic_cast<T *>(component);
            if (casted != nullptr) break;
        }
        return casted;
    }
};

#endif
