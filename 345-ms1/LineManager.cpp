// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"


LineManager::LineManager(const std::string& str, std::vector<Workstation*>& workstat, std::vector<CustomerOrder>& customer) {
	std::fstream file(str);
	do {
		Utilities util;
		size_t next_pos = 0;
		bool more = true;
		util.setDelimiter('|');
		std::string str_ = "";
		getline(file, str_);
		std::string station = "";
		station = util.extractToken(str_, next_pos, more);
		std::string next = "";
		if (more) {
			next = util.extractToken(str_, next_pos, more);
		}
		for (unsigned int i = 0; i < workstat.size(); i++) {
			if (station == workstat[i]->getItemName()) {
				for (unsigned int j = 0; j < workstat.size(); j++) {
					if (workstat[j]->getItemName() == next) {
						workstat[i]->setNextStation(*workstat[j]);
					}
				}
			}
		}

	} while (!file.eof());
	for (unsigned int i = 0; i < customer.size(); i++) {
		ToBeFilled.push_back(std::move(customer[i]));
	}

	for (std::size_t i = 0; i < workstat.size(); i++) {
		AssemblyLine.push_back(workstat[i]);
	}


	m_cntCustomerOrder = customer.size();
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (std::size_t i = 0; i < Completed.size(); ++i) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->display(std::cout);
	}
}bool LineManager::run(std::ostream& os) {
	static unsigned int count = 1;
	os << "Line Manager Iteration: " << count << std::endl;
	count++;
	std::deque<Workstation*>station = sort(AssemblyLine);
	if (!ToBeFilled.empty()) {
		*station.front() += std::move(ToBeFilled.front()); 
		ToBeFilled.pop_front();
	}
	for (unsigned int i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{
			CustomerOrder tmp;
			if (AssemblyLine[i]->getIfCompleted(tmp)) {
				Completed.push_back(std::move(tmp));
			}
		}
		else {
			AssemblyLine[i]->moveOrder();
		}
	}
	CustomerOrder customer;
	for (unsigned int i = 0; i < AssemblyLine.size(); i++) {
		if (AssemblyLine[i]->getIfCompleted(customer)) {
			Completed.push_back(std::move(customer));
		}
	}
	return (Completed.size() == m_cntCustomerOrder);

}
std::deque<Workstation*> LineManager::sort(const std::vector<Workstation*>& _station) const {
	Workstation* w_station = nullptr;
	std::deque<Workstation*>station;

	do {
		for (auto i : _station) {
			if (i->getNextStation() == w_station) {
				station.push_front(i);
				w_station = i;
			}
		}

	} while (station.size() != _station.size());
	
	return station;
}

void LineManager::displayStationsSorted() const {
	std::deque<Workstation*>station = sort(AssemblyLine);
	for (unsigned int i = 0; i < AssemblyLine.size(); i++) {
		station[i]->display(std::cout);
	}
}