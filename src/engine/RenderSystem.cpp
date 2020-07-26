#include "engine/Engine.h"
#include "engine/RenderSystem.h"
#include "engine/SceneSystem.h"
#include "engine/SpriteComponent.h"

SDL_Surface *RenderSystem::background = nullptr;

void DrawObjects(const std::vector<Object *> &objects)
{
    for (auto *object : objects) {
        SpriteComponent *sprite = object->GetComponent<SpriteComponent>();
        if (sprite != nullptr)
            SDL_BlitSurface(sprite->surface, nullptr, RenderSystem::background, &sprite->rect);
    }
}

// Renders every object onto the background surface.
void RenderSystem::Draw()
{
    SDL_FillRect(background, nullptr, SDL_MapRGB(background->format, 0, 0, 0));
    
    DrawObjects(SceneSystem::persistent_objects);
    if (SceneSystem::current != nullptr)
        DrawObjects(SceneSystem::current->objects);
    
    SDL_UpdateWindowSurface(Engine::window);
}
