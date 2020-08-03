#include "engine/Entity.h"
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

void PlayButtonClickHandler(Entity *entity)
{
    auto *game = new GameScene;
    SceneSystem::Load(game);
}

void MainMenuScene::OnLoad()
{
    // Logo
    auto *logo = new Entity;
    auto *logo_sprite = new SpriteComponent(ResourceManager::GetImagePath("Logo"));
    Utility::CenterEntity(logo, RenderSystem::background, logo_sprite->surface->w, logo_sprite->surface->h);
    logo->y = 20;
    logo->AddComponent(logo_sprite);
    AddEntity(logo);

    // Play Button
    auto *play = new Entity;

    auto *play_sprite = new SpriteComponent(ResourceManager::GetImagePath("PlayButton"));
    Utility::CenterEntity(play, RenderSystem::background, play_sprite->surface->w, play_sprite->surface->h);
    play->y = 300;

    auto *play_ui = new UIComponent;
    play_ui->hover_surface = SDL_LoadBMP(ResourceManager::GetImagePath("PlayButtonHover").c_str());
    play_ui->click = &PlayButtonClickHandler;

    play->AddComponent(play_ui);
    play->AddComponent(play_sprite);

    AddEntity(play);

    // Trademark
    auto *trademark = new Entity;
    auto *trademark_sprite = new SpriteComponent(ResourceManager::GetImagePath("Trademark"));
    Utility::CenterEntity(trademark, RenderSystem::background, trademark_sprite->surface->w, trademark_sprite->surface->h);
    trademark->y = 465;
    trademark->AddComponent(trademark_sprite);
    AddEntity(trademark);
}

void MainMenuScene::OnUnload()
{
    // @TODO: abstract this?
    for (auto entity : entities) {
        delete entity;
    }
}
