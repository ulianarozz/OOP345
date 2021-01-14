/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 4*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"Restaurant.h"
using namespace std;
namespace sdds {
	Restaurant::Restaurant() {
		reservation = nullptr;
		num_res = 0;
	}
	Restaurant::~Restaurant() {
		delete[] reservation;
		reservation = nullptr;
	}
	//custom constructor 
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		num_res = 0;
		reservation = nullptr;
		delete[] reservation;
		reservation = new Reservation[cnt]; // creating new reservation
		for(size_t i =0; i<cnt; i++){
			reservation[i] = *reservations[i]; 
		}
		num_res = cnt;
	}

	Restaurant::Restaurant(const Restaurant& rest) {  // copy constructor 
		if (this != &rest) {
			if (rest.reservation != nullptr) {
				reservation = nullptr;
				//delete[] reservation;
				reservation = new Reservation[rest.size() + 1];
				for (size_t i = 0; i < rest.size(); i++) {
					reservation[i] = rest.reservation[i];
				}
				num_res = rest.num_res;
			}

		}
	}

	size_t Restaurant::size() const {
		return num_res;
	}
	ostream& operator<<(ostream& os, const Restaurant& rest) {
		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << endl;
		os << "--------------------------" << endl;
		if (rest.size() == 0) {
			os << "The object is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < rest.size(); i++) {
				os<<rest.reservation[i];
			}
		}
		os << "--------------------------" << endl;
		return os;
	}


	

	//move 
	Restaurant::Restaurant(Restaurant&& rest) {
		if (rest.reservation != nullptr) { // check if passed not null
			swap(reservation, rest.reservation); // swap between
			num_res = rest.num_res;
			rest.num_res = 0;// make passed empty to MOVE and not to copy 
			rest.reservation = nullptr;
		}
	}
}