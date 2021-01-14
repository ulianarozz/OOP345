
/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 5*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include<iostream>
using namespace std;
namespace sdds {
	template<typename T>
	class Collection {
		string c_name;
		T* items;
		size_t c_size;
		void (*c_observer)(const Collection<T>&, const T&);
	public:
		Collection(std::string name) {
			c_name = name;
			items = nullptr;
			c_size = 0;
			c_observer = nullptr;
		}
		//delete copyoption
		Collection(const Collection& source) = delete;
		Collection& operator=(const Collection& source) = delete;

		~Collection() {
			delete[] items;
			items = nullptr;
		}
		const std::string& name() const {
			return c_name;
		}
		size_t size() const {
			return c_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		} //if observer exists set it to out c_observer

		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < c_size; i++) {
				if (items[i].title() == item.title()) {  // if exists dont do changes
					return *this;
				}
			}
			// creating new temp object to add all we need into then assign the copy into our object
			T* copy = new T[c_size + 1];
			for (size_t i = 0; i < c_size; i++) {
				copy[i] = items[i];
			}
			copy[c_size] = item; 
			delete[] items;  //MEMEORY LEAKS
			items = copy; 
			c_size++; 

		
			if (c_observer != nullptr)
				c_observer(*this, items[c_size - 1]);

			return *this;
		}
		T& operator[](size_t idx) const {
			string err = "Bad index [" + to_string(idx) + "]. Collection has [" + to_string(c_size) + "] items.";
			if (idx >= c_size) {
				throw out_of_range(err); //to use it in main out_of_range error later 
			}
			else {
				return items[idx]; // if ok return the item with the index mentioned 
			}
		}
		T* operator[](std::string title) const {
			for (size_t i = 0; i < c_size; i++) {
				if (items[i].title() == title) {  //if exists the title in the collection retun its address if not nullptr
					return &(items[i]); 
				}
			}
			return nullptr;
		};
		friend ostream& operator<<(ostream& os, Collection& collection) {
			for (size_t i = 0; i < collection.size(); i++) {
				os << collection[i];
			}
			return os;
		}
	};


}
#endif