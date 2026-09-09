#include "player.hpp"
#include "miniaudio.h"

#include <iostream>

namespace player {

ma_engine engine;
ma_sound sound;

bool loaded = false;

bool init() {
    if (ma_engine_init(nullptr, &engine) != MA_SUCCESS) {
        std::cerr << "failed to initialize engine\n";
        return false;
    }

    return true;
}

bool load(const std::string& songname) {
    if (loaded) {
        ma_sound_uninit(&sound);
        loaded = false;
    }

    if (ma_sound_init_from_file(&engine, songname.c_str(), 0, nullptr, nullptr, &sound) !=
        MA_SUCCESS) {
        std::cerr << "failed to load song\n";
        return false;
    }

    loaded = true;
    return true;
}

void play() {
    if (loaded) {
        ma_sound_start(&sound);
    }
}

void pause() {
    if (loaded) {
        ma_sound_stop(&sound);
    }
}

void shutdown() {
    if (loaded) {
        ma_sound_uninit(&sound);
        loaded = false;
    }

    ma_engine_uninit(&engine);
}

} // namespace player
