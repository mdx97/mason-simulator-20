#ifndef BUTTON_H
#define BUTTON_H

#include "Object.h"

class Button : public Object
{
public:
    void Update();
    virtual void Hover() = 0;
    virtual void Unhover() = 0;
    virtual void Click() = 0;
};

#endif
