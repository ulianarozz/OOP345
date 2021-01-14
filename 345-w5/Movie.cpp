/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include"Movie.h"

namespace sdds {
	Movie::Movie() {
		movie_title = "";
		movie_year = 0;
		movie_desc = "";
	}
	const string& Movie::title() const {
		return movie_title;
	}
	Movie::Movie(const std::string& strMovie) {  //using ws4 trim again
		string movie_str = strMovie;
		string title, year, desc;
		title = movie_str.substr(0, movie_str.find(','));
		title.erase(0, title.find_first_not_of(' '));
		title.erase(title.find_last_not_of(' ') + 1);
		movie_str.erase(0, movie_str.find(',') + 1);
		year = movie_str.substr(0, movie_str.find(','));
		year.erase(0, year.find_first_not_of(' '));
		year.erase(year.find_last_not_of(' ') + 1);
		movie_str.erase(0, movie_str.find(',') + 1);
		desc = movie_str.substr(0, movie_str.find('.')+1);
		desc.erase(0, desc.find_first_not_of(' '));
		desc.erase(desc.find_last_not_of(' ') + 1);
		movie_title = title;
		movie_year = stoi(year);
		movie_desc = desc;
	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40);
		os << movie.title() << " | ";
		os << std::setw(4);
		os << movie.movie_year << " | ";

		os << movie.movie_desc << endl;
		return os;
	}
}