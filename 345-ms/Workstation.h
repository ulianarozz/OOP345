// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include "Station.h"
#include "CustomerOrder.h"
#include <deque>
#include <iostream>

class Workstation : public Station {

private:

	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

public:

	Workstation(const std::string&);
	//delete move delete copy option
	Workstation(const  Workstation&) = delete;
	Workstation& operator =(const Workstation&) = delete;
	Workstation(const  Workstation&&) = delete;
	Workstation& operator =(const  Workstation&&) = delete;

	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&) const;
	Workstation& operator+=(CustomerOrder&&);

};

#endif 