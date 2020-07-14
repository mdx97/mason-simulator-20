#include <iostream>
#include "engine/Engine.h"
#include "engine/EventSystem.h"
#include "engine/RenderSystem.h"
#include "engine/SceneSystem.h"

SDL_Window *Engine::window = nullptr;

// Initializes SDL and sets up the engine for use.
// This function should always be the first thing called.
void Engine::Start(const std::string &title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cout << "Window could not be created! Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    RenderSystem::background = SDL_GetWindowSurface(window);
}

// Runs the main game loop until the user exits the program.
void Engine::Run()
{
    while (!EventSystem::exit) {
        EventSystem::Process();
        SceneSystem::Tick();
        RenderSystem::Draw();
    }

    End();
}

// Cleans up any engine allocated memory.
// This function should always be the last thing called.
void Engine::End()
{
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    surface = nullptr;
    window = nullptr;
    RenderSystem::background = nullptr;
    SDL_Quit();
}
