/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Autoshop.h"
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		a_vehicles.push_back(theVehicle);
		return *this;
	}
	Autoshop::~Autoshop() {
		while (!a_vehicles.empty()) {
			delete a_vehicles.back();
			a_vehicles.pop_back();
		}
	}
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto i = a_vehicles.begin(); i != a_vehicles.end(); i++) {
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}
}
