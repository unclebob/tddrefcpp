


#include "Expense.h"



Expense::Expense(ExpenseType type, int amount)
: type(type), amountInCents(amount)
{
}

int Expense::getTotal() const
{
	return amountInCents;
}