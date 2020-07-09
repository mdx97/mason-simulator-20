#include "AudioClip.h"

LoopedAudioClip::LoopedAudioClip(const std::string &filepath)
{
    // todo: handle error
    SDL_LoadWAV(filepath.c_str(), &audio_spec, &buffer, &length);
}

LoopedAudioClip::~LoopedAudioClip()
{
    SDL_FreeWAV(buffer);
}

// Populates the audio buffer (stream) with audio data to be played.
void LoopedAudioClip::Callback(void *userdata, Uint8 *stream, int len)
{
    static Uint8 *pointer = buffer;

    for (int i = 0; i < len; i++) {
        stream[i] = *pointer;
        pointer++;

        // If we have reached the end of our clip's audio buffer, wrap around to the beginning.
        if (pointer == buffer + length)
            pointer = buffer;
    }
}
