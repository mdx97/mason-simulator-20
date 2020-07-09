#include "RenderSystem.h"
#include "SceneSystem.h"
#include "Window.h"

SDL_Surface *RenderSystem::background = NULL;

void RenderSystem::Draw()
{
    SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 0, 0, 0));
    if (SceneSystem::current == NULL) return;
    for (auto object : SceneSystem::current->objects) {
        SDL_BlitSurface(object->surface, NULL, background, object->rect);
    }
    SDL_UpdateWindowSurface(Window::instance);
}
