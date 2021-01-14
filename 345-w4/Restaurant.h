/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 4*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include"Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* reservation;
		size_t num_res;
	
	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& rest);
		Restaurant(Restaurant&& rest);
		size_t size() const;
		~Restaurant();
		friend ostream& operator<<(ostream& os, const Restaurant& rest);
	};
}



#endif