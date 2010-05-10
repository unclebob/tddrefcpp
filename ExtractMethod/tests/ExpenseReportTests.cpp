
#include "ExpenseReport.h"
#include "MockReportPrinter.h"
#include "Expense.h"

#include "CppUTest/Extensions/SimpleStringExtensions.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(ExpenseReport)
{
  // put variables and methods for tests here.

  void setup() {
  }

  void teardown() {
  }

};

TEST(ExpenseReport, printEmpty)
{
	ExpenseReport report;
	MockReportPrinter printer;

	report.printOn(printer);

	CHECK_EQUAL("Expenses 9/12/2002\n\nMeal expenses $0.00\nTotal $0.00", printer.getText());
}


TEST(ExpenseReport, printTwoExpenses)
{
	ExpenseReport report;
	MockReportPrinter printer;
    report.addExpense(new Expense(Expense::DINNER,1678));
    report.printOn(printer);

    CHECK_EQUAL("Expenses 9/12/2002\nDinner\t$16.78\n\nMeal expenses $16.78\nTotal $16.78", printer.getText());

}