#include <iostream>
#include "engine/CollisionComponent.h"
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

Block *GameScene::CreateRandomBlock()
{
    Block *block = (this->*block_spawners[std::rand() % COUNT_BLOCK_SPAWNERS])();
    block->Translate(0, -192);
    return block;
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

    // Create block.
    current_block = CreateRandomBlock(); // @TODO: Spawn random block.
}

void GameScene::OnUnload()
{
    // @TODO: abstract this?
    for (auto object : objects)
        delete object;
}

void GameScene::Update(float elapsed)
{
    // @TODO: Probably move these into constructor or OnLoad()?
    static const int drop_step = 1;
    static const int min_y = 384;
    static const int drop = 32;
    static float since_last_drop = 0;
    
    since_last_drop += elapsed;

    if (since_last_drop >= drop_step) {
        bool can_drop = true;
        auto *current_block_collider = current_block->block1->GetComponent<CollisionComponent>();

        for (auto *object : this->objects) {
            auto *collision_component = object->GetComponent<CollisionComponent>();
            if (collision_component != nullptr) {
                if (current_block->block1->y + current_block_collider->y + current_block_collider->h == object->y + collision_component->y) {
                    can_drop = false; 
                }
            }
        }

        if (!can_drop) {
            current_block = CreateRandomBlock();
            return;
        }

        current_block->Translate(0, drop);
        since_last_drop = 0;

        // @TODO: Add collider instead.
        if (current_block->block1->y == min_y) {
            current_block = CreateRandomBlock(); // @TODO: Spawn random block.
        }
    }
}
