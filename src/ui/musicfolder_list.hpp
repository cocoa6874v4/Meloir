#pragma once

#include "../util/getsong.hpp"
#include <filesystem>
#include <ncpp/Plane.hh>
#include <vector>

class MusicfolderList {
  public:
    explicit MusicfolderList(ncpp::Plane* parent);

    void handle_input(uint32_t key);
    void draw();

    void move_down();
    void move_up();
    const fs::path& selected_folder() const;

  private:
    struct VisibleFolder {
        const util::FolderNode* node;
        int depth;
    };

    void build_visible(const util::FolderNode& node, int depth);

    ncpp::Plane plane_;

    util::FolderNode tree_;
    std::vector<VisibleFolder> visible_;

    int selected_;
};
