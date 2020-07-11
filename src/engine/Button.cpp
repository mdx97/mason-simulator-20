#include "engine/Button.h"
#include "engine/Mouse.h"

void Button::Update()
{
    if (SDL_PointInRect(&Mouse::position, rect)) {
        Hover();
        if (Mouse::left_click)
            Click();
    } else {
        Unhover();
    }
}
