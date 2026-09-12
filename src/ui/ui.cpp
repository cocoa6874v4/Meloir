#include "ui.hpp"

#include "music_list.hpp"
#include "musicfolder_list.hpp"

int draw() {
    ncpp::NotCurses nc;

    ncpp::Plane* stdplane = nc.get_stdplane();

    if (!stdplane)
        return 1;

    MusicList musiclist(stdplane);
    MusicfolderList musicfolderlist{stdplane};

    musiclist.draw();
    musicfolderlist.draw();

    nc.render();

    while (true) {
        uint32_t key = nc.get(true);

        if (key == 'q')
            break;
    }
    return 0;
}
