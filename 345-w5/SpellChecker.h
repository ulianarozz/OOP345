/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef _SDDS_SPELLCHECKER_H_
#define _SDDS_SPELLCHECKER_H_

#include <iostream>

namespace sdds {

	class SpellChecker {
	private:
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
		const size_t num = 5;
	};
}
#endif