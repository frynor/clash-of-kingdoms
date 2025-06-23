#ifndef KINGDOM_HPP
#define KINGDOM_HPP

#include <string>
#include <iostream>
#include <vector>
#include "economy.hpp"
#include "province.hpp"

class Kingdom {
	private:
		std::string name;
		Economy economy;
		std::vector<Province> provinces;
	public:
		Kingdom(std::string name, Economy economy, std::vector<Province> provinces);
		Economy& getEconomy();
		void collectIncome();
		std::string displayDenars() const;
		std::string displayProvinces() const;
		void manageEconomy();
};

#endif

