#ifndef ECONOMY_HPP
#define ECONOMY_HPP

#include <string>

class Economy {
	private:
		int denars;
		int income;
		int expenses;
	public:
		Economy(int denars, int income, int expenses);

		void addIncome(int amount);
		void addExpense(int amount);
		void updateMonthly();

		int getDenars() const;
		int getIncome() const;
		int getExpenses() const;
		void takeLoan(int amount);
};


#endif
