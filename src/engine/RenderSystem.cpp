#include "engine/Engine.h"
#include "engine/RenderSystem.h"
#include "engine/SceneSystem.h"
#include "engine/SpriteComponent.h"

SDL_Surface *RenderSystem::background = nullptr;

// Renders every object in the current scene.
void RenderSystem::Draw()
{
    SDL_FillRect(background, nullptr, SDL_MapRGB(background->format, 0, 0, 0));
    if (SceneSystem::current == nullptr) return;
    for (Object *object : SceneSystem::current->objects) {
        SpriteComponent *sprite = object->GetComponent<SpriteComponent>();
        if (sprite != nullptr)
            SDL_BlitSurface(sprite->surface, nullptr, background, sprite->rect);
    }
    SDL_UpdateWindowSurface(Engine::window);
}
