/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<string>
#include<iostream>
#include <sstream>
#include"Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		char ch = '\0';
		char ch2 = '\0';

		std::string line = "";
		getline(in, line);
		std::stringstream record(line);
		record >> ch >> ch2;
		if (record) {
			if (ch == 'c' || ch == 'C') {
				return new Car(record);
			}
			else if (ch == 'r' || ch == 'R') {
				return new Racecar(record);
			}
			else
				throw ch;
		}
		else
			return nullptr;
	}
}