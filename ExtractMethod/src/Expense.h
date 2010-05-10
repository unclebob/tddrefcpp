

#pragma once


class Expense
{
public:
	enum ExpenseType {
		DINNER = 0,
		LUNCH = 1,
		BREAKFAST = 2,
		CAR_RENTAL = 3,
	};


						Expense(ExpenseType type, int amount);		
	int					getTotal() const;


	ExpenseType			type;
	int					amountInCents;

};


