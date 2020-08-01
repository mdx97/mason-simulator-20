#include <iostream>
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

// @TODO: Should probably just get rid of this class and implement the following things...
// - Objects that can compose other objects.
// - Translation components for objects.
// - SpriteComponents get rendered in relation to the translation component of their parent object.
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
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 64;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("LightBlueBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateZBlock()
{
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->y -= 32;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("RedBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateJBlock()
{
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x -= 32;
    block2->y -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("BlueBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateLBlock()
{
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x += 32;
    block2->y -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("OrangeBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateOBlock()
{
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x += 32;
    block3->y -= 32;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("YellowBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateSBlock()
{
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->x += 32;
    block2->y -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("GreenBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->y -= 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
}

Block *GameScene::CreateTBlock()
{
    auto *block1 = new Object;
    auto *block1_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    Utility::CenterObject(block1, RenderSystem::background, block1_sprite->surface->w, block1_sprite->surface->h);
    block1->AddComponent(block1_sprite);
    AddObject(block1);

    auto *block2 = new Object;
    auto *block2_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    Utility::CenterObject(block2, RenderSystem::background, block2_sprite->surface->w, block2_sprite->surface->h);
    block2->y -= 32;
    block2->AddComponent(block2_sprite);
    AddObject(block2);

    auto *block3 = new Object;
    auto *block3_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    Utility::CenterObject(block3, RenderSystem::background, block3_sprite->surface->w, block3_sprite->surface->h);
    block3->x -= 32;
    block3->AddComponent(block3_sprite);
    AddObject(block3);

    auto *block4 = new Object;
    auto *block4_sprite = new SpriteComponent(ResourceManager::GetImagePath("PurpleBlock"));
    Utility::CenterObject(block4, RenderSystem::background, block4_sprite->surface->w, block4_sprite->surface->h);
    block4->x += 32;
    block4->AddComponent(block4_sprite);
    AddObject(block4);

    return new Block(block1, block2, block3, block4);
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
    current_block = CreateTBlock(); // @TODO: Spawn random block.
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
    static float since_last_drop = 0;
    
    since_last_drop += elapsed;

    if (since_last_drop >= drop_step) {
        current_block->Translate(0, 32);
        since_last_drop = 0;

        if (current_block->block1->y == min_y) {
            current_block = CreateOBlock(); // @TODO: Spawn random block.
        }
    }
}
