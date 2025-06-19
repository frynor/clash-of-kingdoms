#include "../includes/credits.hpp"
#include "../includes/ui.hpp"
#include <ncurses.h>

void show_credits(int term_height, int term_width) {
	int win_height = 10;
	int win_width = 40;
	int start_y = (term_height - win_height) / 2;
	int start_x = (term_width - win_width) / 2;

	WINDOW* credits_win = newwin(win_height, win_width, start_y, start_x);
	box(credits_win, 0, 0);
	keypad(credits_win, TRUE);
	wrefresh(credits_win);

	center_text(credits_win, 1, "Main Scripter: frynor", win_width);
	center_text(credits_win, 2, "Main Designer: frynor", win_width);
	wattron(credits_win, A_REVERSE);
	center_text(credits_win, win_height - 2, "Back", win_width);
	wattroff(credits_win, A_REVERSE);

	wrefresh(credits_win);

	int key;
	while ((key = wgetch(credits_win)) != '\n' && key != '\r' && key != KEY_ENTER) {

	}

	werase(credits_win);
	wrefresh(credits_win);
	delwin(credits_win);
}
