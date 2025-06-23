#include "../includes/time.hpp"

using std::array;

Time::Time(int d, int m, int y, bool p, float t) : day(d), month(m), year(y),  pauseTime(p), timeScale(t) {}

const array<std::string, 12> Time::monthNames = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

void Time::advanceDay() { 
	if (!pauseTime) {
		day++;
		if (day > 30) {
			advanceMonth();
			day = 1;
		}
		if (month > 12) {
			advanceYear();
			month = 1;
		}
	}
}

void Time::advanceMonth() {
	month++;
}

void Time::advanceYear() {
	year++;
}

void Time::advanceTime() {
	if (pauseTime == false) {
		advanceDay();
		if (day > 30) {
			advanceMonth();
			day = 1;
		}
		if (month > 12) {
			advanceYear();
			month = 1;
		}
	}
}

void Time::pauseFalse() {
	pauseTime = false;
}

void Time::pauseTrue() {
	pauseTime = true;
}

void Time::increaseTimeScale() {
	if (timeScale == 0.0) {
		timeScale = 1.0;
	} else if (timeScale == 1.0) {
		timeScale = 2.0;
	} else if (timeScale == 2.0) {
		timeScale = 3.0;
	} else if (timeScale == 3.0) {
		timeScale = 4.0;
	} else if (timeScale == 4.0) {
		timeScale = 5.0;
	} else if (timeScale == 5.0) {
		timeScale = 10.0;
	}
}

void Time::decreaseTimeScale() {
	if (timeScale == 10.0) {
		timeScale = 5.0;
	} else if (timeScale == 5.0) {
		timeScale = 4.0;
	} else if (timeScale == 4.0) {
		timeScale = 3.0;
	} else if (timeScale == 3.0) {
		timeScale = 2.0;
	} else if (timeScale == 2.0) {
		timeScale = 1.0;
	} 
}

void Time::setTimeScale(float scale) {
	timeScale = scale;
}

void Time::setTickAccumulator(int scale) {
	tickAccumulator = scale;
}

std::string Time::getDateString() {
	std::string d = std::to_string(day);
	std::string m  = std::to_string(month);
	std::string y = std::to_string(year);

	return "Date: " + d + " " + monthNames[month - 1] + ", " + y;
}

int Time::getDay() const {
	return day;
}

int Time::getMonth() const {
	return month;
}

int Time::getYear() const {
	return year;
}

float Time::getTimeScale() const {
	return timeScale;
}

int Time::getTickAccumulator() const {
	return tickAccumulator;
}

bool Time::getPause() const {
	return pauseTime;
}
