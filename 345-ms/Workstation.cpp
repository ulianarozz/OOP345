
// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Workstation.h"

Workstation::Workstation(const std::string& str) : Station(str) {
	m_pNextStation = nullptr;
}
void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.front().isOrderFilled()) {
			m_orders.front().fillItem(*this, os);
		}
	}
}
bool Workstation::moveOrder() {
	if (m_orders.empty()) {
		return false;
	}

	if (m_orders.front().isItemFilled(getItemName()) == true) {
		*m_pNextStation += std::move(m_orders.front());

		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}
void Workstation::setNextStation(Workstation& station) {
	m_pNextStation = &station;
}
const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}
bool Workstation::getIfCompleted(CustomerOrder& ord) {
	if (m_orders.empty()) {
		return false;
	}
	if (m_orders.front().isOrderFilled()) {
		ord = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}
void Workstation::display(std::ostream& os) const {
	if (m_pNextStation == nullptr)
		os << getItemName() << " --> END OF LINE" << std::endl;
	else
		os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& customer) {
	m_orders.push_back(std::move(customer));
	return *this;
}