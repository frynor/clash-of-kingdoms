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
	public:
		Time(int day, int month, int year);
		void advanceDay();
		void advanceMonth();
		void advanceYear();
		void advanceTime();
		std::string getDateString();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		static const std::array<std::string, 12> monthNames;
};

#endif // TIME_HPP
