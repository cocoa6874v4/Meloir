#include "ui.hpp"

#include "../audio/player.hpp"
#include "music_list.hpp"
#include "musicfolder_list.hpp"
#include "now_playing.hpp"
#include <notcurses/nckeys.h>
#include <thread>
#include <unistd.h>

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
    const auto* song = musiclist.selected_song();

    while (true) {
        key = nc.get(false);

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

                if (song) {
                    player::load(song->string());
                    player::play();
                    nowplayingpanel.set_song(*song);
                }
            }
        }

        if (key == NCKEY_SPACE) {
            player::toggle_play();
        }

        musicfolderlist.draw();
        musiclist.draw();
        nowplayingpanel.draw_playing();

        if (player::get_current_time() == player::get_duration()) {
            musiclist.next_song();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        nc.render();
    }

    return 0;
}
