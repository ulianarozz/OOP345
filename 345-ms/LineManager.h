// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <iostream>
#include <vector>
#include "Workstation.h"

class LineManager
{
	std::vector<Workstation*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

public:
	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations()const ;
	void displayStationsSorted() const;
	std::deque<Workstation*> sort(const std::vector<Workstation*>& ) const;


};
#endif