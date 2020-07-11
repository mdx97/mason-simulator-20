#include <iostream>
#include <string>
#include "engine/AudioClip.h"
#include "engine/AudioSystem.h"
#include "engine/Engine.h"
#include "engine/EventSystem.h"
#include "engine/RenderSystem.h"
#include "engine/SceneSystem.h"
#include "Constants.h"
#include "MainMenuScene.h"
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
