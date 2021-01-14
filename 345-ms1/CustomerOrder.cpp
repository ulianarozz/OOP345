// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"
#include <algorithm>

size_t CustomerOrder::m_widthField=0;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder( const std::string& src) {
	Utilities util;
	size_t next_pos = 0;
	bool more = false;
	m_lstItem=nullptr;
	std::vector<Item*> item;
		m_name = util.extractToken(src, next_pos, more);
		m_product = util.extractToken(src, next_pos, more);
		std::string temp;
		while (more) {
			temp = util.extractToken(src, next_pos, more);
			item.push_back(new Item(temp));
		}

		m_cntItem = item.size();
		
		m_lstItem = new Item* [m_cntItem];

		for (unsigned int i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = std::move(item[i]);
		}
	

		m_widthField = std::max(util.getFieldWidth(), m_widthField);
	
}
CustomerOrder::CustomerOrder(CustomerOrder&& c_order) noexcept {
	m_name = c_order.m_name;
	m_product = c_order.m_product;
	m_cntItem = c_order.m_cntItem;

	m_lstItem = c_order.m_lstItem;
	c_order.m_lstItem = nullptr;
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c_order) noexcept {
	if (&c_order == this)
		return *this;
	if (m_lstItem != nullptr) {
		for (unsigned int i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
	}
	delete[] m_lstItem;

	m_name = c_order.m_name;
	m_product = c_order.m_product;
	m_cntItem = c_order.m_cntItem;

	m_lstItem = c_order.m_lstItem;
	c_order.m_lstItem = nullptr;

	return *this;
}
CustomerOrder::~CustomerOrder() {
	if (m_lstItem == nullptr) {
		return;
	}
	for (unsigned int i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}
	delete[] m_lstItem;
	m_lstItem = nullptr;
}
bool CustomerOrder::isOrderFilled() const {
	size_t count = 0;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled) {
			count++;
		}
	}
	if (count < m_cntItem) {
		return false;
	}
	else {
		return true;
	}
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			return m_lstItem[i]->m_isFilled;
		}
	}
	return true;
}
void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
			}
			else {
				os << "    Unable to fill NAME, PRODUCT " << m_lstItem[i]->m_itemName << std::endl;
			}
		}
	}

}
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << std::setfill('0') << std::right << std::setw(6) << m_lstItem[i]->m_serialNumber << "]" << " ";

		os << std::setfill(' ') << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
	}
}
