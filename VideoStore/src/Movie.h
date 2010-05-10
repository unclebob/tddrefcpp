#pragma once
#ifndef Movie_header
#define Movie_header

#include <string>
using namespace std;

class Movie
{
public:
  enum PriceCode { Childrens, Regular, NewRelease };

  Movie(const string & title, PriceCode priceCode);
  virtual ~Movie();

  int getPriceCode() const { return priceCode; }
  void setPriceCode(PriceCode code) { priceCode = code; }
  const string& getTitle() const { return title; }

private:
  Movie(const Movie&);
  Movie& operator=(const Movie&);

private:
  string title;
  PriceCode priceCode;
};

#endif