#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace util {
struct SongStruct {
    std::string songname;
    std::filesystem::path path;
    int depth;
};

std::vector<fs::path> get_songs(const fs::path& folder);
} // namespace util
