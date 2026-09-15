#pragma once

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

namespace util {

struct FolderNode {
    fs::path path;
    std::vector<FolderNode> children;
};

FolderNode get_folder_tree(const fs::path& folder);

std::vector<fs::path> get_songs(const fs::path& folder);

} // namespace util
