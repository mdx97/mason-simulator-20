#include "engine/Mouse.h"
#include "engine/SpriteComponent.h"
#include "engine/UIComponent.h"

void UIComponent::Update()
{
    auto *sprite = object->GetComponent<SpriteComponent>();
    if (sprite != nullptr) {
        if (SDL_PointInRect(&Mouse::position, sprite->rect)) {
            if (hover_surface != nullptr) {
                if (original_surface == nullptr)
                    original_surface = sprite->surface;
                sprite->surface = hover_surface;
            }
            if (Mouse::left_click && click != nullptr)
                click(object);
        } else {
            if (original_surface != nullptr)
                sprite->surface = original_surface;
        }
    }
}
