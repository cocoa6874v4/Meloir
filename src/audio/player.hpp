#pragma once

#include <string>

namespace player {

bool init();
bool load(const std::string& songname);

void play();
void pause();
void shutdown();
void toggle_play();
float get_current_time();
float get_duration();
bool is_finished();

} // namespace player
