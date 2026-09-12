#include "musicfolder_list.hpp"

MusicfolderList::MusicfolderList(ncpp::Plane* parent) : plane_(parent, 20, 30, 0, 0) {
}

void MusicfolderList::draw() {
    int y = 2;
    plane_.erase();

    plane_.putstr(0, 0, "songname");

    for (const auto& song : util::get_songs("musics")) {
        plane_.putstr(y, 0, song.c_str());
        y++;
    }
}
