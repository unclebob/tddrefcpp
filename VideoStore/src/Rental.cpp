#include "Rental.h"
#include "Movie.h"

Rental::Rental(Movie* movie, int daysRented) : movie(movie), daysRented(daysRented)
{
}

Rental::~Rental()
{
  delete movie;
}
