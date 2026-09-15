#include "musicfolder_list.hpp"

#include "../util/getsong.hpp"
#include "draw_cursor.hpp"
#include <vector>

MusicfolderList::MusicfolderList(ncpp::Plane* parent)
    : plane_(parent, 20, 30, 0, 0), songs_(util::get_songs("musics")), selected_(0) {
}

void MusicfolderList::handle_input(uint32_t key) {
    if (key == 'j')
        move_down();
    if (key == 'k')
        move_up();
}

void MusicfolderList::draw() {
    int y = 2;
    plane_.erase();

    plane_.putstr(0, 0, "songname");

    for (const auto& song : songs_) {
        plane_.putstr(y, 1, song.c_str());
        y++;
    }

    ui::draw_cursor(plane_, selected_ + 2);
}

void MusicfolderList::move_down() {
    if (selected_ + 1 < songs_.size()) {
        selected_++;
    }
}
void MusicfolderList::move_up() {
    if (selected_ > 0) {
        selected_--;
    }
}
