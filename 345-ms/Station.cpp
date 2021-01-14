// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
size_t Station::m_widthField = 0;
int Station::id_generator = 1;


Station::Station(const std::string& str) {
	m_id = id_generator;

	Utilities util;
	size_t next_pos = 0;
	bool more = true;

	try {
		m_name = util.extractToken(str, next_pos, more);
		m_serial_num = stoi(util.extractToken(str, next_pos, more));
		m_current_stock = stoi(util.extractToken(str, next_pos, more));
		m_widthField = std::max(util.getFieldWidth(), m_widthField);
		m_description = util.extractToken(str, next_pos, more);
	}
	catch (std::string& err) {
		std::cout << err;
	}
	id_generator++;
}
const std::string& Station::getItemName() const{
	return m_name;
}
unsigned int Station::getNextSerialNumber(){
	m_serial_num++;
	return m_serial_num - 1;
}
unsigned int Station::getQuantity() const {
	return m_current_stock;
}
void Station::updateQuantity() {
	m_current_stock--;
	if (m_current_stock < 0) {
		m_current_stock = 0;
	}
}
void Station::display(std::ostream& os, bool full) const {
	if (full == false) {
		os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]" << std::setfill(' ')
			<< " Item: " << std::setw(m_widthField) << std::left << m_name << std::setfill(' ')
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serial_num<< "]" << std::setfill(' ')<< std::endl;
	}
	else if (full == true) {
		os << "[" << std::setw(3) << std::setfill('0') << std::right << m_id << "]" << std::setfill(' ')
			<< " Item: " << std::setw(m_widthField) << std::left << m_name << std::setfill(' ')
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serial_num << "]" << std::setfill(' ')

			<< " Quantity: " << std::setw(m_widthField) << std::left << m_current_stock << std::setfill(' ')<< " Description: " << m_description<< std::endl;
	}
}