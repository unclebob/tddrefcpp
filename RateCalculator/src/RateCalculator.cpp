#include "RateCalculator.h"
#include "Customer.h"
#include "Site.h"

// This method is stubbed from the original to simplify the problem
bool RateCalculator::isWinter() {
	return false;
}

// This method is stubbed from the original to simplify the problem
int RateCalculator::calculateSlidingScale(int kwh) {
	return kwh;
}

// This method is stubbed from the original to simplify the problem
int RateCalculator::calculateTerritory(int address) {
	return address;
}

double RateCalculator::calculateRate(Customer &c) {
	double rate = 0;
	switch(c.type) {
		case Customer::consumer: switch(c.rate) {
			case Customer::lifeline: if(c.kwh <= 100) {
				rate = c.kwh * .03;
				break;
			}
			 else if(c.kwh <= 200) {
				rate = 3+(c.kwh - 100) *.05;
				break;
			}
			// Customer does not qualify for lifline, 
			// fall through to territorial case. 
			case Customer::territorial: switch(calculateTerritory(c.address)) {
				case 1:
					// spec says territory 1 and 2 use same rate. 
				case 2:
					rate = c.kwh *(isWinter() ? .07 : .06);
					break;
				case 3:
					rate = c.kwh * .065;
					break;
				}
				break;
			}
			break; // consumer 
			case Customer::business: 
         case Customer::industrial: 
            for(Customer::c_site::iterator i = c.sites.begin(); i != c.sites.end(); ++i) {
				   Site *s =  *i;
				   rate += calculateSlidingScale(s->kwh);
			   }
			   if(c.type == Customer::industrial)
			      switch(c.industrialRate) {
				      case Customer::interruptable: rate *= .8;
				      break;
				      case Customer::oneHourNotice: rate *= .9;
				      break;
			      default:
				      rate *= .95;
				      break;
			      } // industrial rate 
			break; // business + industrial
	} // customer.type 
	return rate;
}
