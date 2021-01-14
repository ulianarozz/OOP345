#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "event.h"
#include <cstring>


using namespace std;


unsigned int g_sysClock = 0;


namespace sdds
{
	//constructor --- default we also need custom otherwisde destructor is not gonna work
	Event::Event() {
		secMidnight = 0;
		description = nullptr;
	}
	Event::Event(const Event& src) {
		description = nullptr;
		*this = src;
	}

	Event::~Event() {
		delete[] description;
		description = nullptr;
	}

	//calculates time in seconds to HH:MM::SS format and displays.
	void Event::display() {
		static int counter = 1;
		int hour = 0;
		int min = 0;
		int sec = 0;
		hour = secMidnight / 3600;
		min = (secMidnight - (hour * 3600)) / 60;
		sec = (secMidnight - (hour * 3600) - (min * 60));
		if (description != nullptr) {
			cout << setw(3) << setfill(' ') << counter << ". " <<setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec << " -> " << description<< endl;
		}
		else {
			cout << setw(3) << setfill(' ') << counter << ". [ No Event ]" << endl;
		}
		counter++;
	}




	// basically copy constructor  ----  its not Andrew :)  its just set function - i created copy assignnment below
	void Event::setDescription(const char* src) {
		if (src != nullptr ) {
			delete[] description;
			description = nullptr;
			description = new char[strlen(src) + 1];
			strcpy(description, src);
			secMidnight = g_sysClock;
		}
		else {
			delete[] description;
			description = nullptr;
			secMidnight = 0;
		}
	}
	Event& Event::operator=(const Event& src) {
		if (this != &src) {
			if (src.description != nullptr) {
				secMidnight = src.secMidnight;
				delete[] description;
				description = nullptr;
				description = new char[strlen(src.description) + 1];
				strcpy(description, src.description);
			}
			else {
				delete[] description;
				description = nullptr;
				secMidnight = 0;
			}
		}
		return *this;
	}


	


}

