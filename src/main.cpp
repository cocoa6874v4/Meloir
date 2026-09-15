#include "audio/player.hpp"
#include "ui/ui.hpp"
#include "util/getsong.hpp"

#include <ncpp/NotCurses.hh>

#include <iostream>
#include <vector>

int main() {
    if (!player::init()) {
        return 1;
    }

    int result = draw();

    player::shutdown();

    return result;
}
