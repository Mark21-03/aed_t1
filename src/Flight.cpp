
#include "../include/Flight.h"
#include "../Exceptions/NameToLongException.h"

#include <utility>

Flight::Flight(int number,const Date& departureDate,float duration,std::string origin,std::string destiny){

    this->number = number;
    this->departureDate = departureDate;
    this->duration = duration;


    if (origin.size() > STRING_MAX_VALUE || destiny.size() > STRING_MAX_VALUE) {
        throw NameToLongException();
    }

    setOrigin(origin).setDestiny(destiny);

}

//Getters
int Flight::getNumber() const{return this->number;}

Date& Flight::getDepartureDate() {return (this->departureDate);}

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
Flight& Flight::setNumber(int number) {this->number = number;return *this;}

Flight& Flight::setDepartureDate(Date departureDate) {this->departureDate = departureDate;return *this;}

Flight& Flight::setDuration(float duration) {this->duration = duration; return *this;}

Flight& Flight::setOrigin(std::string origin) {
    int i = 0;
    for (auto c: origin) {
        if (i > STRING_MAX_VALUE)
            throw NameToLongException();
        this->origin[i++] = c;
    }
    this->origin[i] = '\0';

    return *this;
}

Flight& Flight::setDestiny(std::string destiny) {
    int i = 0;
    for (auto c: destiny) {
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

