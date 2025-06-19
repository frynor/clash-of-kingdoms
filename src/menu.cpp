#include "../includes/menu.hpp"
#include "../includes/ui.hpp"

int run_menu(WINDOW* win, const std::vector<std::string>& choices, int win_width) {
	int highlight = 0;
	int choice;

	while(true) {
		werase(win);
		box(win, 0, 0);

		for (int i = 0; i < choices.size(); i++) {
			if (i == highlight) {
				wattron(win, A_REVERSE);
			}
			center_text(win, i + 1, choices[i].c_str(), win_width);
			wattroff(win, A_REVERSE);
		}
		wrefresh(win);

		choice = wgetch(win);
		switch(choice) {
			case KEY_UP:
				highlight--;
				if (highlight < 0) {
					highlight = choices.size() - 1;
				}
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight > choices.size() - 1) {
					highlight = 0;
				}
				break;
			case 10:
				return highlight;
		}
	}
}
