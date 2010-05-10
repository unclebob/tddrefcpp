

#pragma once
#include <cstdlib>
#include <vector>
#include <string>


class ReportPrinter;
class Expense;



class ExpenseReport
{
public:
									ExpenseReport();
									~ExpenseReport();

	void							printOn(ReportPrinter& printer);
	void							addExpense(Expense *expense);

private:
	std::string						currentDate;
	std::vector<Expense *>			expenses;
};