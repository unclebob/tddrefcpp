#pragma once
#ifndef Customer_header
#define Customer_header

#include <string>
#include <vector>

using namespace std;

class Rental;

class Customer
{
public:
  Customer(const string& name);
  virtual ~Customer();

  void addRental(Rental* rental);
  const string& getName() const { return name; }

  string statement();

private:
  Customer(const Customer&);
  Customer& operator=(const Customer&);
  typedef vector<Rental*> RentalCollection;
  typedef RentalCollection::iterator Iter;

  string name;
  RentalCollection rentals;
};

#endif