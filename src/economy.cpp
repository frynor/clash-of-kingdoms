#include "../includes/economy.hpp"

Economy::Economy(float d, float i, float e) : denars(d), income(i), expenses(e) {}

void Economy::addIncome(float amount) {
	income += amount;
}

void Economy::addExpense(float amount) {
	expenses += amount;
}

float Economy::getIncome() const {
	return income;
}

float Economy::getDenars() const {
	return denars;
}

float Economy::getExpenses() const {
	return expenses;
}

void Economy::takeLoan(float amount) {
	denars += amount; 
}

void Economy::updateMonthly() {
	denars += income - expenses;
	income = 0.0f;
	expenses = 0.0f;
}


