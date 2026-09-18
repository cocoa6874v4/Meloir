#include "ui.hpp"

#include "../audio/player.hpp"
#include "music_list.hpp"
#include "musicfolder_list.hpp"
#include "now_playing.hpp"

int draw() {
    enum class Focus { FolderList, MusicList };

    Focus focus = Focus::FolderList;

    ncpp::NotCurses nc;

    ncpp::Plane* stdplane = nc.get_stdplane();

    if (!stdplane)
        return 1;

    MusicList musiclist(stdplane);
    MusicfolderList musicfolderlist{stdplane};
    NowPlaying nowplayingpanel(stdplane);

    musiclist.draw();
    musicfolderlist.draw();
    nowplayingpanel.draw_playing();

    nc.render();
    uint32_t key;

    while (true) {
        key = nc.get(true);

        if (key == 'q')
            break;

        if (focus == Focus::FolderList) {
            musicfolderlist.handle_input(key);

            if (key == 'l') {
                musiclist.set_folder(musicfolderlist.selected_folder());

                focus = Focus::MusicList;
            }
        }

        else if (focus == Focus::MusicList) {
            musiclist.handle_input(key);

            if (key == 'h') {
                focus = Focus::FolderList;
            }
            if (key == NCKEY_ENTER) {
                const auto* song = musiclist.selected_song();

                if (song) {
                    player::load(song->string());
                    player::play();
                }
            }
        }

        musicfolderlist.draw();
        musiclist.draw();
        nowplayingpanel.draw_playing();

        nc.render();
    }

    return 0;
}
