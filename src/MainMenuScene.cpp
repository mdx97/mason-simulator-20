#include "engine/Object.h"
#include "engine/SpriteComponent.h"
#include "engine/Utility.h"
#include "engine/UIComponent.h"
#include "Constants.h"
#include "MainMenuScene.h"

void MainMenuScene::OnLoad()
{
    auto *play = new Object;
    auto *play_ui = new UIComponent;
    auto *play_sprite = new SpriteComponent(Constants::PLAY_BUTTON_PATH);
    play_sprite->rect = Utility::CreateCenterRect(play_sprite->surface->w, play_sprite->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    play->AddComponent(play_ui);
    play->AddComponent(play_sprite);
    AddObject(play);
}

void MainMenuScene::OnUnload()
{
    // todo: abstract this?
    for (auto object : objects)
        delete object;
}
