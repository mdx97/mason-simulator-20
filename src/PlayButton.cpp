#include <iostream>
#include "AudioSystem.h"
#include "Constants.h"
#include "Mouse.h"
#include "PlayButton.h"

PlayButton::PlayButton()
{
    normal = SDL_LoadBMP(Constants::PLAY_BUTTON_PATH.c_str());
    hover = SDL_LoadBMP(Constants::PLAY_BUTTON_HOVER_PATH.c_str());
    surface = normal;
    clip = new AudioClip(Constants::PLAY_BUTTON_SOUND_PATH);
}

PlayButton::~PlayButton()
{
    SDL_FreeSurface(normal);
    SDL_FreeSurface(hover);
    delete clip;
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
    AudioSystem::FreeClip(clip);
    clip->Reset();
    AudioSystem::PlayClip(clip);
}