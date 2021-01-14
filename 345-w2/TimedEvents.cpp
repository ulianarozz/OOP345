/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/01
Workshop: 2*/
/****************************/
#include "TimedEvents.h"

namespace sdds {

	TimedEvents::TimedEvents() {
		num_rec = 0;
		start_time = {};
		end_time = {};
	}



	void TimedEvents::startClock() {
		start_time = std::chrono::steady_clock::now();
	}



	void TimedEvents::stopClock() {
		end_time = std::chrono::steady_clock::now();
	}




	void TimedEvents::recordEvent(const char* name) {
		if (num_rec < MAX_RECORD) {
			std::chrono::nanoseconds duration_ = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
			strct[num_rec].event_name = name;
			strct[num_rec].duration = duration_;
			strct[num_rec].time_units = "nanoseconds";
		}
		num_rec++;
	}



	std::ostream& operator<<(std::ostream& os, const TimedEvents& event) {
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (unsigned int i = 0; i < event.num_rec; i++) {
			os << std::setw(20) << std::left << event.strct[i].event_name << " " << std::setw(12) << std::right
				<< event.strct[i].duration.count() << " " << event.strct[i].time_units << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}

	
}