#include "music_list.hpp"

MusicList::MusicList(ncpp::Plane* parent) : plane_(parent, 20, 40, 0, 30) {
}

void MusicList::draw() {
    plane_.erase();

    plane_.putstr(0, 0, "now playing");
}
