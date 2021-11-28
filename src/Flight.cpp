#include "Flight.hpp"


Flight::Flight(int number,Date departureDate,float duration,string origin,string destiny){
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

string Flight::getOrigin() const {return this->origin;}

string Flight::getDestiny() const {return this->destiny;}

//Setters
void Flight::setNumber(int number) {this->number = number;}

void Flight::setDepartureDate(Date departureDate) {this->departureDate = departureDate;}

void Flight::setDuration(float duration) {this->duration = duration;}

void Flight::setOrigin(string origin) {this->origin = origin;}

void Flight::setDestiny(string destiny) {this->destiny = destiny;}