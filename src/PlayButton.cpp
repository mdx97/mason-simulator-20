#include <iostream>
#include "engine/AudioSystem.h"
#include "engine/Mouse.h"
#include "engine/SceneSystem.h"
#include "Constants.h"
#include "GameScene.h"
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
    GameScene *scene = new GameScene;
    SceneSystem::Load(scene);
}