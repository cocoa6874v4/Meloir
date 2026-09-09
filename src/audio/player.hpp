#pragma once

#include <string>

namespace player {

bool init();
bool load(const std::string& songname);

void play();
void pause();
void shutdown();

} // namespace player
