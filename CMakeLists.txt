cmake_minimum_required(VERSION 3.20)

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

add_executable(meloir
    src/audio/player.cpp
    src/main.cpp
)

target_link_libraries(meloir PRIVATE miniaudio)
