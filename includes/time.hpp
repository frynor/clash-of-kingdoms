#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <array>

class Time {
	private:
		int day;
		int month;
		int year;
		bool pauseTime;
	public:
		Time(int day, int month, int year, bool pauseTime);
		void advanceDay();
		void advanceMonth();
		void advanceYear();
		void advanceTime();
		void pauseFalse();
		void pauseTrue();
		std::string getDateString();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		bool getPause() const;
		static const std::array<std::string, 12> monthNames;
};

#endif // TIME_HPP
