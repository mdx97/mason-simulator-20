#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include "engine/Component.h"
#include "SDL.h"

class UIComponent : public Component
{
public:
    void Update(float elapsed);
    SDL_Surface *hover_surface = nullptr;
    void (*click)(Object *);

private:
    void HandleClick();
    void Hover(SpriteComponent *sprite);
    void Unhover(SpriteComponent *sprite);
    SDL_Surface *original_surface = nullptr;
};

#endif
