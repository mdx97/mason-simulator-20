#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "engine/Scene.h"

class MainMenuScene : public Scene
{
public:
    void OnLoad();
    void OnUnload();
    void Update(float elapsed) { }
};

#endif
