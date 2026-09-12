#pragma once

#include "../util/getsong.hpp"
#include <ncpp/Plane.hh>

class MusicfolderList {
  public:
    explicit MusicfolderList(ncpp::Plane* parent);

    void draw();

  private:
    ncpp::Plane plane_;
};
