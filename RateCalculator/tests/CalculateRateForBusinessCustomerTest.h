#pragma once

#ifndef CalculateRateForBusinessCustomerTest_header
#define CalculateRateForBusinessCustomerTest_header

#include "CalculateRatesEmptyCustomerTest.h"

static TEST_GROUP_BASE(CalculateRateForBusinessCustomerTest, CppUTestGroupCalculateRatesEmptyCustomerTest)
{
public:
  virtual void setup();

  void addSite(int kwh);
};

#endif