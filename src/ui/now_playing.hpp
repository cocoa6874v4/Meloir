#pragma once
#include <ncpp/NotCurses.hh>
#include <ncpp/Plane.hh>
#include <string>

class NowPlaying {
  public:
    explicit NowPlaying(ncpp::Plane* parent);
    void draw_playing();

  private:
    ncpp::Plane plane_;
};
