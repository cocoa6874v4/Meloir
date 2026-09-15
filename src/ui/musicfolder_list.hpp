#pragma once

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
    std::vector<std::filesystem::path> songs_;

  private:
    ncpp::Plane plane_;
    int selected_;
};
