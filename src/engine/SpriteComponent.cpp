#include "engine/SpriteComponent.h"
#include "SDL.h"

SpriteComponent::SpriteComponent(const std::string &image_path)
{
    surface = SDL_LoadBMP(image_path.c_str());
}

SpriteComponent::~SpriteComponent()
{
    SDL_FreeSurface(surface);
}
