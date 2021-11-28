#pragma once

#include <iostream>
#include "Date.hpp"

using namespace std;


class Flight{
    private:
        int number;
        Date departureDate;
        float duration; //hours
        string origin,destiny;

    public:

        Flight(){}
        Flight(int number,Date departureDate,float duration,string origin,string destiny);

        //Setters
        void setNumber(int number);
        void setDepartureDate(Date departureDate);
        void setDuration(float duration);
        void setOrigin(string origin);
        void setDestiny(string destiny);
        
        //Getters
        int getNumber() const;
        Date getDepartureDate() const;
        float getDuration() const;
        string getOrigin() const;
        string getDestiny() const;
};
