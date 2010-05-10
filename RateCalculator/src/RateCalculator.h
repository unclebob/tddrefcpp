#ifndef RateCalculator_HPP
#define RateCalculator_HPP

struct Customer;

class RateCalculator {
	public:
		double calculateRate(Customer &customer);

	protected:
		bool isWinter();
		int calculateSlidingScale(int kwh);
		int calculateTerritory(int address);
};

#endif
