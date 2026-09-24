#include "player.hpp"
#include "miniaudio.h"

#include <iostream>

namespace player {

ma_engine engine;
ma_sound sound;

bool loaded = false;
bool playing = false;

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
        playing = false;
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
        playing = true;
    }
}

void pause() {
    if (loaded) {
        ma_sound_stop(&sound);
        playing = false;
    }
}

void toggle_play() {
    if (playing)
        pause();
    else
        play();
}

void shutdown() {
    if (loaded) {
        ma_sound_uninit(&sound);
        loaded = false;
        playing = false;
    }

    ma_engine_uninit(&engine);
}

float get_current_time() {
    if (!loaded)
        return 0.0f;

    float seconds = 0.0f;
    ma_sound_get_cursor_in_seconds(&sound, &seconds);

    return seconds;
}

float get_duration() {
    if (!loaded)
        return 0.0f;

    float seconds = 0.0f;
    ma_sound_get_length_in_seconds(&sound, &seconds);

    return seconds;
}

} // namespace player
