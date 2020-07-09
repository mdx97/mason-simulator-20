#include <iostream>
#include <string>
#include "AudioClip.h"
#include "AudioSystem.h"
#include "Constants.h"
#include "EventSystem.h"
#include "MainMenuScene.h"
#include "RenderSystem.h"
#include "SceneSystem.h"
#include "SDL.h"
#include "SDLUtility.h"
#include "Window.h"

int main(int argc, char *argv[])
{
    Window::instance = InitializeSDLWindow(Constants::TITLE, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
    RenderSystem::background = SDL_GetWindowSurface(Window::instance);

    LoopedAudioClip theme(Constants::THEME_SONG_PATH);
    AudioSystem::PlayClip(&theme);

    MainMenuScene mainmenu;
    SceneSystem::Load(&mainmenu);

    while (!EventSystem::exit) {
        EventSystem::Process();
        SceneSystem::Tick();
        RenderSystem::Draw();
    }

    DestroySDLWindow(Window::instance);
    return 0;
}
