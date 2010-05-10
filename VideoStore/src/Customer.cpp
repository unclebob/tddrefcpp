#include "Customer.h"
#include "Movie.h"
#include "Rental.h"
#include <sstream>
using namespace std;

Customer::Customer(const string& name) : name(name)
{
}

Customer::~Customer()
{
  for(Iter iter = rentals.begin(); iter != rentals.end(); ++iter)
    delete *iter;
}

void Customer::addRental(Rental* rental) {
  rentals.push_back(rental);
}

string Customer::statement() {
		double totalAmount = 0;
		int frequentRenterPoints 	= 0;
    ostringstream result;
    result << "Rental Record for " << getName () << "\n";
		
    for(Iter iter = rentals.begin(); iter != rentals.end(); ++iter) {
			double thisAmount = 0;
			Rental* each = *iter;
			
			// determines the amount for each line
			switch (each->getMovie()->getPriceCode()) {
        case Movie::Regular:
					thisAmount += 2;
					if (each->getDaysRented () > 2)
						thisAmount += (each->getDaysRented () - 2) * 1.5;
					break;
        case Movie::NewRelease:
					thisAmount += each->getDaysRented () * 3;
					break;
        case Movie::Childrens:
					thisAmount += 1.5;
					if (each->getDaysRented () > 3)
						thisAmount += (each->getDaysRented () - 3) * 1.5;
					break;
			}
			
			frequentRenterPoints++;
			
      if (each->getMovie()->getPriceCode() == Movie::NewRelease && each->getDaysRented () > 1)
				frequentRenterPoints++;
				
			result << "\t" << each->getMovie()->getTitle() << "\t" << thisAmount << "\n";
			totalAmount += thisAmount;
		}
		
		result << "You owed " << totalAmount << "\n" << "You earned " << frequentRenterPoints << " frequent renter points\n";
		
		return result.str();
	}