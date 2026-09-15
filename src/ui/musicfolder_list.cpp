#include "musicfolder_list.hpp"

#include "draw_cursor.hpp"

MusicfolderList::MusicfolderList(ncpp::Plane* parent)
    : plane_(parent, 20, 30, 0, 0), tree_(util::get_folder_tree("musics")), selected_(0) {
    build_visible(tree_, 0);
}

void MusicfolderList::build_visible(const util::FolderNode& node, int depth) {
    for (const auto& child : node.children) {
        visible_.push_back({.node = &child, .depth = depth});

        build_visible(child, depth + 1);
    }
}

void MusicfolderList::handle_input(uint32_t key) {
    if (key == 'j')
        move_down();

    if (key == 'k')
        move_up();
}

void MusicfolderList::draw() {
    plane_.erase();

    plane_.putstr(0, 0, "Folders");

    int y = 2;

    for (const auto& folder : visible_) {
        std::string line(folder.depth * 2, ' ');

        line += folder.node->path.filename().string();

        plane_.putstr(y, 1, line.c_str());

        y++;
    }

    ui::draw_cursor(plane_, selected_ + 2);
}

const fs::path& MusicfolderList::selected_folder() const {
    return visible_[selected_].node->path;
}

void MusicfolderList::move_down() {
    if (selected_ + 1 < visible_.size())
        selected_++;
}

void MusicfolderList::move_up() {
    if (selected_ > 0)
        selected_--;
}
