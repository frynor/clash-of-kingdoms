#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include "kingdom.hpp"
#include <ncurses.h>

int game_loop(int term_height, int term_width);
void show_stats(WINDOW *win, Kingdom& kingdom, int width);

#endif
