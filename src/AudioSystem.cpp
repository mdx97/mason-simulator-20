#include "AudioSystem.h"

AudioClip *playing;

void AudioCallback(void *userdata, Uint8 *stream, int len)
{
    // todo: support concurrent tracks.
    playing->Callback(userdata, stream, len);
}

// Begins playing the given audio clip.
void AudioSystem::PlayClip(AudioClip *clip)
{
    // todo: handle errors.
    const char *device = SDL_GetAudioDeviceName(0, 0);

    // todo: pull this stuff out into constants.
    SDL_AudioSpec want, have;
    SDL_zero(want);
    want.freq = 44100;
    want.format = AUDIO_S16;
    want.channels = 2;
    want.samples = 4096;
    want.callback = &AudioCallback;

    // todo: handle errors.
    SDL_AudioDeviceID device_id = SDL_OpenAudioDevice(device, 0, &want, &have, 0);
    SDL_PauseAudioDevice(device_id, 0);
    playing = clip;
}
