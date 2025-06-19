#include "../includes/ui.hpp"

void center_text(WINDOW *win, int row, const char *text, int win_width) {
	int x = (win_width - strlen(text)) / 2;
	mvwprintw(win, row, x, "%s", text);
}

