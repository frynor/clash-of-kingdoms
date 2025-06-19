#include "../includes/economy.hpp"

Economy::Economy(int d, int i, int e) : denars(d), income(i), expenses(e) {}

void Economy::addIncome(int amount) {
	income += amount;
}

void Economy::addExpense(int amount) {
	expenses += amount;
}

int Economy::getIncome() const {
	return income;
}

int Economy::getDenars() const {
	return denars;
}

int Economy::getExpenses() const {
	return expenses;
}

void Economy::takeLoan(int amount) {
	denars += amount; 
}

void Economy::updateMonthly() {
	denars += income - expenses;
}


