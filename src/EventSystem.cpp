#include "EventSystem.h"
#include "Mouse.h"

bool EventSystem::exit = false;

// Checks for new I/O events and updates the Event System's internal representation of the state of these various I/O devices.
void EventSystem::Process()
{
    SDL_Event e;
    SDL_GetMouseState(&Mouse::position.x, &Mouse::position.y);
    Mouse::left_click = false;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            EventSystem::exit = true;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            Mouse::left_click = true;
        }
    }
}
