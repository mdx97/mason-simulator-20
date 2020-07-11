#include "engine/Object.h"
#include "engine/SpriteComponent.h"
#include "engine/Utility.h"
#include "Constants.h"
#include "GameScene.h"

void GameScene::OnLoad()
{
    auto *area = new Object;
    auto *area_sprite = new SpriteComponent(Constants::PLAYING_AREA_PATH);
    area_sprite->rect = Utility::CreateCenterRect(area_sprite->surface->w, area_sprite->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    area->AddComponent(area_sprite);
    AddObject(area);
}

void GameScene::OnUnload()
{
    // todo: abstract this?
    for (auto object : objects)
        delete object;
}
