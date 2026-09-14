#include "ui.hpp"

#include "music_list.hpp"
#include "musicfolder_list.hpp"

int draw() {
    enum class Focus { FolderList, MusicList };

    Focus focus = Focus::FolderList;

    ncpp::NotCurses nc;

    ncpp::Plane* stdplane = nc.get_stdplane();

    if (!stdplane)
        return 1;

    MusicList musiclist(stdplane);
    MusicfolderList musicfolderlist{stdplane};

    musiclist.draw();
    musicfolderlist.draw();

    nc.render();
    uint32_t key;

    while (true) {
        key = nc.get(true);

        if (key == 'q')
            break;

        if (focus == Focus::FolderList) {
            musicfolderlist.handle_input(key);
        }

        if (focus == Focus::MusicList) {
            // musiclist
        }

        musicfolderlist.draw();
        musiclist.draw();

        nc.render();
    }

    return 0;
}
