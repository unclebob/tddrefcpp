#include "CalculateRateForIndustrialCustomerTest.h"

void CppUTestGroupCalculateRateForIndustrialCustomerTest::setup() {
  CppUTestGroupCalculateRateForBusinessCustomerTest::setup();
  customer->type = Customer::industrial;
}

TEST(CalculateRateForIndustrialCustomerTest, industrialWith0Sites0) {
	validateRate(0);
}

TEST(CalculateRateForIndustrialCustomerTest, industrialWith1Site100Kwh) {
	addSite(100);
	validateRate(95);
}