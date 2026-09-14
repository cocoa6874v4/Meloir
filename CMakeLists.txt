cmake_minimum_required(VERSION 3.21)

project(meloir LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    miniaudio
    GIT_REPOSITORY https://github.com/mackron/miniaudio.git
    GIT_TAG master
)

FetchContent_MakeAvailable(miniaudio)

find_package(PkgConfig REQUIRED)

pkg_check_modules(
    NOTCURSES
    REQUIRED
    IMPORTED_TARGET
    notcurses
)

add_executable(meloir
    src/audio/player.cpp
    src/main.cpp
    src/ui/musicfolder_list.cpp
    src/ui/music_list.cpp
    src/ui/ui.cpp
    src/util/getsong.cpp
    src/ui/draw_cursor.cpp
)

target_link_libraries(meloir
    PRIVATE
        miniaudio
        notcurses++
        notcurses
        notcurses-core
)
