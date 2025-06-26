#include "../includes/province.hpp"
#include "../includes/ui.hpp"
#include <ncurses.h>
#include <vector>
#include <string>

Province::Province(std::string n, int p) : name(n), population(p) {}

void Province::setName(std::string n) {
	name = n;
}

float Province::updateIncome() {
	income = population * 0.00001f;
	return income;
}

void Province::setPopulation(int p) {
	population = p;
}

std::string Province::getName() const {
	return name;
}

float Province::getIncome() const {
	return income;
}

int Province::getPopulation() const {
	return population;
}

void Province::setIncome(float p) {
	income = p;
	if (p > 0.00005f) {
		p = 0.00005f;
	} else if (p < 0.00001f) {
		p = 0.00001f;
	}
}
