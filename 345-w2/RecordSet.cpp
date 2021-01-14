/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/01
Workshop: 2*/
/****************************/
#include"RecordSet.h"
#include"TimedEvents.h"

namespace sdds{
	void RecordSet::emptyState() {
		rec_string = nullptr;
		delete[] rec_string;
		rec_string = nullptr;
		num_strings = 0;
	}


	RecordSet::RecordSet() {
		emptyState();
	}


    RecordSet::RecordSet(const char* name) {
        num_strings = 0;
        std::string rec;
        std::ifstream file(name);
        while (!file.eof()) {
            getline(file, rec, ' ');
            rec.clear();
            num_strings++;
        }
            file.clear();
            file.seekg(0,file.beg);
        rec_string = new std::string[num_strings];

        for (unsigned int i = 0; i < num_strings; i++) {
            getline(file, rec_string[i], ' ');
        }
        file.clear();
        file.close();
    }



    RecordSet::RecordSet(const RecordSet& source) {
        *this = source;
    }



    RecordSet& RecordSet::operator=(const RecordSet& source) {
        if (this != &source) {
            if (source.num_strings > 0) {
                rec_string = new std::string[source.num_strings];
                num_strings = source.num_strings;
                for (unsigned int i = 0; i < source.num_strings; i++) {
                    rec_string[i] = source.rec_string[i];
                }
            }
        }
        return *this;
    }




    size_t RecordSet::size() {
        return num_strings;
    }




    std::string RecordSet::getRecord(size_t num) {
        if (num <= num_strings && rec_string !=nullptr) {
            return rec_string[num];
        }
        else {
            return "";
        }
    }



    RecordSet::~RecordSet() {
        delete[] rec_string;
        rec_string = nullptr;
    }



    RecordSet::RecordSet(RecordSet&& source) {
        *this = std::move(source);
    }




    RecordSet& RecordSet::operator=(RecordSet&& source) {
        if (this != &source) {
            num_strings = source.num_strings;
            rec_string = source.rec_string;
            source.num_strings = 0u;
            source.rec_string = nullptr;
          
        }
        return *this;
    }
}