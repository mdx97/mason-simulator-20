#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include "engine/Component.h"
#include "SDL.h"

class UIComponent : public Component
{
public:
    void Update();
    SDL_Surface *hover_surface;
    void (*click)(Object *);
private:
    SDL_Surface *original_surface;
};

#endif
