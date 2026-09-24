#include "now_playing.hpp"
#include "../audio/player.hpp"
#include <ncpp/Plane.hh>

std::string format_time(float seconds) {
    int total = static_cast<int>(seconds);

    int minutes = total / 60;
    int secs = total % 60;

    char buf[16];
    std::snprintf(buf, sizeof(buf), "%02d:%02d", minutes, secs);

    return buf;
}

NowPlaying::NowPlaying(ncpp::Plane* parent) : plane_(parent, 20, 30, 0, 70) {
}

void NowPlaying::draw_playing() {
    plane_.erase();

    plane_.putstr(0, 0, "Playing");

    if (!song_.empty()) {
        const std::string name = song_.filename().string();
        plane_.putstr(2, 1, name.c_str());
    }

    const std::string current = format_time(player::get_current_time());
    const std::string duration = format_time(player::get_duration());

    const std::string time = current + " / " + duration;

    plane_.putstr(4, 1, time.c_str());
}

void NowPlaying::set_song(const fs::path& song) {
    song_ = song;
}
