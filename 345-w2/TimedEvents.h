#define _CRT_SECURE_NO_WARNINGS
/****************************/
/*Name: Uliana Rozzhyvaikina
Student number: 132294190
Section:NFF
Date: 2020/10/01
Workshop: 2*/
/****************************/
#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__
#include<iostream>
#include<iomanip>
#include<chrono>
namespace sdds {
    const int MAX_RECORD = 7;
    class TimedEvents {
        int num_rec;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        struct {
            std::string event_name{};
            std::string time_units{};
            std::chrono::steady_clock::duration duration{};
        }strct[MAX_RECORD];

    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void recordEvent(const char*);
        friend std::ostream& operator<<(std::ostream& , const TimedEvents&);

    };
}
#endif