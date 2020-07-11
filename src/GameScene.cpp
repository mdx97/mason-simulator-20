#include "engine/Utility.h"
#include "Constants.h"
#include "GameScene.h"
#include "PlayingArea.h"

void GameScene::OnLoad()
{
    PlayingArea *area = new PlayingArea;
    area->rect = Utility::CreateCenterRect(area->surface->w, area->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    AddObject(area);
}

void GameScene::OnUnload()
{
    // todo: abstract this?
    for (auto object : objects)
        delete object;
}
