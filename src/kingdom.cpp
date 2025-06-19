#include "../includes/kingdom.hpp"
#include "../includes/ui.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

Kingdom::Kingdom(std::string n, Economy e) : name(n), economy(e) {}

void Kingdom::collectTaxes() {
	economy.updateMonthly();
}

std::string Kingdom::displayStats() const {
	return "Denars: " + std::to_string(economy.getDenars()); 
}

void Kingdom::manageEconomy() {
	int win_height = 40;
	int win_width = 80;
	int term_height; int term_width;
	getmaxyx(stdscr, term_height, term_width);
	int start_y = (term_height - win_height) / 2;
	int start_x = (term_width - win_width) / 2;

	WINDOW *eco_win = newwin(win_height, win_width, start_y, start_x);
	box(eco_win, 0, 0);
	keypad(eco_win, TRUE);
	wrefresh(eco_win);

	// Economy Management Loop
	std::vector<std::string> options = {"Take a loan (50 denars)", "Lower the taxes", "Return back"};
	int highlight = 0;
	int option;


	while(true) {
		werase(eco_win);
		box(eco_win, 0, 0);

		for (int i = 0; i < options.size(); i++) {
			if (i == highlight) {
				wattron(eco_win, A_REVERSE);
			}
			center_text(eco_win, i + 1, options[i].c_str(), win_width);
			wattroff(eco_win, A_REVERSE);
		}
		wrefresh(eco_win);

		option = wgetch(eco_win);
		switch(option) {
			case KEY_UP:
				highlight--;
				if (highlight < 0) {
					highlight = options.size() - 1;
				}
				break;
			case KEY_DOWN:
				highlight++;
				if (highlight > options.size() - 1) {
					highlight = 0;
				}
				break;
			case 10:
				if (highlight == 0) {
					economy.takeLoan(50);
				} else if (highlight == 2) {
					werase(eco_win);
					wrefresh(eco_win);
					delwin(eco_win);
					return;
				}
				break;
		}
	}


	werase(eco_win);
	wrefresh(eco_win);
	delwin(eco_win);
}
