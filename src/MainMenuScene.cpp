#include "Constants.h"
#include "MainMenuScene.h"
#include "PlayButton.h"

SDL_Rect *CreateCenterRect(int source_width, int source_height, int dest_width, int dest_height)
{
    SDL_Rect *rect = new SDL_Rect;
    rect->x = (dest_width - source_width) / 2;
    rect->y = (dest_height - source_height) / 2;
    rect->w = source_width;
    rect->h = source_height;
    return rect;
}

void MainMenuScene::OnLoad()
{
    PlayButton *button = new PlayButton;
    button->rect = CreateCenterRect(button->surface->w, button->surface->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    AddObject(button);
}

void MainMenuScene::OnUnload()
{
    // todo: clean up after myself.
}
