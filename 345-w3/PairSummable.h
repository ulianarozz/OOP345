/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/10
Workshop: 3*/
/****************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__

#include "Pair.h"
#include <iostream>
#include <iomanip>
#include <string>
//#include<typeinfo>

using namespace std;

namespace sdds {
    template<typename K, typename V>
    class PairSummable : public Pair<K, V> {
        static V initial_value;
        static size_t p_width; //firls width
    public:

        PairSummable() {   // set empty??
        }

        //custom const
        PairSummable(const K& key, const V& value=initial_value) : Pair<K, V>(key, value) {
            if (p_width < key.size()) {
                p_width = key.size();
            }
        }
        // overload display virtual
        void display(std::ostream& os) const {
            os.setf(ios::left);
            os.width(p_width);
            Pair<K, V>::display(os);
            os.unsetf(ios::left);
        }
        PairSummable<K, V> operator+=(const PairSummable<K, V>& source); //op gen def
    };


  //  template<typename K, typename V> V PairSummable<K, V>::initial_value = 0;

    //if string string 
    template<>
    string PairSummable<string, string>::initial_value = string("");
    //if string int
    template<> 
    int PairSummable<string, int>::initial_value = 0;



    template
    <typename K, typename V> size_t PairSummable<K, V>::p_width = 0;

  
    template<typename K, typename V>
    PairSummable<K, V> PairSummable<K, V>::operator+=(const PairSummable<K, V>& src) {}
    // += string string

   template<>
   PairSummable<string, string> PairSummable<string, string> ::operator+=(const PairSummable<string, string>& source) {
       if (this != &source) {
           if (this->key() == source.key()) {
               if (this->value().empty()) {
                   value_p = "" + source.value();
               }
               else {
                   value_p = this->value() + ", " + source.value();
               }
           }
       }
       return *this;
   }

   // += string int
   template<>
   PairSummable<string, int>PairSummable<string, int>::operator+=(const PairSummable<string, int>& source) {
       if (this != &source) {
           if (this->key() == source.key()) {
               value_p = this->value() + source.value();
           }
       }
       return *this;
   }
}
#endif