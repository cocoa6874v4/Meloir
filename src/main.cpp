#include "audio/player.hpp"
#include <iostream>

int main() {
    if (!player::init()) {
        return 1;
    }

    if (!player::load("test.wav")) {
        player::shutdown();
        return 1;
    }

    player::play();

    int x;
    std::cin >> x;

    player::shutdown();
}
