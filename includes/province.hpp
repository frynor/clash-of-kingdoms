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
	public:
		Province(std::string name, int population);
		void setName(std::string n);
		void setPopulation(int p);
		void setIncome(float i);
		float updateIncome();
		std::string getName() const;
		float getIncome() const;
		int getPopulation() const;
		void manageProvinces();
};

#endif // PROVINCE_HPP
