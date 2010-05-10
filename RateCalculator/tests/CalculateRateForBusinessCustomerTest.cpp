#include "CalculateRateForBusinessCustomerTest.h"

void CppUTestGroupCalculateRateForBusinessCustomerTest::setup() {
  CppUTestGroupCalculateRatesEmptyCustomerTest::setup();
  customer->type = Customer::business;
}

void CppUTestGroupCalculateRateForBusinessCustomerTest::addSite(int kwh) {
	Site *site = new Site();
	site->kwh = kwh;
	customer->sites.push_back(site);
}

TEST(CalculateRateForBusinessCustomerTest, emptyBusinessCustomerHas0Rate) {
	validateRate(0);
}

TEST(CalculateRateForBusinessCustomerTest, businessCustomerWithOne100KwhSiteHas100Rate) {
  addSite(100);
	validateRate(100);
}