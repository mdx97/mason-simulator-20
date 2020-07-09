#include <iostream>
#include "Constants.h"
#include "Mouse.h"
#include "PlayButton.h"

PlayButton::PlayButton()
{
    normal = SDL_LoadBMP(Constants::PLAY_BUTTON_PATH.c_str());
    hover = SDL_LoadBMP(Constants::PLAY_BUTTON_HOVER_PATH.c_str());
    surface = normal;
}

PlayButton::~PlayButton()
{
    SDL_FreeSurface(normal);
    SDL_FreeSurface(hover);
}

void PlayButton::Hover() 
{
    surface = hover;
}

void PlayButton::Unhover()
{
    surface = normal;
}

void PlayButton::Click()
{
    std::cout << "Button clicked!" << std::endl;
}