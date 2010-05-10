#include "CalculateRateForConsumerLifelineTest.h"

void CppUTestGroupCalculateRateForConsumerLifelineTest::setup() {
  CppUTestGroupCalculateRatesEmptyCustomerTest::setup();
  customer->address = 1;
	customer->type = Customer::consumer;
	customer->rate = Customer::lifeline;
}

TEST(CalculateRateForConsumerLifelineTest, lifeline200Kwh) {
	setKwh(200);
	validateRate(8);
}

TEST(CalculateRateForConsumerLifelineTest, lifeline100Kwh) {
	setKwh(100);
	validateRate(3);
}

TEST(CalculateRateForConsumerLifelineTest, lifeline500KwhSameAsTerritorial) {
	setKwh(500);
	validateRate(30);
}
