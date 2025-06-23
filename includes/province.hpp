#ifndef PROVINCE_HPP
#define PROVINCE_HPP

#include <iostream>
#include <ncurses.h>
#include <string>
#include "../includes/economy.hpp"

class Province {
	private:
		std::string name;
		float income;
		float population;
	public:
		Province(std::string name, float population);
		void setName(std::string n);
		void setPopulation(float p);
		float updateIncome();
		std::string getName() const;
		float getIncome() const;
		float getPopulation() const;
};

#endif // PROVINCE_HPP
