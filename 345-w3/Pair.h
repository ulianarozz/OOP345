/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/10
Workshop: 3*/
/****************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PAIR_H__
#define SDDS_PAIR_H__

#include <iostream>
//#include<typeinfo>
namespace sdds {
	template<typename K, typename V>
	class Pair {
		protected: // couldnt access from pairSummable template outside the class
		K key_p;
		V value_p;
	public:
		Pair() : key_p(), value_p() {
		};

		Pair(const K& k, const V& v) {
			key_p = k;
			value_p = v;
		}

		const K& key() const {
			return key_p;
		}

		const V& value() const {
			return value_p;
		}

		virtual void display(std::ostream& os) const {
			os << key_p << " : " << value_p << std::endl;
		}
	};

	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif 