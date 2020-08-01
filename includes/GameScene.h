#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "engine/Scene.h"

// @TODO: When the block class is refactored, remove this forward declaration.
class Block;

class GameScene : public Scene 
{
public:
    void OnLoad();
    void OnUnload();
    void Update(float elapsed) override;

private:
    Block *current_block = nullptr;
    Block *CreateIBlock();
    Block *CreateZBlock();
    Block *CreateJBlock();
    Block *CreateLBlock();
    Block *CreateOBlock();
    Block *CreateSBlock();
    Block *CreateTBlock();
};

#endif
