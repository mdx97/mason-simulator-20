#include "engine/Object.h"
#include "engine/RenderSystem.h"
#include "engine/SceneSystem.h"
#include "engine/SpriteComponent.h"
#include "engine/UIComponent.h"
#include "engine/Utility.h"
#include "Constants.h"
#include "GameScene.h"
#include "MainMenuScene.h"

void MenuButtonClick(Object *object)
{
    auto *scene = new MainMenuScene;
    SceneSystem::Load(scene);
}

void GameScene::OnLoad()
{
    auto *area = new Object;
    auto *area_sprite = new SpriteComponent(Constants::PLAYING_AREA_PATH);
    Utility::CenterRect(&area_sprite->rect, area_sprite->surface, RenderSystem::background);
    area->AddComponent(area_sprite);
    AddObject(area);

    auto *menu_button = new Object;
    auto *menu_button_ui = new UIComponent;
    auto *menu_button_sprite = new SpriteComponent(Constants::MENU_BUTTON_PATH);
    menu_button_ui->hover_surface = SDL_LoadBMP(Constants::MENU_BUTTON_HOVER_PATH.c_str());
    menu_button_ui->click = &MenuButtonClick;
    menu_button->AddComponent(menu_button_ui);
    menu_button->AddComponent(menu_button_sprite);
    AddObject(menu_button);
}

void GameScene::OnUnload()
{
    // todo: abstract this?
    for (auto object : objects)
        delete object;
}
