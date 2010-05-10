#include "CalculateRatesEmptyCustomerTest.h"

void CppUTestGroupCalculateRatesEmptyCustomerTest::setup() {
  customer = new Customer();
}

void CppUTestGroupCalculateRatesEmptyCustomerTest::teardown() {
  delete customer;
}

void CppUTestGroupCalculateRatesEmptyCustomerTest::validateRate(double expectedRate) {
	double actualRate = rateCalculator.calculateRate(*customer);
	CHECK_EQUAL(expectedRate, actualRate);
}

void CppUTestGroupCalculateRatesEmptyCustomerTest::setKwh(int kwh) {
	customer->kwh = kwh;
}

TEST(CalculateRatesEmptyCustomerTest, blankCustomerHas0Rate) {
	validateRate(0);
}