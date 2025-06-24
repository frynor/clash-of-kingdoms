#include "../includes/kingdom.hpp"
#include "../includes/ui.hpp"
#include "../includes/province.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <sstream>

Kingdom::Kingdom(std::string n, Economy e, std::vector<Province> p) : name(n), economy(e), provinces(p) {}

void Kingdom::collectIncome() {
	float totalIncome = 0;
	for (Province& p : provinces) {
		totalIncome += p.updateIncome();
	}
	economy.addIncome(totalIncome);
	economy.updateMonthly();
}

std::string Kingdom::displayDenars() const {
	std::ostringstream oss;
	oss.precision(2);
	oss << std::fixed;
	oss << "Denars: " << economy.getDenars();
	return oss.str();
}

std::string Kingdom::displayProvinces() const {
	return "Provinces: " + std::to_string(provinces.size());
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

Economy& Kingdom::getEconomy() {
	return economy;
}

void Kingdom::manageProvinces() {
	int win_height = 40, win_width = 80;
	int term_height, term_width;
	getmaxyx(stdscr, term_height, term_width);
	int start_y = (term_height - win_height) / 2;
	int start_x = (term_width - win_width) / 2;

	WINDOW *prov_win = newwin(win_height, win_width, start_y, start_x);
	box(prov_win, 0, 0);
	keypad(prov_win, TRUE);
	wrefresh(prov_win);

	int highlight = 0;        // Which province
	int actionHighlight = 0;  // 0 = "+", 1 = "-"

	while (true) {
		werase(prov_win);
		box(prov_win, 0, 0);

		for (int i = 0; i < provinces.size(); ++i) {
			int y = 2 + i * 3;
			std::string text = provinces[i].getName() + " - Population: " + std::to_string(provinces[i].getPopulation());
			mvwprintw(prov_win, y, 2, "%s", text.c_str());

			// Draw + and - next to the province
			if (i == highlight) {
				if (actionHighlight == 0) wattron(prov_win, A_REVERSE);
				mvwprintw(prov_win, y, win_width - 10, "+");
				if (actionHighlight == 0) wattroff(prov_win, A_REVERSE);

				if (actionHighlight == 1) wattron(prov_win, A_REVERSE);
				mvwprintw(prov_win, y, win_width - 8, "-");
				if (actionHighlight == 1) wattroff(prov_win, A_REVERSE);
			} else {
				mvwprintw(prov_win, y, win_width - 10, "+");
				mvwprintw(prov_win, y, win_width - 8, "-");
			}
		}

		center_text(prov_win, win_height - 3, "Arrow keys to navigate, ENTER to apply, ESC to return", win_width);
		wrefresh(prov_win);

		int ch = wgetch(prov_win);
		switch (ch) {
			case KEY_UP:
				highlight = (highlight - 1 + provinces.size()) % provinces.size();
				break;
			case KEY_DOWN:
				highlight = (highlight + 1) % provinces.size();
				break;
			case KEY_LEFT:
				actionHighlight = (actionHighlight == 0) ? 1 : 0;
				break;
			case KEY_RIGHT:
				actionHighlight = (actionHighlight == 0) ? 1 : 0;
				break;
			case 10: { // ENTER
				int pop = provinces[highlight].getPopulation();
				if (actionHighlight == 0) {
					provinces[highlight].setPopulation(pop + 1000);
				} else {
					if (pop > 1000) provinces[highlight].setPopulation(pop - 1000);
				}
				break;
			}
			case 27: // ESC
				werase(prov_win);
				wrefresh(prov_win);
				delwin(prov_win);
				return;
		}
	}
}

