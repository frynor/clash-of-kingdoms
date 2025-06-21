#include "../includes/time.hpp"

using std::array;

Time::Time(int d, int m, int y) : day(d), month(m), year(y) {}

const array<std::string, 12> Time::monthNames = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

void Time::advanceDay() { 
	day++;

}

void Time::advanceMonth() {
	month++;
}

void Time::advanceYear() {
	year++;
}

void Time::advanceTime() {
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


