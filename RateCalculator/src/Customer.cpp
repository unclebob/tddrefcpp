#include "Customer.h"

#include "Site.h"

Customer::~Customer() {
	for(c_site::iterator iter = sites.begin(); iter != sites.end(); ++iter) {
		delete  *iter;
	}
}
