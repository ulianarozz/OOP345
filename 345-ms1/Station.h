// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

class Station {
	int m_id;
	std::string m_name;
	std::string m_description;
	int m_serial_num;
	int m_current_stock;
	static size_t m_widthField;
	static int id_generator;
public:
	Station( const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;

};

#endif