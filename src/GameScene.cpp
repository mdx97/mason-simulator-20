#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include "engine/CollisionComponent.h"
#include "engine/EventSystem.h"
#include "engine/Object.h"
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

const int DROP_RATE = 1;
const int DROP_AMOUNT = 32;
const int SHIFT_AMOUNT = 32;

// @TODO: Should probably just get rid of this class and implement Objects that can compose other objects.
class Block {
public:
    Object *block1, *block2, *block3, *block4;

    Block(Object *block1, Object *block2, Object *block3, Object *block4)
    {
        this->block1 = block1;
        this->block2 = block2;
        this->block3 = block3;
        this->block4 = block4;

        block1->type = "Block";
        block2->type = "Block";
        block3->type = "Block";
        block4->type = "Block";
    }

    void Translate(int x, int y)
    {
        block1->x += x;
        block2->x += x;
        block3->x += x;
        block4->x += x;

        block1->y += y;
        block2->y += y;
        block3->y += y;
        block4->y += y;
    }

    void RotateLeft()
    {
        std::vector<Object *> sub_blocks = { block2, block3, block4 };

        for (auto *block : sub_blocks) {
            int offset_x = block->x - block1->x;
            int offset_y = block->y - block1->y;
            block->x = block1->x + offset_y;
            block->y = block1->y + (offset_x * -1);
        }
    }

    void RotateRight()
    {
        std::vector<Object *> sub_blocks = { block2, block3, block4 };

        for (auto *block : sub_blocks) {
            int offset_x = block->x - block1->x;
            int offset_y = block->y - block1->y;
            block->x = block1->x - offset_y;
            block->y = block1->y - (offset_x * -1);
        }
    }

    bool HasBlock(Object *object)
    {
        if (object == nullptr) {
            return false;
        }

        return object == block1 || object == block2 || object == block3 || object == block4;
    }
};

void MenuButtonClick(Object *object)
{
    auto *scene = new MainMenuScene;
    SceneSystem::Load(scene);
}

// @TODO: Should refactor these functions out of this file, it kinda clutters it up.
Block *GameScene::CreateIBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);
    
    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 64;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);
    
    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);
    
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateZBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->y -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateJBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);
    
    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x -= 32;
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateLBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x += 32;
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateOBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x += 32;
    block3->y -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateSBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x += 32;
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->y -= 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateTBlock()
{
    // First block.
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block1_collision = new CollisionComponent(block1_sprite->surface->w, block1_sprite->surface->h);

    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);

    block1->AddComponent(block1_sprite);
    block1->AddComponent(block1_collision);

    AddObject(block1);

    // Second block.
    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block2_collision = new CollisionComponent(block2_sprite->surface->w, block2_sprite->surface->h);

    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;

    block2->AddComponent(block2_sprite);
    block2->AddComponent(block2_collision);

    AddObject(block2);

    // Third block.
    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block3_collision = new CollisionComponent(block3_sprite->surface->w, block3_sprite->surface->h);

    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;

    block3->AddComponent(block3_sprite);
    block3->AddComponent(block3_collision);

    AddObject(block3);

    // Fourth block.
    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    auto *block4_collision = new CollisionComponent(block4_sprite->surface->w, block4_sprite->surface->h);

    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;

    block4->AddComponent(block4_sprite);
    block4->AddComponent(block4_collision);

    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateRandomBlock()
{
    Block *block = (this->*block_spawners[std::rand() % COUNT_BLOCK_SPAWNERS])();
    block->Translate(0, -192); // @TODO: Find a better way to determine starting position.
    return block;
}

GameScene::GameScene()
{
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
    // Playing Area
    auto *area = new Object;
    auto *area_sprite = new SpriteComponent(ResourceManager::GetImagePath("PlayingArea"));
    Utility::CenterObject(area, RenderSystem::background, area_sprite->surface->w, area_sprite->surface->h);
    area->AddComponent(area_sprite);
    AddObject(area);
    
    // Menu Button
    auto *menu_button = new Object;
    auto *menu_button_sprite = new SpriteComponent(ResourceManager::GetImagePath("Menu"));

    auto *menu_button_ui = new UIComponent;
    menu_button_ui->hover_surface = SDL_LoadBMP(ResourceManager::GetImagePath("MenuHover").c_str());
    menu_button_ui->click = &MenuButtonClick;

    menu_button->AddComponent(menu_button_ui);
    menu_button->AddComponent(menu_button_sprite);

    AddObject(menu_button);

    // Bottom Collider
    auto *bottom = new Object;
    auto *bottom_collision = new CollisionComponent(Constants::SCREEN_WIDTH, 1);
    bottom->y = 416;
    bottom->AddComponent(bottom_collision);
    AddObject(bottom);

    // Left Collider
    auto *left = new Object;
    auto *left_collision = new CollisionComponent(1, Constants::SCREEN_HEIGHT);
    Utility::CenterObject(left, RenderSystem::background, 1, Constants::SCREEN_HEIGHT);
    left->x = 207;
    left->AddComponent(left_collision);
    AddObject(left);

    // Right Collider
    auto *right = new Object;
    auto *right_collision = new CollisionComponent(1, Constants::SCREEN_HEIGHT);
    Utility::CenterObject(right, RenderSystem::background, 1, Constants::SCREEN_HEIGHT);
    right->x = 432;
    right->AddComponent(right_collision);
    AddObject(right);

    // Create block.
    current_block = CreateRandomBlock();
}

void GameScene::OnUnload()
{
    // @TODO: abstract this?
    for (auto object : objects) {
        delete object;
    }
}

// Dumb collision detection. Relies on a few assumptions, including that we will never try to move "past" another collider.
// @TODO: Should probably generalize this a bit for the engine. But this works for Tetris. Also will need another solution for moving the block horizontally.
bool CollidesDown(Object *source, Object *other)
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

bool CollidesLeft(Object *source, Object *other)
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

bool CollidesRight(Object *source, Object *other)
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
    bool (*function)(Object*, Object*) = nullptr;

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
    std::vector<Object *> sub_blocks = {
        current_block->block1, current_block->block2, current_block->block3, current_block->block4
    };

    for (auto *block : sub_blocks) {
        for (auto *object : this->objects) {
            if (std::find(sub_blocks.begin(), sub_blocks.end(), object) != sub_blocks.end()) {
                continue;
            }

            if (function(block, object)) {
                can_move = false; 
            }
        }
    }

    return can_move;
}

void GameScene::HandleBlockControl()
{
    if (EventSystem::IsKeyDown(SDL_SCANCODE_A) && CanMoveDirection(DIRECTION_LEFT)) {
        current_block->Translate(-SHIFT_AMOUNT, 0);
    }

    if (EventSystem::IsKeyDown(SDL_SCANCODE_D) && CanMoveDirection(DIRECTION_RIGHT)) {
        current_block->Translate(SHIFT_AMOUNT, 0);
    }

    if (CanMoveDirection(DIRECTION_LEFT) && CanMoveDirection(DIRECTION_RIGHT)) {
        if (EventSystem::IsKeyDown(SDL_SCANCODE_Q)) {
            current_block->RotateLeft();
        }

        if (EventSystem::IsKeyDown(SDL_SCANCODE_E)) {
            current_block->RotateRight();
        }
    }
}

void GameScene::HandleBlockGravity(float elapsed)
{
    // @TODO: Probably move this into constructor or OnLoad()?
    static float since_last_drop = 0;
    
    since_last_drop += elapsed;

    if (since_last_drop >= DROP_RATE) {
        if (!CanMoveDirection(DIRECTION_DOWN)) {
            current_block = CreateRandomBlock();
            return;
        }
        current_block->Translate(0, DROP_AMOUNT);
        since_last_drop = 0;

    } else if (EventSystem::IsKeyDown(SDL_SCANCODE_S)) {
        while (CanMoveDirection(DIRECTION_DOWN)) {
            current_block->Translate(0, DROP_AMOUNT);
        }
        current_block = CreateRandomBlock();
        since_last_drop = 0;
    }
}

// @TODO: Clean this code up. Also, there may be an issue with blocks needing to fall more than the number of levels that were deleted? Not sure how this works in
// real tetris. Should research.
void GameScene::HandleScoring()
{
    static const int ROWS = 11;
    static const int COLS = 7;

    static const int MAX_Y = 384;
    static const int MIN_X = 208;

    Object *fill_table[ROWS][COLS] = { nullptr };

    for (auto *object : objects) {
        if (object && object->type == "Block" && !current_block->HasBlock(object)) {
            fill_table[ROWS - ((MAX_Y - object->y) / DROP_AMOUNT) - 1][(object->x - MIN_X) / DROP_AMOUNT] = object;
        }
    }

    int rows_deleted = 0;
    int min_delted_row_lvl = ROWS;

    for (int i = 0; i < ROWS; i++) {
        bool row_filled = true;

        for (int j = 0; j < COLS; j++) {
            if (fill_table[i][j] == nullptr) {
                row_filled = false;
                break;
            }
        }

        if (row_filled) {
            rows_deleted++;
            min_delted_row_lvl = std::min(min_delted_row_lvl, ROWS - i - 1);

            for (int j = 0; j < COLS; j++) {
                delete fill_table[i][j];
                RemoveObject(fill_table[i][j]);
            }
        }
    }

    if (rows_deleted > 0) {
        for (auto *object : objects) {
            if (object != nullptr && object->type == "Block" && !current_block->HasBlock(object) && MAX_Y - object->y > min_delted_row_lvl * DROP_AMOUNT) {
                object->y += DROP_AMOUNT * rows_deleted;
            }
        }
    }
}

void GameScene::Update(float elapsed)
{
    HandleBlockControl();
    HandleBlockGravity(elapsed);

    for (auto *object : objects) {
        // @TODO: Better way to determine top of playing area.
        if (object->type == "Block" && !current_block->HasBlock(object) && object->y <= 32) {
            auto *scene = new MainMenuScene;
            SceneSystem::Load(scene);
        }
    }

    HandleScoring();
}
