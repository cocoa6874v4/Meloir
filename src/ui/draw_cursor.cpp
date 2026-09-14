#include "draw_cursor.hpp"
#include <ncpp/Plane.hh>

namespace ui {
void draw_cursor(ncpp::Plane& plane_, int selected) {
    plane_.putstr(selected, 0, ">");
}
} // namespace ui
