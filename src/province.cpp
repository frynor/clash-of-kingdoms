#include "../includes/province.hpp"
#include "../includes/ui.hpp"
#include <ncurses.h>
#include <vector>
#include <string>

Province::Province(std::string n, int p) : name(n), population(p) {
	updateIncome();
}

void Province::setName(std::string n) {
	name = n;
}

float Province::updateIncome() {
	income = population * incomeMultiplier;
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

void Province::increaseMultiplier() {
	if (incomeMultiplier < 0.00005f) {
		incomeMultiplier += 0.00001f;
		updateIncome();
	}
}

void Province::decreaseMultiplier() {
	if (incomeMultiplier > 0.00001f) {
		incomeMultiplier -= 0.00001f;
		updateIncome();
	}
}

float Province::getMultiplier() const {
	return incomeMultiplier;
}
