#include "getsong.hpp"

namespace util {
std::vector<fs::path> get_songs(const fs::path& folder) {
    std::vector<fs::path> songs;

    for (const auto& entry : fs::recursive_directory_iterator{folder}) {
        if (!entry.is_regular_file()) {
            continue;
        }

        const auto ext = entry.path().extension();

        if (ext == ".mp3" || ext == ".flac" || ext == ".wav" || ext == ".ogg") {
            songs.push_back(entry.path());
        }
    }

    return songs;
}
} // namespace util
