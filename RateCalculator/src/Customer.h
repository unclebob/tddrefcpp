#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>

struct Site;

struct Customer {
	enum customertype {
		consumer, business, industrial
	};
	enum ratetype {
		lifeline, interruptable, oneHourNotice, territorial, UNDEFINED
	};

	typedef std::vector < Site * > c_site;

	int address;
	int kwh;
	customertype type;
	ratetype rate, industrialRate;
	c_site sites;
	~Customer();
};

#endif
