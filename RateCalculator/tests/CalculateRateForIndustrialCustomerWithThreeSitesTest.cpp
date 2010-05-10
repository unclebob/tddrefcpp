#include "CalculateRateForIndustrialCustomerWithThreeSitesTest.h"

void CppUTestGroupCalculateRateForIndustrialCustomerWithThreeSitesTest::setup() {
  CppUTestGroupCalculateRateForIndustrialCustomerTest::setup();
	addSite(300);
	addSite(600);
	addSite(9700);
}

TEST(CalculateRateForIndustrialCustomerWithThreeSitesTest, industrialWith3SitesVariableKwh) {
	validateRate(10070);
}

TEST(CalculateRateForIndustrialCustomerWithThreeSitesTest, industrialInterruptable) {
	customer->industrialRate = Customer::interruptable;
	validateRate(8480);
}

TEST(CalculateRateForIndustrialCustomerWithThreeSitesTest, industrialOneHourNotice) {
	customer->industrialRate = Customer::oneHourNotice;
	validateRate(9540);
}

TEST(CalculateRateForIndustrialCustomerWithThreeSitesTest, industrialDefault) {
	customer->industrialRate = Customer::UNDEFINED;
	validateRate(10070);
}