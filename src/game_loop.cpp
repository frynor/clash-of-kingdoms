#include "../includes/game_loop.hpp"
#include "../includes/ui.hpp"
#include "../includes/kingdom.hpp"
#include "../includes/economy.hpp"
#include "../includes/time.hpp"
#include <ncurses.h>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

void show_stats(WINDOW* win, Kingdom& kingdom, int width) {
	werase(win);
	box(win, 0, 0);
	
	center_text(win, 1, kingdom.displayStats().c_str(), width);
	center_text(win, 3, "Press any key to return", width);
	wrefresh(win);
	wgetch(win);
}

int game_loop(int term_height, int term_width) {
	int win_height = 40;
	int win_width = 80;
	int start_y = (term_height - win_height) / 2;
	int start_x = (term_width - win_width) / 2;

	WINDOW *game_win = newwin(win_height, win_width, start_y, start_x);
	box(game_win, 0, 0);
	keypad(game_win, TRUE);
	nodelay(game_win, TRUE);
	wrefresh(game_win);

	Economy economy(1000, 100, 50);
	Kingdom kingdom("My Kingdom", economy);
	Time gameTime(1, 1, 1000, false, 1.0);

	std::vector<std::string> options = {"Manage an economy", "Show stats", "Exit to the menu"};
	int highlight = 0;
	int option;
	auto lastTick = std::chrono::steady_clock::now();
	double tickAccumulator = 0.0;
	const int tickDuration = 1000;

	while(true) {
		werase(game_win);
		box(game_win, 0, 0);

		std::string dateString = gameTime.getDateString();
		mvwprintw(game_win, win_height - 2, 2, "%s", dateString.c_str());

		std::string scaleString = "Speed: " + std::to_string(static_cast<int>(gameTime.getTimeScale())) + "x";
		mvwprintw(game_win, win_height - 4, 2, "%s", scaleString.c_str());

		if (gameTime.getPause()) {
			mvwprintw(game_win, win_height - 3, 2, "[PAUSED]");
		}

		for (int i = 0; i < options.size(); i++) {
			if (i == highlight) {
				wattron(game_win, A_REVERSE);
			}
			center_text(game_win, i + 1, options[i].c_str(), win_width);
			wattroff(game_win, A_REVERSE);
		}
		wrefresh(game_win);

		auto now = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTick);
		tickAccumulator += elapsed.count() * gameTime.getTimeScale();

		while (tickAccumulator >= tickDuration) {
			if (!gameTime.getPause()) {
				gameTime.advanceDay();
			}
			tickAccumulator -= tickDuration;
		}
		lastTick = now;


		option = wgetch(game_win);
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
					kingdom.manageEconomy();
					werase(game_win);
					box(game_win, 0, 0);
					wrefresh(game_win);
				} else if (highlight == 1) {
					nodelay(game_win, FALSE);
					show_stats(game_win, kingdom, win_width);
					nodelay(game_win, TRUE);
				} else if (highlight == 2) {
					werase(game_win);
					wrefresh(game_win);
					delwin(game_win);
					return 0;
				}
				break;
			case 32:
				if (gameTime.getPause() == false) {
					gameTime.pauseTrue();
				} else {
					gameTime.pauseFalse();
				}
				break;
			case KEY_RIGHT:
				gameTime.increaseTimeScale();
				break;
			case KEY_LEFT:
				gameTime.decreaseTimeScale();
				break;	
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

}
