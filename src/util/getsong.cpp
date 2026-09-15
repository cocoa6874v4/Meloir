#include "getsong.hpp"

namespace util {

FolderNode get_folder_tree(const fs::path& folder) {
    FolderNode node{.path = folder};

    for (const auto& entry : fs::directory_iterator{folder}) {
        if (entry.is_directory()) {
            node.children.push_back(get_folder_tree(entry.path()));
        }
    }

    return node;
}

std::vector<fs::path> get_songs(const fs::path& folder) {
    std::vector<fs::path> songs;

    for (const auto& entry : fs::directory_iterator{folder}) {
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
