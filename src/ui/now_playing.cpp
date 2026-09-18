#include "now_playing.hpp"
#include <ncpp/Plane.hh>

NowPlaying::NowPlaying(ncpp::Plane* parent) : plane_(parent, 20, 30, 0, 70) {
}

void NowPlaying::draw_playing() {
    plane_.erase();

    plane_.putstr(0, 0, "Playing");

    if (!song_.empty()) {
        const std::string name = song_.filename().string();
        plane_.putstr(2, 1, name.c_str());
    }
}

void NowPlaying::set_song(const fs::path& song) {
    song_ = song;
}
