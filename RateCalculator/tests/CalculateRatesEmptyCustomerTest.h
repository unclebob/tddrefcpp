#pragma once

#ifndef CalculateRatesEmptyCustomer_header
#define CalculateRatesEmptyCustomer_header

#include "RateCalculator.h"
#include "Customer.h"
#include "Site.h"
#include <CppUTest/TestHarness.h>


static TEST_GROUP(CalculateRatesEmptyCustomerTest) {
  virtual void setup();
  virtual void teardown();

 	void validateRate(double expectedRate);
	void setKwh(int kwh);

  RateCalculator rateCalculator;
	Customer *customer;
};

#endif