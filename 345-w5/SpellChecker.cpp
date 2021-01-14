/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS_
#include "SpellChecker.h"
#include <iostream>
#include <fstream>

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file.is_open()) { //if file is missing
			throw "Bad file name!";
		}
		for (size_t i = 0; i < num;i ++) {
			file >> m_badWords[i]; 
			file >> m_goodWords[i]; 
		}
	}

	// FUNCTOR
	void SpellChecker::operator()(std::string& text) const {
		size_t word = 0;

		for (size_t i = 0; i < num; i++) {
			word = text.find(m_badWords[i]); // if bad words exist
			if (word != std::string::npos) { // in the whole text at least once
				do {
					text.replace(word, m_badWords[i].size(), m_goodWords[i]); //replace 
					word = text.find(m_badWords[i]); //check more
				} while (word != std::string::npos);// till the end
			}
		}
	}
}