#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include "SDL.h"

namespace Constants {
    const std::string TITLE = "Mason Simulator '20";

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const std::string LOG_FILE_PATH = "log.txt";

    const std::string THEME_SONG_PATH = "resources/theme.wav";

    const std::string MENU_BUTTON_PATH = "resources/Menu.bmp";
    const std::string MENU_BUTTON_HOVER_PATH = "resources/MenuHover.bmp";
    const std::string PLAY_BUTTON_PATH = "resources/PlayButton.bmp";
    const std::string PLAY_BUTTON_HOVER_PATH = "resources/PlayButtonHover.bmp";
    const std::string PLAYING_AREA_PATH = "resources/PlayingArea.bmp";
};

#endif
