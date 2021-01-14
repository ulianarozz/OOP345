
/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
/*Uliana Rozzhtvaikina
part 1 ws5*/
#include <iostream>
#include <iomanip>
#include <string>
#include"SpellChecker.h"

using namespace std;

namespace sdds {
	class Book {
		string book_author;
		string book_title;
		string book_country;
		size_t book_year;
		double book_price;
		string book_desc;

	public:
		Book();
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend ostream& operator<<(ostream&, const Book&);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker.operator()(book_desc);
		}
	};
}

#endif 