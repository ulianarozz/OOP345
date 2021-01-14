/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/10
Workshop: 3*/
/****************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
//#include<typeinfo>
#include <iostream>
#include "Set.h"

namespace sdds {
	template<typename T, unsigned int N>
	class SetSummable : public Set<T, N> {
	//	std::string filter; 
	public:
		T accumulate(const std::string& filter) const {
			T accum(filter);
			for (size_t i = 0; i <this->size(); i++){
				accum += this->operator[](i);
			}
			return accum;
		}
	};
}
#endif 