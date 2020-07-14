#include "engine/Utility.h"

// Sets the given rect to be centered in the middle of the destination surface.
void Utility::CenterRect(SDL_Rect *rect, SDL_Surface *source, SDL_Surface *dest)
{
    rect->x = (dest->w - source->w) / 2;
    rect->y = (dest->h - source->h) / 2;
    rect->w = source->w;
    rect->h = source->h;
}
