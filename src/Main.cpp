#include <iostream>
#include <string>
#include "engine/AudioClip.h"
#include "engine/AudioSystem.h"
#include "engine/Engine.h"
#include "engine/Logger.h"
#include "engine/SceneSystem.h"
#include "Constants.h"
#include "MainMenuScene.h"
#include "SDL.h"

int main(int argc, char *argv[])
{
    Logger::SetFile(Constants::LOG_FILE_PATH);
    Engine::Start(Constants::TITLE, Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);

    LoopedAudioClip theme(Constants::THEME_SONG_PATH);
    AudioSystem::PlayClip(&theme);
    
    MainMenuScene mainmenu;
    SceneSystem::Load(&mainmenu);
    
    Engine::Run();
    return 0;
}
