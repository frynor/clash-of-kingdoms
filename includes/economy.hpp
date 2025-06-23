#ifndef ECONOMY_HPP
#define ECONOMY_HPP

#include <string>

class Economy {
	private:
		float denars;
		float income;
		float expenses;
	public:
		Economy(float denars, float income, float expenses);

		void addIncome(float amount);
		void addExpense(float amount);
		void updateMonthly();

		float getDenars() const;
		float getIncome() const;
		float getExpenses() const;
		void takeLoan(float amount);
};


#endif
