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
		int population;
		float incomeMultiplier = 0.00001f;
	public:
		Province(std::string name, int population);
		void setName(std::string n);
		void setPopulation(int p);
		float updateIncome();
		std::string getName() const;
		float getIncome() const;
		int getPopulation() const;
		void manageProvinces();
		void increaseMultiplier();
		void decreaseMultiplier();
		float getMultiplier() const;
};

#endif // PROVINCE_HPP
