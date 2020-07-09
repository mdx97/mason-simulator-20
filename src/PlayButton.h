#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H

#include "AudioClip.h"
#include "Button.h"

class PlayButton : public Button
{
public:
    PlayButton();
    ~PlayButton();
    void Hover();
    void Unhover();
    void Click();

private:
    SDL_Surface *normal, *hover;
    AudioClip *clip;
};

#endif
