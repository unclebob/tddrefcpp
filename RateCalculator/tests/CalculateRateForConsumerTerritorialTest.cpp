#include "CalculateRateForConsumerTerritorialTest.h"

void CppUTestGroupCalculateRateForConsumerTerritorialTest::setup() {
  CppUTestGroupCalculateRatesEmptyCustomerTest::setup();
	customer->type = Customer::consumer;
	customer->rate = Customer::territorial;
	setKwh(500);
}

TEST(CalculateRateForConsumerTerritorialTest, territorial500KwhWithAddressCategory1) {
	customer->address = 1;
	validateRate(30);
}

TEST(CalculateRateForConsumerTerritorialTest, territorial500KwhAddressCategory3) {
	customer->address = 3;
	validateRate(32.5);
}