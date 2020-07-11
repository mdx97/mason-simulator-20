#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include "engine/AudioClip.h"

namespace AudioSystem {
    void PlayClip(AudioClip *clip);
    void FreeClip(AudioClip *clip);
};

#endif
