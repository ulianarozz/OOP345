
/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_MOVIE_H_
#define _SDDS_MOVIE_H_
#include <iostream>
#include <iomanip>
#include <string>
#include"SpellChecker.h"
using namespace std;
namespace sdds {
	class Movie {
		string movie_title;
		size_t movie_year;
		string movie_desc;

	public:
		Movie();
		const string& title() const;
		Movie(const std::string& strMovie);
		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker.operator()(movie_title);
			spellChecker.operator()(movie_desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie&);
	};
}

#endif