#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include "Component.h"
#include "SDL.h"

class Object
{
public:
    int x, y;
    const char *type;

    Object()
    {
        x = 0;
        y = 0;
        type = "";
    }

    ~Object()
    {
        for (auto component : components)
            delete component;
    }

    std::vector<Component *> components;

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
