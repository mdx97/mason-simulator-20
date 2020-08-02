#include <iostream>
#include "engine/EventSystem.h"
#include "engine/Mouse.h"

bool EventSystem::exit = false;

bool scancode_pressed_states[SDL_NUM_SCANCODES];

// Checks for new I/O events and updates the Event System's internal representation of the state of these various I/O devices.
void EventSystem::Process()
{
    SDL_Event e;
    SDL_GetMouseState(&Mouse::position.x, &Mouse::position.y);
    Mouse::left_click = false;

    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        scancode_pressed_states[i] = false;
    }

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            EventSystem::exit = true;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            Mouse::left_click = true;
        } else if (e.type == SDL_KEYDOWN) {
            scancode_pressed_states[SDL_GetScancodeFromKey(e.key.keysym.sym)] = true;
        }
    }
}

bool EventSystem::IsKeyDown(SDL_Scancode scancode)
{
    return scancode_pressed_states[scancode];
}
