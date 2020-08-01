#include "engine/Object.h"
#include "engine/Utility.h"

// Sets the given rect to be centered in the middle of the destination surface.
void Utility::CenterObject(Object *object, SDL_Surface *container, int width, int height)
{
    object->x = (container->w - width) / 2;
    object->y = (container->h - height) / 2;
}
