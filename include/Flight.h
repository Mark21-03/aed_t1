#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <utility>

#include "Date.h"

class Flight{
private:
    int number;
    Date departureDate;
    float duration; //hours
    std::string origin,destiny; // MAYBE IT WOULD BE GOOD TO STORE THIS IN A ARRAY OF CHARS
    // maybe add a mile counter

public:

    Flight(){}
    Flight(int number,const Date& departureDate,float duration,std::string origin,std::string destiny);

    //Setters
    void setNumber(int number);
    void setDepartureDate(Date departureDate);
    void setDuration(float duration);
    void setOrigin(std::string origin);
    void setDestiny(std::string destiny);

    //Getters
    int getNumber() const;
    Date getDepartureDate() const;
    float getDuration() const;
    std::string getOrigin() const;
    std::string getDestiny() const;


    // TODO: DO A CHECK IN FUNCTION WHICH WILL TAKE A PASSENGER
};

#endif //FLIGHT_H