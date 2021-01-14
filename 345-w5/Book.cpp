/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include"Book.h"
using namespace std;
namespace sdds {
	Book::Book() {
		book_author = "";
		 book_title = "";
		 book_country = "";
		 book_year = 0;
		 book_price = 0;
		 book_desc = "";
	}
	const string& Book::title() const {
		return book_title;
	}
	const string& Book::country() const {
		return book_country;
	}
	const size_t& Book::year() const {
		return book_year;
	}
	double& Book::price() {
		return book_price;
	} 
	Book::Book(const std::string& strBook) {  //using my ws4 trimming 
		string book_string = strBook;
		//AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		string author, title, country, price, year, description;
		// taking each string and remove every part i need till the end and store it into new temp strings 
		author = book_string.substr(0, book_string.find(','));
		author.erase(0, author.find_first_not_of(' '));
		author.erase(author.find_last_not_of(' ') + 1);
		book_string.erase(0, book_string.find(',') + 1);
		title = book_string.substr(0, book_string.find(','));
		title.erase(0, title.find_first_not_of(' '));
		title.erase(title.find_last_not_of(' ') + 1);
		book_string.erase(0, book_string.find(',') + 1);
		country = book_string.substr(0, book_string.find(','));
		country.erase(0, country.find_first_not_of(' '));
		country.erase(country.find_last_not_of(' ') + 1);
		book_string.erase(0, book_string.find(',') + 1);
		price = book_string.substr(0, book_string.find(','));
		price.erase(0, price.find_first_not_of(' '));
		price.erase(price.find_last_not_of(' ') + 1);
		book_string.erase(0, book_string.find(',') + 1);
		year = book_string.substr(0, book_string.find(','));
		year.erase(0, year.find_first_not_of(' '));
		year.erase(year.find_last_not_of(' ') + 1);
		book_string.erase(0, book_string.find(',') + 1);
		description = book_string.substr(0, book_string.find('.')+1);
		description.erase(0, description.find_first_not_of(' '));
		description.erase(description.find_last_not_of(' ') + 1);
		//setting all the cut temp strings into values
		book_author = author;
		book_title = title;
		book_country = country;
		book_price = stod(price);
		book_year = stoi(year);
		book_desc = description;
	}
	ostream& operator<<(ostream& os, const Book& book) {
		os << setw(20) << setfill(' ') << book.book_author << " | ";
		os << setw(22) << setfill(' ') << book.book_title << " | ";
		os << setw(5) << setfill(' ') << book.book_country << " | ";
		os << setw(4) << setfill(' ') << book.book_year << " | ";
		os << setw(6) << setfill(' ') << fixed << setprecision(2) << book.book_price << " | ";
		os << setw(22) << setfill(' ') << book.book_desc;
		os << endl;
		return os;
	}

}