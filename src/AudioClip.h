#ifndef AUDIOCLIP_H
#define AUDIOCLIP_H

#include "SDL.h"
#include <string>

class AudioClip
{
public:
    virtual void Callback(void *userdata, Uint8 *stream, int len) = 0;
};

class LoopedAudioClip : public AudioClip
{
public:
    LoopedAudioClip(const std::string &filepath);
    ~LoopedAudioClip();
    void Callback(void *userdata, Uint8 *stream, int len) override;

private:
    SDL_AudioSpec audio_spec;
    Uint8 *buffer;
    Uint32 length;
    
};

#endif
