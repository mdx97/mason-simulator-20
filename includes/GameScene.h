#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "engine/Scene.h"

#define COUNT_BLOCK_SPAWNERS 7

// @TODO: When the block class is refactored, remove this forward declaration.
class Block;

typedef enum direction_e {
    DIRECTION_LEFT,
    DIRECTION_RIGHT,
    DIRECTION_UP,
    DIRECTION_DOWN
} Direction;

class GameScene : public Scene 
{
public:
    GameScene();
    void OnLoad();
    void OnUnload();
    void Update(float elapsed) override;

private:
    Block *current_block = nullptr;
    Block* (GameScene::* block_spawners[COUNT_BLOCK_SPAWNERS])();
    Block *CreateIBlock();
    Block *CreateZBlock();
    Block *CreateJBlock();
    Block *CreateLBlock();
    Block *CreateOBlock();
    Block *CreateSBlock();
    Block *CreateTBlock();
    Block *CreateRandomBlock();

    void HandleBlockControl();
    void HandleBlockGravity(float elapsed);
    bool CanMoveDirection(Direction direction);
};

#endif
