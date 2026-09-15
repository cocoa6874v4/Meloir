#include "music_list.hpp"

#include "../util/getsong.hpp"
#include "draw_cursor.hpp"

MusicList::MusicList(ncpp::Plane* parent) : plane_(parent, 20, 40, 0, 30), selected_(0) {
}

void MusicList::set_folder(const fs::path& folder) {
    songs_ = util::get_songs(folder);
    selected_ = 0;
}

void MusicList::handle_input(uint32_t key) {
    if (key == 'j')
        move_down();

    if (key == 'k')
        move_up();
}

void MusicList::draw() {
    plane_.erase();

    plane_.putstr(0, 0, "Songs");

    int y = 2;

    for (const auto& song : songs_) {
        const std::string name = song.filename().string();

        plane_.putstr(y, 1, name.c_str());

        y++;
    }

    if (!songs_.empty()) {
        ui::draw_cursor(plane_, selected_ + 2);
    }
}

const fs::path* MusicList::selected_song() const {
    if (songs_.empty()) {
        return nullptr;
    }

    return &songs_[selected_];
}

void MusicList::move_down() {
    if (selected_ + 1 < songs_.size())
        selected_++;
}

void MusicList::move_up() {
    if (selected_ > 0)
        selected_--;
}
