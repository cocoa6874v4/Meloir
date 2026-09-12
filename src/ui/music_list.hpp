#pragma once

#include <ncpp/Plane.hh>

class MusicList {
  public:
    explicit MusicList(ncpp::Plane* parent);
    void draw();

  private:
    ncpp::Plane plane_;
};
