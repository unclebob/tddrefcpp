#pragma once
#ifndef Rental_header
#define Rental_header

class Movie;

class Rental
{
public:
  Rental(Movie *movie, int daysRented);
  virtual ~Rental();

  int getDaysRented() const { return daysRented; }
  Movie* getMovie() const { return movie; }

private:
  Rental(const Rental&);
  Rental& operator=(const Rental&);

  Movie* movie;
  int daysRented;
};

#endif