#ifndef OBJECT_H
#define OBJECT_H

#include "SDL.h"

class Object
{
public:
    virtual void Update() = 0;
    SDL_Rect *rect;
    SDL_Surface *surface;
};

#endif