#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <ncurses.h>

int run_menu(WINDOW* win, const std::vector<std::string>& choices, int win_width);

#endif
