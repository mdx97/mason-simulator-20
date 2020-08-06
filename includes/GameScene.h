#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "engine/Entity.h"
#include "engine/Scene.h"

#define COUNT_BLOCK_SPAWNERS 7

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
    Composite *current_block = nullptr;
    Composite *next_block = nullptr;

    Composite* (GameScene::* block_spawners[COUNT_BLOCK_SPAWNERS])();

    int score;
    SpriteComponent *score_sprites[3];

    float since_last_drop;

    Entity *barrier_left;
    Entity *barrier_right;

    Composite *CreateIBlock();
    Composite *CreateZBlock();
    Composite *CreateJBlock();
    Composite *CreateLBlock();
    Composite *CreateOBlock();
    Composite *CreateSBlock();
    Composite *CreateTBlock();

    void SpawnInitialBlock();
    void SpawnBlock();

    void BlockRotateLeft(Composite *composite, bool check_overlap);
    void BlockRotateRight(Composite *composite, bool check_overlap);

    void UpdateScore();

    bool CanMoveDirection(Direction direction);

    void HandleBlockControl();
    void HandleBlockGravity(float elapsed);
    void HandleScoring();

    bool OverlapsAny(Composite *composite);
};

#endif
