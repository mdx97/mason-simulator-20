#include "AudioClip.h"

LoopedAudioClip::LoopedAudioClip(const std::string &filepath)
{
    // todo: handle error
    SDL_LoadWAV(filepath.c_str(), &audio_spec, &buffer, &length);
}

void LoopedAudioClip::Callback(void *userdata, Uint8 *stream, int len)
{
    static Uint8 *pointer = buffer;

    for (int i = 0; i < len; i++) {
        stream[i] = *pointer;
        pointer++;
        if (pointer == buffer + length)
            pointer = buffer;
    }
}
