#include "engine/Utility.h"

SDL_Rect *Utility::CreateCenterRect(int source_width, int source_height, int dest_width, int dest_height)
{
    SDL_Rect *rect = new SDL_Rect;
    rect->x = (dest_width - source_width) / 2;
    rect->y = (dest_height - source_height) / 2;
    rect->w = source_width;
    rect->h = source_height;
    return rect;
}
