/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <string>
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) :Car(in) {
		char boost;
		in >> boost >> m_booster;
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}
