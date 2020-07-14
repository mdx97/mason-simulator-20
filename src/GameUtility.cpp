#include "engine/AudioSystem.h"
#include "engine/Object.h"
#include "engine/SpriteComponent.h"
#include "engine/UIComponent.h"
#include "Constants.h"
#include "GameUtility.h"

// todo: this may end up being some sort of global game state? depends on what other
// parts of the application needs to access this value.
bool muted = false;
SDL_Surface *sound_surface = nullptr;
SDL_Surface *muted_surface = nullptr;

// Click handler for the sound toggle control.
void ToggleSound(Object *object)
{
    muted = !muted;
    AudioSystem::ToggleSound(!muted);
    auto *sprite = object->GetComponent<SpriteComponent>();
    if (sprite != nullptr) 
        sprite->surface = !muted ? sound_surface : muted_surface;
}

// Adds the sound control that is shared across both scenes.
// todo: This function should be completely temporary as I plan on
// adding a way to create objects that persist across scene changes.
Object *GameUtility::CreateSoundControl()
{
    auto *sound = new Object;
    auto *sound_sprite = new SpriteComponent(!muted ? Constants::SOUND_TOGGLE_ON : Constants::SOUND_TOGGLE_OFF);
    auto *sound_ui = new UIComponent;
    sound_sprite->rect.x = 611;
    sound_sprite->rect.y = 5;
    sound_ui->click = &ToggleSound;
    sound->AddComponent(sound_sprite);
    sound->AddComponent(sound_ui);

    if (sound_surface == nullptr) {
        sound_surface = sound_sprite->surface;
        muted_surface = SDL_LoadBMP(Constants::SOUND_TOGGLE_OFF.c_str());
    }

    return sound;
}
