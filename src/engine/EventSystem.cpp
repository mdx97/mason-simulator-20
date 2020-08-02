#include <iostream>
#include "engine/EventSystem.h"
#include "engine/Mouse.h"

bool EventSystem::exit = false;

// @TODO: This is just temporary, we will implement a better keydown event system.
bool EventSystem::keydown_a = false;
bool EventSystem::keydown_d = false;

// Checks for new I/O events and updates the Event System's internal representation of the state of these various I/O devices.
void EventSystem::Process()
{
    SDL_Event e;
    SDL_GetMouseState(&Mouse::position.x, &Mouse::position.y);
    Mouse::left_click = false;
    EventSystem::keydown_a = false;
    EventSystem::keydown_d = false;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            EventSystem::exit = true;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            Mouse::left_click = true;
        } else if (e.type == SDL_KEYDOWN) {
            if (SDL_GetScancodeFromKey(e.key.keysym.sym) == SDL_SCANCODE_A) EventSystem::keydown_a = true;
            if (SDL_GetScancodeFromKey(e.key.keysym.sym) == SDL_SCANCODE_D) EventSystem::keydown_d = true;
        }
    }
}
