#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include "engine/CollisionComponent.h"
#include "engine/EventSystem.h"
#include "engine/Logger.h"
#include "engine/RenderSystem.h"
#include "engine/ResourceManager.h"
#include "engine/SceneSystem.h"
#include "engine/SpriteComponent.h"
#include "engine/UIComponent.h"
#include "engine/Utility.h"
#include "Constants.h"
#include "GameScene.h"
#include "GameUtility.h"
#include "MainMenuScene.h"

// @TODO: Replace with 2d vectors?
const int BLOCK_SPAWN_X_CENTER_OFFSET = 0;
const int BLOCK_SPAWN_Y_CENTER_OFFSET = -192;
const int BLOCK_SPAWN_X_DECK_OFFSET = -224;
const int BLOCK_SPAWN_Y_DECK_OFFSET = -128;
const int BLOCK_DECK_X_CENTER_OFFSET = 224;
const int BLOCK_DECK_Y_CENTER_OFFSET = -64;

const int ROWS = 11;
const int COLS = 7;

const int MAX_Y = 384;
const int MIN_X = 208;

const int DROP_RATE = 1;
const int DROP_AMOUNT = 32;
const int SHIFT_AMOUNT = 32;

void BlockTranslate(Composite *composite, int x, int y)
{ 
    for (auto *entity : composite->entities) {
        entity->x += x;
        entity->y += y;
    }
}

void GameScene::CorrectPositionAgainstBarriers(Composite *composite)
{
    // Correct against left side barrier.
    CollisionComponent *barrier_left_collider = barrier_left->GetComponent<CollisionComponent>();

    if (barrier_left_collider != nullptr) {
        bool check_left = true;

        while (1) {
            check_left = false;

            for (auto *block : composite->entities) {
                CollisionComponent *block_collider = block->GetComponent<CollisionComponent>();

                if (block_collider != nullptr) {
                    if (block->x + block_collider->x < barrier_left->x + barrier_left_collider->x + barrier_left_collider->w) {
                        check_left = true;
                        break;
                    }
                }
            }

            if (!check_left) break;

            BlockTranslate(composite, SHIFT_AMOUNT, 0);
        }
    }

    // Correct against right side barrier.
    CollisionComponent *barrier_right_collider = barrier_right->GetComponent<CollisionComponent>();

    if (barrier_right_collider != nullptr) {
        bool check_right = true;

        while (1) {
            check_right = false;

            for (auto *block : composite->entities) {
                CollisionComponent *block_collider = block->GetComponent<CollisionComponent>();

                if (block_collider != nullptr) {
                    if (block->x + block_collider->x + block_collider->w  > barrier_right->x + barrier_right_collider->x) {
                        check_right = true;
                        break;
                    }
                }
            }

            if (!check_right) break;

            BlockTranslate(composite, -SHIFT_AMOUNT, 0);
        }
    }
}

void GameScene::BlockRotateLeft(Composite *composite)
{
    auto *block1 = composite->entities[0];

    for (int i = 1; i < composite->entities.size(); i++) {
        auto *block = composite->entities[i];

        int offset_x = block->x - block1->x;
        int offset_y = block->y - block1->y;

        block->x = block1->x + offset_y;
        block->y = block1->y + (offset_x * -1);
    }

    CorrectPositionAgainstBarriers(composite);
}

void GameScene::BlockRotateRight(Composite *composite)
{
    auto *block1 = composite->entities[0];
    
    for (int i = 1; i < composite->entities.size(); i++) {
        auto *block = composite->entities[i];

        int offset_x = block->x - block1->x;
        int offset_y = block->y - block1->y;

        block->x = block1->x - offset_y;
        block->y = block1->y - (offset_x * -1);
    }

    CorrectPositionAgainstBarriers(composite);
}

void MenuButtonClick(Entity *entity)
{
    auto *scene = new MainMenuScene;
    SceneSystem::Load(scene);
}

Composite *CreateBlockComposite(Entity *block1, Entity *block2, Entity *block3, Entity *block4, const char *type)
{
    auto *composite = new Composite;

    composite->AddEntity(block1);
    composite->AddEntity(block2);
    composite->AddEntity(block3);
    composite->AddEntity(block4);

    block1->type = "Block";
    block2->type = "Block";
    block3->type = "Block";
    block4->type = "Block";

    composite->type = type;

    return composite;
}

// @TODO: Should refactor these functions out of this file, it kinda clutters it up.
Composite *GameScene::CreateIBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);
    
    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 64;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);
    
    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);
    
    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "I-Block");
}

Composite *GameScene::CreateZBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->y -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "Z-Block");
}

Composite *GameScene::CreateJBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);
    
    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x -= 32;
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "J-Block");
}

Composite *GameScene::CreateLBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x += 32;
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "L-Block");
}

Composite *GameScene::CreateOBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x += 32;
    block3->y -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "O-Block");
}

Composite *GameScene::CreateSBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x += 32;
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->y -= 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "S-Block");
}

Composite *GameScene::CreateTBlock()
{
    // First block.
    auto *block1 = new Entity;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterEntity(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddEntity(block1);

    // Second block.
    auto *block2 = new Entity;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterEntity(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddEntity(block2);

    // Third block.
    auto *block3 = new Entity;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterEntity(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddEntity(block3);

    // Fourth block.
    auto *block4 = new Entity;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterEntity(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddEntity(block4);

    return CreateBlockComposite(block1, block2, block3, block4, "T-Block");
}

void GameScene::SpawnInitialBlock()
{
    current_block = (this->*block_spawners[std::rand() % COUNT_BLOCK_SPAWNERS])();
    BlockTranslate(current_block, BLOCK_SPAWN_X_CENTER_OFFSET, BLOCK_SPAWN_Y_CENTER_OFFSET);

    next_block = (this->*block_spawners[std::rand() % COUNT_BLOCK_SPAWNERS])();
    BlockTranslate(next_block, BLOCK_DECK_X_CENTER_OFFSET, BLOCK_DECK_Y_CENTER_OFFSET);
}

void GameScene::SpawnBlock()
{
    current_block = next_block;
    BlockTranslate(current_block, BLOCK_SPAWN_X_DECK_OFFSET, BLOCK_SPAWN_Y_DECK_OFFSET);

    next_block = (this->*block_spawners[std::rand() % COUNT_BLOCK_SPAWNERS])();
    BlockTranslate(next_block, BLOCK_DECK_X_CENTER_OFFSET, BLOCK_DECK_Y_CENTER_OFFSET);
}

GameScene::GameScene()
{
    score = 0;
    since_last_drop = 0;

    block_spawners[0] = &GameScene::CreateIBlock;
    block_spawners[1] = &GameScene::CreateZBlock;
    block_spawners[2] = &GameScene::CreateJBlock;
    block_spawners[3] = &GameScene::CreateLBlock;
    block_spawners[4] = &GameScene::CreateOBlock;
    block_spawners[5] = &GameScene::CreateSBlock;
    block_spawners[6] = &GameScene::CreateTBlock;
}

void GameScene::OnLoad()
{
    score = 0;
    since_last_drop = 0;

    // Playing Area
    auto *area = new Entity;
    auto *area_sprite = new SpriteComponent(ResourceManager::GetImagePath("PlayingArea"));
    Utility::CenterEntity(area, RenderSystem::background, area_sprite->surface->w, area_sprite->surface->h);
    area->AddComponent(area_sprite);
    AddEntity(area);
    
    // Menu Button
    auto *menu_button = new Entity;
    auto *menu_button_sprite = new SpriteComponent(ResourceManager::GetImagePath("Menu"));

    auto *menu_button_ui = new UIComponent;
    menu_button_ui->hover_surface = SDL_LoadBMP(ResourceManager::GetImagePath("MenuHover").c_str());
    menu_button_ui->click = &MenuButtonClick;

    menu_button->AddComponent(menu_button_ui);
    menu_button->AddComponent(menu_button_sprite);

    AddEntity(menu_button);

    // Bottom Collider
    auto *bottom = new Entity;
    auto *bottom_collision = new CollisionComponent(Constants::SCREEN_WIDTH, 1);
    bottom->y = 416;
    bottom->AddComponent(bottom_collision);
    AddEntity(bottom);

    // Left Collider
    auto *left = new Entity;
    auto *left_collision = new CollisionComponent(1, Constants::SCREEN_HEIGHT);
    Utility::CenterEntity(left, RenderSystem::background, 1, Constants::SCREEN_HEIGHT);
    left->x = 207;
    left->AddComponent(left_collision);
    AddEntity(left);

    barrier_left = left;

    // Right Collider
    auto *right = new Entity;
    auto *right_collision = new CollisionComponent(1, Constants::SCREEN_HEIGHT);
    Utility::CenterEntity(right, RenderSystem::background, 1, Constants::SCREEN_HEIGHT);
    right->x = 432;
    right->AddComponent(right_collision);
    AddEntity(right);

    barrier_right = right;
    
    // Score
    auto *digit1 = new Entity;
    auto *digit2 = new Entity;
    auto *digit3 = new Entity;

    auto *digit1_sprite = new SpriteComponent(ResourceManager::GetImagePath("0"));
    auto *digit2_sprite = new SpriteComponent(ResourceManager::GetImagePath("0"));
    auto *digit3_sprite = new SpriteComponent(ResourceManager::GetImagePath("0"));

    digit1->y = 32;
    digit2->y = 32;
    digit3->y = 32;

    digit1->x = 564;
    digit2->x = 532;
    digit3->x = 500;

    digit1->AddComponent(digit1_sprite);
    digit2->AddComponent(digit2_sprite);
    digit3->AddComponent(digit3_sprite);

    AddEntity(digit1);
    AddEntity(digit2);
    AddEntity(digit3);

    score_sprites[0] = digit1_sprite;
    score_sprites[1] = digit2_sprite;
    score_sprites[2] = digit3_sprite;

    // Create block.
    SpawnInitialBlock();
}

void GameScene::OnUnload()
{
    // @TODO: abstract this?
    for (auto entity : entities) {
        delete entity;
    }
}

// Dumb collision detection. Relies on a few assumptions, including that we will never try to move "past" another collider.
// @TODO: Should probably generalize this a bit for the engine. But this works for Tetris. Also will need another solution for moving the block horizontally.
bool CollidesDown(Entity *source, Entity *other)
{
    auto *source_collision = source->GetComponent<CollisionComponent>();
    auto *other_collision = other->GetComponent<CollisionComponent>();

    if (source_collision == nullptr || other_collision == nullptr) {
        return false;
    }

    auto source_left = source->x + source_collision->x;
    auto source_right = source->x + source_collision->x + source_collision->w;
    auto source_bottom = source->y + source_collision->y + source_collision->h;

    auto other_left = other->x + other_collision->x;
    auto other_right = other->x + other_collision->x + other_collision->w;
    auto other_top = other->y + other_collision->y;

    return ((source_left < other_right && source_left >= other_left) || (source_right > other_left && source_right <= other_right)) && source_bottom == other_top;
}

bool CollidesLeft(Entity *source, Entity *other)
{
    auto *source_collision = source->GetComponent<CollisionComponent>();
    auto *other_collision = other->GetComponent<CollisionComponent>();

    if (source_collision == nullptr || other_collision == nullptr) {
        return false;
    }

    auto source_top = source->y + source_collision->y;
    auto source_bottom = source->y + source_collision->y + source_collision->h;
    auto source_left = source->x + source_collision->x;

    auto other_top = other->y + other_collision->y;
    auto other_bottom = other->y + other_collision->y + other_collision->h;
    auto other_right = other->x + other_collision->x + other_collision->w;

    return ((source_top < other_bottom && source_top >= other_top) || (source_bottom < other_top && source_bottom >= other_bottom)) && source_left == other_right;
}

bool CollidesRight(Entity *source, Entity *other)
{
    auto *source_collision = source->GetComponent<CollisionComponent>();
    auto *other_collision = other->GetComponent<CollisionComponent>();

    if (source_collision == nullptr || other_collision == nullptr) {
        return false;
    }

    auto source_top = source->y + source_collision->y;
    auto source_bottom = source->y + source_collision->y + source_collision->h;
    auto source_right = source->x + source_collision->x + source_collision->w;

    auto other_top = other->y + other_collision->y;
    auto other_bottom = other->y + other_collision->y + other_collision->h;
    auto other_left = other->x + other_collision->x;

    return ((source_top < other_bottom && source_top >= other_top) || (source_bottom < other_top && source_bottom >= other_bottom)) && source_right == other_left;
}

bool GameScene::CanMoveDirection(Direction direction)
{
    bool can_move = true;
    bool (*function)(Entity*, Entity*) = nullptr;

    switch (direction) {
        case DIRECTION_LEFT:
            function = &CollidesLeft;
            break;
        case DIRECTION_RIGHT:
            function = &CollidesRight;
            break;
        case DIRECTION_DOWN:
            function = &CollidesDown;
            break;
    }

    if (function == nullptr) {
        return false;
    }

    // @NOTE: When we implement block deletion, this will need to be updated so we aren't using dangling pointers.
    for (auto *block : current_block->entities) {
        for (auto *entity : this->entities) {
            if (std::find(current_block->entities.begin(), current_block->entities.end(), entity) != current_block->entities.end()) {
                continue;
            }

            if (function(block, entity)) {
                can_move = false; 
            }
        }
    }

    return can_move;
}

void GameScene::HandleBlockControl()
{
    if (EventSystem::IsKeyDown(SDL_SCANCODE_A) && CanMoveDirection(DIRECTION_LEFT)) {
        BlockTranslate(current_block, -SHIFT_AMOUNT, 0);
    }

    if (EventSystem::IsKeyDown(SDL_SCANCODE_D) && CanMoveDirection(DIRECTION_RIGHT)) {
        BlockTranslate(current_block, SHIFT_AMOUNT, 0);
    }

    if (current_block->type != "O-Block") {
        if (EventSystem::IsKeyDown(SDL_SCANCODE_Q)) {
            BlockRotateLeft(current_block);
        }

        if (EventSystem::IsKeyDown(SDL_SCANCODE_E)) {
            BlockRotateRight(current_block);
        }
    }
}

void GameScene::HandleBlockGravity(float elapsed)
{
    since_last_drop += elapsed;

    if (since_last_drop >= DROP_RATE) {
        if (!CanMoveDirection(DIRECTION_DOWN)) {
            SpawnBlock();
            return;
        }
        BlockTranslate(current_block, 0, DROP_AMOUNT);
        since_last_drop = 0;

    } else if (EventSystem::IsKeyDown(SDL_SCANCODE_S)) {
        while (CanMoveDirection(DIRECTION_DOWN)) {
            BlockTranslate(current_block, 0, DROP_AMOUNT);
        }
        SpawnBlock();
        since_last_drop = 0;
    }
}

void GameScene::UpdateScore()
{
    if (score >= 999) {
        for (auto *sprite : score_sprites) {
            SDL_FreeSurface(sprite->surface);
            sprite->surface = SDL_LoadBMP(ResourceManager::GetImagePath("9").c_str());
        }
    }

    int i = 0;
    int temp = score;

    while (temp > 0) {
        int digit = temp % 10;
        
        SDL_FreeSurface(score_sprites[i]->surface);

        auto path = ResourceManager::GetImagePath(std::to_string(digit)).c_str();
        score_sprites[i]->surface = SDL_LoadBMP(path);
        
        temp /= 10;
        i++;
    }
}

bool HasBlock(Composite *composite, Entity *entity)
{
    if (entity == nullptr) {
        return false;
    }

    return std::find(composite->entities.begin(), composite->entities.end(), entity) != composite->entities.end();
}

void GameScene::HandleScoring()
{
    Entity *fill_table[ROWS][COLS] = { nullptr };

    for (auto *entity : entities) {
        if (entity && entity->type == "Block" && !HasBlock(current_block, entity) && !HasBlock(next_block, entity)) {
            int row = ROWS - ((MAX_Y - entity->y) / DROP_AMOUNT) - 1;
            int col = (entity->x - MIN_X) / DROP_AMOUNT;
            fill_table[row][col] = entity;
        }
    }

    int rows_deleted_acc[ROWS];
    std::memset(rows_deleted_acc, 0, ROWS * sizeof(int));

    for (int i = ROWS - 1; i >= 0; i--) {
        if (i < ROWS - 1) {
            rows_deleted_acc[i] = rows_deleted_acc[i + 1];
        }

        bool row_filled = true;

        for (int j = 0; j < COLS; j++) {
            if (fill_table[i][j] == nullptr) {
                row_filled = false;
                break;
            }
        }

        if (row_filled) {
            score++;
            rows_deleted_acc[i] += 1;

            for (int j = 0; j < COLS; j++) {
                RemoveEntity(fill_table[i][j]);
            }
        }
    }

    if (rows_deleted_acc[0] > 0) {
        for (auto *entity : entities) {
            if (entity != nullptr && entity->type == "Block" && !HasBlock(current_block, entity) && !HasBlock(next_block, entity)) {
                entity->y += DROP_AMOUNT * rows_deleted_acc[ROWS - ((MAX_Y - entity->y) / DROP_AMOUNT) - 1];
            }
        }
        UpdateScore();
    }
}

void GameScene::Update(float elapsed)
{
    HandleBlockControl();
    HandleBlockGravity(elapsed);

    for (auto *entity : entities) {
        // @TODO: Better way to determine top of playing area.
        if (entity->type == "Block" && !HasBlock(current_block, entity) && entity->y <= 32) {
            auto *scene = new MainMenuScene;
            SceneSystem::Load(scene);
            return;
        }
    }

    HandleScoring();
}
