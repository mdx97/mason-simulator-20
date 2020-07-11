#include "engine/Utility.h"
#include "Constants.h"
#include "MainMenuScene.h"
#include "PlayButton.h"

void MainMenuScene::OnLoad()
{
    PlayButton *button = new PlayButton;
    button->rect = Utility::CreateCenterRect(button->surface->w, button->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    AddObject(button);
}

void MainMenuScene::OnUnload()
{
    // todo: abstract this?
    for (auto object : objects)
        delete object;
}
