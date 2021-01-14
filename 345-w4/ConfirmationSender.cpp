/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 4*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		con_reservation = nullptr;
		con_num = 0;
	} // constructor 
	ConfirmationSender::~ConfirmationSender() {
		delete[] con_reservation;
		con_reservation = nullptr;
	} //destructor
	size_t ConfirmationSender::size() const {
		return con_num;  
	} // function to keep track of number of reservartion by calling method .size()
	ConfirmationSender::ConfirmationSender( ConfirmationSender& conSen) {
		if (this != &conSen) { // if the obect is no equial to the passed one
			if (conSen.con_reservation != nullptr) { //and the passed param is not empty
				con_reservation = nullptr;
				delete[] con_reservation;
				con_reservation = new  Reservation * [conSen.size()];  // creating new dynamic object of Reservation
				for (size_t i = 0; i < conSen.size(); i++) {
					con_reservation[i] = conSen.con_reservation[i];    // aadding passed reservations to the object 
				}
				con_num = conSen.con_num;  
			}
		}
		else {
			con_reservation = nullptr;
		}  // if not set to empty 
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& conSen) {    //move constructor 
		if (conSen.con_reservation != nullptr) {  // if passed res. is not null
			swap(con_reservation, conSen.con_reservation); // swapping between passed and the obj
			con_num = conSen.con_num; 
			conSen.con_num = 0;  // passed one is empty
			conSen.con_reservation = nullptr; // passed is empty since we moved it without saving copy 
		}
	}
	ConfirmationSender& ConfirmationSender::operator+=(Reservation& res) { // adding new elements
        bool equal = false;  
        for (size_t i = 0; i < con_num; i++) {
            if (con_reservation[i] == &res) {
                equal = true;
            }  //going check if specific reservartion exists 
        }
        if (equal == false) {   //if wasnt found 
            Reservation** temp = nullptr;  // creating temporary object
			delete[] temp;
            temp = new  Reservation * [con_num + 1]; 
            for (size_t i = 0; i < con_num; ++i)
            temp[i] = con_reservation[i];  // setting it to the temp object 
             temp[con_num] = &res; 
			++con_num;
            delete[] con_reservation;
            con_reservation = temp; // setting temp obejct to the reservation 
        }

        return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(Reservation& res) {  // removing the reservation 
        for (size_t i = 0; i < con_num; i++) {
            if (con_reservation[i] == &res) { // if found the record
                con_reservation[i] = nullptr; // set it to null (delete the record)
            }
        }
        return *this;
	}
	ostream& operator<<(ostream& os, ConfirmationSender& conSen) {  // inserting operator
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (conSen.con_num == 0) {
			os << "The object is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < conSen.size(); i++) {
				if (conSen.con_reservation[i] != nullptr) {
					os << *conSen.con_reservation[i];
				}
			}
		}
		os << "--------------------------" << endl;
		return os;
	}
}


