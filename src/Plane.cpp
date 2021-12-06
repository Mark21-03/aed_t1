#include "../include/Plane.h"

#include <utility>

Plane::Plane(std::string numberPlate, int capacity){
    this->numberPlate = std::move(numberPlate);
    this->capacity = capacity;
}


Plane::Plane(std::string numberPlate, int capacity,std::list<flightNumber> flightPlan){

    this->numberPlate = std::move(numberPlate);
    this->capacity = capacity;
    this->flightPlan = std::move(flightPlan);
}
//Getters
std::string Plane::getNumberPlate() const{return this->numberPlate;}

int Plane::getCapacity() const {return this->capacity;}

std::list<flightNumber> Plane::getFlightPlan() const {return this->flightPlan;}

//Setters
void Plane::setFlightPlan(const std::list<flightNumber> &flightPlan) { this->flightPlan = flightPlan;}

void Plane::setCapacity(int capacity) {this->capacity = capacity;}

void Plane::setNumberPlate(std::string numberPlate) {this->numberPlate = std::move(numberPlate);}
