#include "../include/Flight.h"

Flight::Flight(int number,const Date& departureDate,float duration,std::string origin,std::string destiny){
    this->number = number;
    this->departureDate = departureDate;
    this->duration = duration;
    this->origin = origin;
    this->destiny = destiny;
}

//Getters
int Flight::getNumber() const{return this->number;}

Date Flight::getDepartureDate() const {return this->departureDate;}

float Flight::getDuration() const {return this->duration;}

std::string Flight::getOrigin() const {return this->origin;}

std::string Flight::getDestiny() const {return this->destiny;}

//Setters
void Flight::setNumber(int number) {this->number = number;}

void Flight::setDepartureDate(Date departureDate) {this->departureDate = departureDate;}

void Flight::setDuration(float duration) {this->duration = duration;}

void Flight::setOrigin(std::string origin) {this->origin = origin;}

void Flight::setDestiny(std::string destiny) {this->destiny = destiny;}