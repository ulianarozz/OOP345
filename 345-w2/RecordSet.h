/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/01
Workshop: 2*/
/****************************/

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

namespace sdds {
    class RecordSet {
        unsigned int num_strings;
        std::string* rec_string;
        void emptyState();
    public:
        RecordSet();
        RecordSet(const char*);
        RecordSet(const RecordSet&);
        RecordSet(RecordSet&&);
        RecordSet& operator=(const RecordSet&);
        RecordSet& operator=(RecordSet&&);
        ~RecordSet();
        size_t size();
        std::string getRecord(size_t);
    };
}



#endif