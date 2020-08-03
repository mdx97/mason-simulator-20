#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component
{
public:
    virtual void Update(float elapsed) = 0;
    Entity *entity = nullptr;
};

#include "engine/Entity.h"

#endif
