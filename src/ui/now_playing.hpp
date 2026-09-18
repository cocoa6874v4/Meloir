#pragma once
#include <filesystem>
#include <ncpp/NotCurses.hh>
#include <ncpp/Plane.hh>
#include <string>

namespace fs = std::filesystem;

class NowPlaying {
  public:
    explicit NowPlaying(ncpp::Plane* parent);
    void draw_playing();
    void set_song(const fs::path& song);

  private:
    ncpp::Plane plane_;
    fs::path song_;
};
