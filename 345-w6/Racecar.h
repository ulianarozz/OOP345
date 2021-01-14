/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_RACECAR_H 
#define SDDS_RACECAR_H
#include <iostream>
#include"Car.h"
namespace sdds {
	class Racecar : public Car{
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};


}

#endif