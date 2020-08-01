#ifndef COMPONENT_H
#define COMPONENT_H

class Object;

class Component
{
public:
    virtual void Update(float elapsed) = 0;
    Object *object = nullptr;
};

#include "engine/Object.h"

#endif
