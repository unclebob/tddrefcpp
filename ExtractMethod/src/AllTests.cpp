#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac, av);
}


