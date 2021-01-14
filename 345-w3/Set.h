/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/10
Workshop: 3*/
/****************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SET_H__
#define SDDS_SET_H__
#include <cstring>
#include <iostream>
//#include<typeinfo>
namespace sdds {
	template<typename T, unsigned int N>
	class Set {
		T arr[N];
		size_t num_el;
	public:
		Set() {
			num_el = 0;
		}
		size_t size() const {
			return num_el;
		}
		//return strind asked 
		const T& operator[](size_t idx) const {
			return arr[idx];
		}
		//add item to arr
		void operator+=(const T& item) {
			if (num_el < N) {
				arr[num_el] = item;
				num_el++;
			}
		}
	};
}

#endif