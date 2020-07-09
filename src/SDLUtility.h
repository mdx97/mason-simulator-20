#ifndef SDLUTILITY_H
#define SDLUTILITY_H

#include "SDL.h"

SDL_Window *InitializeSDLWindow(const std::string &title, int width, int height);
void DestroySDLWindow(SDL_Window *window);

#endif
