#include "Customer.h"
#include "Movie.h"
#include "Rental.h"

#include "CppUTest/Extensions/SimpleStringExtensions.h"
#include <CppUTest/TestHarness.h>

TEST_GROUP(VideoStoreTest) {
  Customer* customer;

  virtual void setup() {
    customer = new Customer("Fred");
  }

  virtual void teardown() {
    delete customer;
  }
};


TEST(VideoStoreTest, singleNewReleaseStatement) {
  customer->addRental (new Rental (new Movie ("The Cell", Movie::NewRelease), 3));		
  STRCMP_EQUAL("Rental Record for Fred\n\tThe Cell\t9\nYou owed 9\nYou earned 2 frequent renter points\n", customer->statement().c_str());
}

TEST(VideoStoreTest, dualNewReleaseStatement) {
	customer->addRental (new Rental (new Movie ("The Cell", Movie::NewRelease), 3));
  customer->addRental (new Rental (new Movie ("The Tigger Movie", Movie::NewRelease), 3));		
	STRCMP_EQUAL("Rental Record for Fred\n\tThe Cell\t9\n\tThe Tigger Movie\t9\nYou owed 18\nYou earned 4 frequent renter points\n", customer->statement().c_str());
}

TEST(VideoStoreTest, singleChildrensStatement) {
  customer->addRental (new Rental (new Movie ("The Tigger Movie", Movie::Childrens), 3));
	STRCMP_EQUAL("Rental Record for Fred\n\tThe Tigger Movie\t1.5\nYou owed 1.5\nYou earned 1 frequent renter points\n", customer->statement().c_str());
}

TEST(VideoStoreTest, multipleRegularStatement) {
  customer->addRental (new Rental (new Movie ("Plan 9 from Outer Space", Movie::Regular), 1));
  customer->addRental (new Rental (new Movie ("8 1/2", Movie::Regular), 2));
  customer->addRental (new Rental (new Movie ("Eraserhead", Movie::Regular), 3));
	
	STRCMP_EQUAL("Rental Record for Fred\n\tPlan 9 from Outer Space\t2\n\t8 1/2\t2\n\tEraserhead\t3.5\nYou owed 7.5\nYou earned 3 frequent renter points\n", customer->statement().c_str());
}