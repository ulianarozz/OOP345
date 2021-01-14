/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 4*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	class Reservation {
		string id;
		string name;
		string email;
		size_t num_people;
		unsigned int day;
		unsigned int hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend ostream& operator<<(ostream& os, Reservation& res);
	};
	


}


#endif // !SDDS_RESERVATION_H
