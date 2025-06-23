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
		float timeScale;
		int tickAccumulator;
		bool pauseTime;
	public:
		Time(int day, int month, int year, bool pauseTime, float timeScale);
		void advanceDay();
		void advanceMonth();
		void advanceYear();
		void advanceTime();
		void pauseFalse();
		void pauseTrue();
		void increaseTimeScale();
		void decreaseTimeScale();
		void setTimeScale(float scale);
		void setTickAccumulator(int scale);
		std::string getDateString();
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		float getTimeScale() const;
		int getTickAccumulator() const;
		bool getPause() const;
		static const std::array<std::string, 12> monthNames;
};

#endif // TIME_HPP
