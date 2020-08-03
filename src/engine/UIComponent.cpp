#include "engine/Mouse.h"
#include "engine/SpriteComponent.h"
#include "engine/UIComponent.h"

void UIComponent::Update(float elapsed)
{
    auto *sprite = object->GetComponent<SpriteComponent>();
    
    if (sprite != nullptr) {
        SDL_Rect rect = { 
            object->x + sprite->x,
            object->y + sprite->y,
            sprite->surface->w, 
            sprite->surface->h 
        };

        if (SDL_PointInRect(&Mouse::position, &rect)) {
            Hover(sprite);
            HandleClick();
        } else {
            Unhover(sprite);
        }
    }
}

// Calls the click handler function if a click event has happened.
void UIComponent::HandleClick()
{
    if (Mouse::left_click && click != nullptr) {
        click(object);
    }
}

// Updates the sprite to use the hover image.
void UIComponent::Hover(SpriteComponent *sprite)
{
    if (hover_surface != nullptr && sprite->surface != hover_surface) {
        if (original_surface == nullptr) {
            original_surface = sprite->surface;
        }
        sprite->surface = hover_surface;
    }
}

// Updates the sprite to use the unhovered image.
void UIComponent::Unhover(SpriteComponent *sprite)
{
    if (original_surface != nullptr && sprite->surface != original_surface) {
        sprite->surface = original_surface;
    }
}
