
#include "../include/Flight.h"
#include "../Exceptions/NameToLongException.h"

Flight::Flight(flightNumber number,const Date& departureDate,const Time& departureTime,float duration,std::string origin,std::string destiny){

    this->number = number;
    this->departureDate = departureDate;
    this->departureTime = departureTime;
    this->duration = duration;


    if (origin.size() > STRING_MAX_VALUE || destiny.size() > STRING_MAX_VALUE) {
        throw NameToLongException();
    }

    setOrigin(origin).setDestiny(destiny);

}

//Getters
flightNumber Flight::getNumber() const{return this->number;}


Date Flight::getDepartureDate() const {return this->departureDate;}

float Flight::getDuration() const {return this->duration;}

std::string Flight::getOrigin() const {
    int i=0;
    string s;
    char c;
    while ((c = origin[i++] )!= '\0') {
        s+=c;
    }
    return s;
}

std::string Flight::getDestiny() const {
    int i=0;
    string s;
    char c;
    while ((c = destiny[i++] )!= '\0') {
        s+=c;
    }
    return s;
}

//Setters
Flight& Flight::setNumber(flightNumber number) {this->number = number;return *this;}

Flight& Flight::setDepartureDate(const Date& departureDate) {this->departureDate = departureDate;return *this;}

Flight& Flight::setDuration(float duration) {this->duration = duration; return *this;}

Flight& Flight::setOrigin(const std::string& origin) {
    int i = 0;
    for (const auto& c: origin) {
        if (i > STRING_MAX_VALUE)
            throw NameToLongException();
        this->origin[i++] = c;
    }
    this->origin[i] = '\0';

    return *this;
}

Flight& Flight::setDestiny(const std::string& destiny) {
    int i = 0;
    for (const auto& c: destiny) {
        if (i > STRING_MAX_VALUE)
            throw NameToLongException();
        this->destiny[i++] = c;
    }
    this->destiny[i] = '\0';

    return *this;
}

char* Flight::getOriginC()  {
    return origin;
}

char *Flight::getDestinyC()  {
    return destiny;
}

Flight &Flight::setDepartureTime(const Time &departureTime) {
    this->departureTime = departureTime;
    return *this;
}

Time Flight::getDepartureTime() const{
    return this->departureTime;
}


