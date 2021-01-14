/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_UTILITIES_H 
#define SDDS_UTILITIES_H
#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include"Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif 