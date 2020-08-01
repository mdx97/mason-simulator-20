#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <string>
#include "engine/Component.h"
#include "SDL.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent(const std::string &image_path);
    ~SpriteComponent();
    void Update(float elapsed) { }
    SDL_Surface *surface = nullptr;
    SDL_Rect rect;
};

#endif
