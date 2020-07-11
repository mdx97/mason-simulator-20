#include "engine/Engine.h"
#include "engine/RenderSystem.h"
#include "engine/SceneSystem.h"

SDL_Surface *RenderSystem::background = NULL;

// Renders every object in the current scene.
void RenderSystem::Draw()
{
    SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 0, 0, 0));
    if (SceneSystem::current == NULL) return;
    for (auto object : SceneSystem::current->objects) {
        SDL_BlitSurface(object->surface, NULL, background, object->rect);
    }
    SDL_UpdateWindowSurface(Engine::window);
}
