#include "../includes/province.hpp"

Province::Province(std::string n, float p) : name(n), population(p) {}

void Province::setName(std::string n) {
	name = n;
}

float Province::updateIncome() {
	income = population * 0.00001f;
	return income;
}

void Province::setPopulation(float p) {
	population = p;
}

std::string Province::getName() const {
	return name;
}

float Province::getIncome() const {
	return income;
}

float Province::getPopulation() const {
	return population;
}
