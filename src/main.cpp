#include <csignal>
#include <cstring>
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "../includes/credits.hpp"
#include "../includes/menu.hpp"
#include "../includes/ui.hpp"
#include "../includes/game_loop.hpp"

int main() {
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	// Getting terminal dimensions
	int term_height, term_width;
	getmaxyx(stdscr, term_height, term_width);

	// Setting desired window dimensions
	int win_height = 10;
	int win_width = 30;

	// Calculating the center of the terminal/screen
	int start_y = (term_height - win_height) / 2;
	int start_x = (term_width - win_width) / 2;

	WINDOW *win = newwin(win_height, win_width, start_y, start_x);
	keypad(win, TRUE);
	refresh();


	// Setting up the menu for the game
	std::vector<std::string> choices = {"Start the game", "Settings", "Credits", "Exit"};

	while(true) {
		flushinp();
		int selected = run_menu(win, choices, win_width);

		if (selected == 0) {
			clear();
			refresh();
			game_loop(term_height, term_width);
			clear();
			refresh();
			werase(win);
			box(win, 0, 0);
			wrefresh(win);
		} else if (selected == 1) {
			// Settings
		} else if (selected == 2) {
			clear();
			refresh();
			show_credits(term_height, term_width);
			clear();
			refresh();
			werase(win);
			box(win, 0, 0);
			wrefresh(win);
		} else if (selected == 3) {
			break;
		}
	}


	wrefresh(win);
	delwin(win);
	endwin();

	return 0;
}
