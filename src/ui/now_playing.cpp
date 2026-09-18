#include "now_playing.hpp"
#include <ncpp/Plane.hh>

NowPlaying::NowPlaying(ncpp::Plane* parent) : plane_(parent, 20, 30, 0, 70) {
}

void NowPlaying::draw_playing() {
    plane_.erase();

    plane_.putstr(0, 0, "Playing");
}
