/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef sdds_Autoshop_h
#define sdds_Autoshop_h

#include <vector>
#include <iostream>
#include "Vehicle.h"
#include <list>

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> a_vehicles;

	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		~Autoshop();
		void display(std::ostream& out) const;
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto ptr = a_vehicles.begin(); ptr < a_vehicles.end(); ptr++) {
				if (test(*ptr)) {
					vehicles.push_back(*ptr);
				}
			}

		}
	};
}
#endif