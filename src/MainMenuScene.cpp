#include "engine/Object.h"
#include "engine/SceneSystem.h"
#include "engine/SpriteComponent.h"
#include "engine/Utility.h"
#include "engine/UIComponent.h"
#include "Constants.h"
#include "GameScene.h"
#include "MainMenuScene.h"

void PlayButtonClickHandler(Object *object)
{
    auto *game = new GameScene;
    SceneSystem::Load(game);
}

void MainMenuScene::OnLoad()
{
    auto *logo = new Object;
    auto *logo_sprite = new SpriteComponent(Constants::LOGO_PATH);
    logo_sprite->rect = Utility::CreateCenterRect(logo_sprite->surface->w, logo_sprite->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    logo_sprite->rect->y = 20;
    logo->AddComponent(logo_sprite);
    AddObject(logo);

    auto *play = new Object;
    auto *play_ui = new UIComponent;
    auto *play_sprite = new SpriteComponent(Constants::PLAY_BUTTON_PATH);
    play_ui->hover_surface = SDL_LoadBMP(Constants::PLAY_BUTTON_HOVER_PATH.c_str());
    play_ui->click = &PlayButtonClickHandler;
    play_sprite->rect = Utility::CreateCenterRect(play_sprite->surface->w, play_sprite->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    play->AddComponent(play_ui);
    play->AddComponent(play_sprite);
    AddObject(play);

    auto *trademark = new Object;
    auto *trademark_sprite = new SpriteComponent(Constants::TRADEMARK_PATH);
    trademark_sprite->rect = Utility::CreateCenterRect(trademark_sprite->surface->w, trademark_sprite->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    trademark_sprite->rect->y = 465;
    trademark->AddComponent(trademark_sprite);
    AddObject(trademark);
}

void MainMenuScene::OnUnload()
{
    // todo: abstract this?
    for (auto object : objects)
        delete object;
}
