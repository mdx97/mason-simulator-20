#include <iostream>
#include <string>
#include "AudioClip.h"
#include "AudioSystem.h"
#include "Constants.h"
#include "Engine.h"
#include "EventSystem.h"
#include "MainMenuScene.h"
#include "RenderSystem.h"
#include "SceneSystem.h"
#include "SDL.h"

int main(int argc, char *argv[])
{
    Engine::Start(Constants::TITLE, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);

    LoopedAudioClip theme(Constants::THEME_SONG_PATH);
    AudioSystem::PlayClip(&theme);

    MainMenuScene mainmenu;
    SceneSystem::Load(&mainmenu);

    while (!EventSystem::exit) {
        EventSystem::Process();
        SceneSystem::Tick();
        RenderSystem::Draw();
    }

    Engine::End();
    return 0;
}
