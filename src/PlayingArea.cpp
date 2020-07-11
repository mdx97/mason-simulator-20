#include "Constants.h"
#include "PlayingArea.h"

PlayingArea::PlayingArea()
{
    surface = SDL_LoadBMP(Constants::PLAYING_AREA_PATH.c_str());
}

PlayingArea::~PlayingArea()
{
    SDL_FreeSurface(surface);
}
