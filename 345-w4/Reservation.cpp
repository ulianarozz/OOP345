/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 4*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Reservation.h"
#include <string>
#include <iomanip>
using namespace std;
namespace sdds {
	Reservation::Reservation(){
		id = "";
		name = "";
		email = "";
		num_people =0;
		day=0;
		hour=0;
	};
	Reservation::Reservation(const std::string& res) {
		string res_string = res;
		string c_id, c_name, c_email, c_num_people, c_day, c_hour;
		// taking each string and remove every part i need till the end and store it into new temp strings as id , name etc
		c_id = res_string.substr(0, res_string.find(':'));
		c_id.erase(0, c_id.find_first_not_of(' '));
		c_id.erase(c_id.find_last_not_of(' ') + 1);
		res_string.erase(0, res_string.find(':')+1);
		c_name=res_string.substr(0, res_string.find(','));
		c_name.erase(0, c_name.find_first_not_of(' '));
		c_name.erase(c_name.find_last_not_of(' ') + 1);
		res_string.erase(0, res_string.find(',') + 1);
		c_email = res_string.substr(0, res_string.find(','));
		c_email.erase(0, c_email.find_first_not_of(' '));
		c_email.erase(c_email.find_last_not_of(' ') + 1);
		res_string.erase(0, res_string.find(',') + 1);
		c_num_people = res_string.substr(0, res_string.find(','));
		c_num_people.erase(0, c_num_people.find_first_not_of(' '));
		c_num_people.erase(c_num_people.find_last_not_of(' ') + 1);
		res_string.erase(0, res_string.find(',') + 1);
		c_day = res_string.substr(0, res_string.find(','));
		c_day.erase(0, c_day.find_first_not_of(' '));
		c_day.erase(c_day.find_last_not_of(' ') + 1);
		res_string.erase(0, res_string.find(',') + 1);
		c_hour = res_string.substr(0, res_string.find(','));
		c_hour.erase(0, c_hour.find_first_not_of(' '));
		c_hour.erase(c_hour.find_last_not_of(' ') + 1);
		//setting all the cut temp strings into values
		id = c_id;
		name = c_name;
		email = "<" + c_email + ">";
		//convert into int from str
		num_people = stoi(c_num_people);
		day = stoi(c_day);
		hour = stoi(c_hour);
	}
	ostream& operator<<(ostream& os,  Reservation& res) {
		string message = "";
		if (res.hour >=6 && res.hour <= 9) {
			message = "Breakfast on day ";
		}
		else if (res.hour >= 11 && res.hour <= 15) {
			message = "Lunch on day ";
		}
		else if (res.hour >= 17 && res.hour <= 21) {
			message = "Dinner on day ";
		}
		else {
			message = "Drinks on day ";
		}
		//the setw is not as instructed but this is the only way I made it work as expected output. 10 and 20 didnt work...
		os << "Reservation " << res.id<<":" << setw(11) << right << res.name<< "  "<< setw(24) << left << res.email  << message << res.day << " "<< "@ " << res.hour << ":00 " << "for " << res.num_people << " people." << endl;
		return os;
	}
}