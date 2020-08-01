#include "engine/Object.h"
#include "engine/RenderSystem.h"
#include "engine/ResourceManager.h"
#include "engine/SceneSystem.h"
#include "engine/SpriteComponent.h"
#include "engine/Utility.h"
#include "engine/UIComponent.h"
#include "Constants.h"
#include "GameScene.h"
#include "GameUtility.h"
#include "MainMenuScene.h"

void PlayButtonClickHandler(Object *object)
{
    auto *game = new GameScene;
    SceneSystem::Load(game);
}

void MainMenuScene::OnLoad()
{
    // Logo
    auto *logo = new Object;
    auto *logo_sprite = new SpriteComponent(ResourceManager::GetImagePath("Logo"));
    Utility::CenterRect(&logo_sprite->rect, logo_sprite->surface, RenderSystem::background);
    logo_sprite->rect.y = 20;
    logo->AddComponent(logo_sprite);
    AddObject(logo);

    // Play Button
    auto *play = new Object;

    auto *play_sprite = new SpriteComponent(ResourceManager::GetImagePath("PlayButton"));
    Utility::CenterRect(&play_sprite->rect, play_sprite->surface, RenderSystem::background);
    play_sprite->rect.y = 300;

    auto *play_ui = new UIComponent;
    play_ui->hover_surface = SDL_LoadBMP(ResourceManager::GetImagePath("PlayButtonHover").c_str());
    play_ui->click = &PlayButtonClickHandler;

    play->AddComponent(play_ui);
    play->AddComponent(play_sprite);

    AddObject(play);

    // Trademark
    auto *trademark = new Object;
    auto *trademark_sprite = new SpriteComponent(ResourceManager::GetImagePath("Trademark"));
    Utility::CenterRect(&trademark_sprite->rect, trademark_sprite->surface, RenderSystem::background);
    trademark_sprite->rect.y = 465;
    trademark->AddComponent(trademark_sprite);
    AddObject(trademark);
}

void MainMenuScene::OnUnload()
{
    // @TODO: abstract this?
    for (auto object : objects)
        delete object;
}
