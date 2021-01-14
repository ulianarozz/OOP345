/*Uliana Rozzhyvaikina
132294190
urozzhyvaikina@myseneca.ca
Workshop 4*/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        Reservation** con_reservation;
        size_t con_num;

    public:

        ConfirmationSender();
        ~ConfirmationSender();
        size_t size() const ;
        ConfirmationSender(ConfirmationSender&);
        ConfirmationSender(ConfirmationSender&&);
        ConfirmationSender& operator+=( Reservation& res);
        ConfirmationSender& operator-=(Reservation& res);
        friend ostream& operator<<(ostream& os, ConfirmationSender& conSen);
    };
}

#endif 