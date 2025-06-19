#ifndef KINGDOM_HPP
#define KINGDOM_HPP

#include <string>
#include "economy.hpp"

class Kingdom {
	private:
		std::string name;
		Economy economy;
	public:
		Kingdom(std::string name, Economy economy);
		void collectTaxes();
		std::string displayStats() const;
		void manageEconomy();
};

#endif

