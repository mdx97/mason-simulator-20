#ifndef UTILITY_H
#define UTILITY_H

#include "SDL.h"

namespace Utility {
    SDL_Rect *CreateCenterRect(int source_width, int source_height, int dest_width, int dest_height);
};

#endif
