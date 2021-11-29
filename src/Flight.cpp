
#include "../include/Flight.h"

#include <utility>

Flight::Flight(int number,const Date& departureDate,float duration,std::string origin,std::string destiny){

    this->number = number;
    this->departureDate = departureDate;
    this->duration = duration;
    this->origin = std::move(origin);
    this->destiny = std::move(destiny);
}

//Getters
int Flight::getNumber() const{return this->number;}

Date& Flight::getDepartureDate() {return (this->departureDate);}

float Flight::getDuration() const {return this->duration;}

std::string Flight::getOrigin() const {return this->origin;}

std::string Flight::getDestiny() const {return this->destiny;}

//Setters
void Flight::setNumber(int number) {this->number = number;}

void Flight::setDepartureDate(Date departureDate) {this->departureDate = departureDate;}

void Flight::setDuration(float duration) {this->duration = duration;}

void Flight::setOrigin(std::string origin) {this->origin = std::move(origin);}

void Flight::setDestiny(std::string destiny) {this->destiny = std::move(destiny);}

