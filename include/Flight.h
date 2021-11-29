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
    std::string origin,destiny;

public:

    Flight() = default;
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
};

#endif //FLIGHT_H