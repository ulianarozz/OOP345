// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 8*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t k = 0; k < price.size(); k++) {
				if (desc[i].code == price[k].code) {
					Product* product = new Product(desc[i].desc, price[k].price);
					product->validate();
					priceList += product;
					delete product;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t k = 0; k < price.size(); k++) {
				if (desc[i].code == price[k].code) {
					std::unique_ptr<Product> product (new Product(desc[i].desc, price[k].price));
					product->validate();
					priceList += std::move(product);
				}
			}
		}

		return priceList;
	}
}

