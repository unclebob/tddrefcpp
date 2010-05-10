


#include "ExpenseReport.h"
#include "ReportPrinter.h"
#include "Expense.h"


ExpenseReport::ExpenseReport()
: currentDate("9/12/2002")
{}


ExpenseReport::~ExpenseReport()
{
	for (std::vector<Expense *>::iterator it = expenses.begin();
			it != expenses.end();
			++it) 
		delete *it;

}


void ExpenseReport::printOn(ReportPrinter& printer) 
{
    int total = 0;
    int mealExpenses = 0;

    printer.print("Expenses " + currentDate + "\n");

	for (std::vector<Expense *>::iterator it = expenses.begin();
			it != expenses.end();
			++it) 
	{
		Expense *currentExpense = *it;

        if (currentExpense->type == Expense::DINNER) 
		{
			char amount[30];
			sprintf(amount,"%3.2f",currentExpense->getTotal() / 100.0);
            printer.print(std::string("Dinner\t$") + std::string(amount) + std::string("\n"));
            mealExpenses += currentExpense->getTotal();
        }
        total += currentExpense->getTotal();	
	}

	char amount[30];
	sprintf(amount,"%3.2f", mealExpenses / 100.0);
    printer.print("\nMeal expenses $" + std::string(amount));

	sprintf(amount,"%3.2f", total / 100.0);
    printer.print("\nTotal $" + std::string(amount));

}



void ExpenseReport::addExpense(Expense *expense) 
{
	expenses.push_back(expense);
}