/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 6*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"
using namespace std;
namespace sdds {
	Car::Car(std::istream& is)
	{
		std::string temp = "";
		getline(is, c_maker, ',');
		trim(c_maker);
		getline(is, temp, ',');
		trim(temp);
		if (temp == "n" || temp == "N" || temp == "")
		{
			c_condition = "new";
		}
		else if (temp == "u" || temp == "U")
		{
			c_condition = "used";
		}
		else if (temp == "b" || temp == "B")
		{
			c_condition = "broken";
		}
		else
		{
			throw "Invalid Record!";
		}
		size_t start = 0;
		size_t begin = temp.find(',', start);
		std::getline(is, temp, ',');
		start = begin;
		begin = temp.find(',', start + 1);
		try
		{
			c_topSpeed = std::stod(temp.substr(start + 1, begin - start - 1));
		}
		catch (...)
		{
			throw "Invalid Record!";
		}
	}
	string Car::condition() const {
		
		return c_condition;
	}
	double Car::topSpeed() const {
		return c_topSpeed;
	}
	void Car::display(std::ostream& out) const {
		out << "| ";
		out.width(10);
		out << std::right << c_maker << " | ";
		out.width(6);
		out << std::left<< c_condition  << " | ";
		out.width(6);
		out<< std::right;
		out << std::fixed << std::setprecision(2)<< topSpeed()<< " |";

	}
	void Car::trim(string& str)const
	{
		size_t i = 0;
		for (i = 0; i < str.length() && str[i] == ' '; i++);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; i--);
		str = str.substr(0, i);
	}
}