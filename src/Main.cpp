#include <iostream>
#include <string>
#include "AudioClip.h"
#include "AudioSystem.h"
#include "Constants.h"
#include "Mouse.h"
#include "SDL.h"
#include "SDLUtility.h"

SDL_Rect CreateCenterRect(int source_width, int source_height, int dest_width, int dest_height)
{
    SDL_Rect rect;
    rect.x = (dest_width - source_width) / 2;
    rect.y = (dest_height - source_height) / 2;
    rect.w = source_width;
    rect.h = source_height;
    return rect;
}

int main(int argc, char *argv[])
{
    SDL_Window *window = InitializeSDLWindow(Constants::TITLE, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    SDL_Surface *background = SDL_GetWindowSurface(window);
    
    SDL_Surface *play_normal = SDL_LoadBMP("resources/PlayButton.bmp");
    SDL_Surface *play_hover = SDL_LoadBMP("resources/PlayButtonHover.bmp");
    SDL_Surface *play = play_normal;
    SDL_Rect play_rect = CreateCenterRect(play->w, play->h, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);

    SDL_Event e;
    bool quit = false;

    LoopedAudioClip theme(Constants::THEME_SONG_PATH);
    AudioSystem::PlayClip(&theme);

    while (!quit) {
        SDL_GetMouseState(&mouse.x, &mouse.y);

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (SDL_PointInRect(&mouse, &play_rect)) {
                    std::cout << "Play clicked!" << std::endl;
                }
            }
        }

        play = SDL_PointInRect(&mouse, &play_rect) ? play_hover : play_normal;
        SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 0, 0, 0));
        SDL_BlitSurface(play, NULL, background, &play_rect);
        SDL_UpdateWindowSurface(window);
    }

    DestroySDLWindow(window);
    return 0;
}
