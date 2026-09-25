#pragma once

#include <filesystem>
#include <ncpp/Plane.hh>
#include <vector>

namespace fs = std::filesystem;

class MusicList {
  public:
    explicit MusicList(ncpp::Plane* parent);

    void set_folder(const fs::path& folder);

    void handle_input(uint32_t key);
    void draw();

    void move_down();
    void move_up();
    const fs::path* selected_song() const;
    const fs::path* next_song();
    const fs::path* previous_song();

  private:
    ncpp::Plane plane_;

    std::vector<fs::path> songs_;
    int selected_;
};
