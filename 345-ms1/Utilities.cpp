// Name: Uliana Rozzhyvaikina
// Seneca Student ID: 132294190
// Seneca email: urozzhyvaikina@myseneca.ca
// Date of completion: 2020-11-27
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<string>
#include<iostream>
#include<algorithm>
#include "Utilities.h"
char Utilities::m_delimiter = ' ';
void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}
size_t Utilities::getFieldWidth() const {
	return m_widthField;
}
void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}
char Utilities::getDelimiter() {
	return m_delimiter;
}
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

std::string tmp = "";
	size_t first_pos = next_pos;
	next_pos = str.find(m_delimiter, first_pos);
	size_t wField;

	if (next_pos == std::string::npos) {
		tmp = str.substr(first_pos);
		wField = std::max(tmp.length(), m_widthField);
		setFieldWidth(wField);
		more = false;
	}
	else if (first_pos == next_pos)
	{
		more = false;
		throw "No token between delimiters is not allowed";
	}
	else {
		tmp = str.substr(first_pos, next_pos - first_pos);
		wField = std::max(tmp.length(), m_widthField);
		setFieldWidth(wField);
		more = true;
	}
	next_pos++;
	return tmp;

}