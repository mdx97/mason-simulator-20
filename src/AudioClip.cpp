#include "AudioClip.h"
#include "AudioSystem.h"

AudioClip::AudioClip(const std::string &filepath)
{
    // todo: handle error
    SDL_LoadWAV(filepath.c_str(), &audio_spec, &buffer, &length);
    Reset();
}

AudioClip::~AudioClip()
{
    SDL_FreeWAV(buffer);
}

// Populates the audio buffer (stream) with audio data to be played.
// Only works for a single traversal of the buffer.
void AudioClip::Callback(void *userdata, Uint8 *stream, int len)
{
    if (pointer >= buffer + length) {
        SDL_memset(stream, 0, len);
        AudioSystem::FreeClip(this);
        return;
    }

    for (int i = 0; i < len; i++) {
        stream[i] = (pointer < buffer + length) ? *pointer : 0;
        pointer++;
    }
}

void AudioClip::Reset()
{
    pointer = buffer;
}

// Populates the audio buffer (stream) with audio data to be played.
// Output loops back to the beginning when it reaches the end of the buffer.
void LoopedAudioClip::Callback(void *userdata, Uint8 *stream, int len)
{
    for (int i = 0; i < len; i++) {
        stream[i] = *pointer;
        pointer++;

        // If we have reached the end of our clip's audio buffer, wrap around to the beginning.
        if (pointer == buffer + length)
            pointer = buffer;
    }
}
