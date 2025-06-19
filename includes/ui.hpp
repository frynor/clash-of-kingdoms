#ifndef UI_HPP
#define UI_HPP

#include <ncurses.h>
#include <cstring>

void center_text(WINDOW* win, int row, const char* text, int win_width);

#endif //UI_HPP
