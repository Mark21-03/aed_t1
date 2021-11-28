#include "../include/Plane.h"

#include <utility>

Plane::Plane(std::string numberPlate, int capacity){
    this->numberPlate = numberPlate;
    this->capacity = capacity;
}

Plane::Plane(std::string numberPlate, int capacity,std::vector<Flight> flightPlan){
    this->numberPlate = numberPlate;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
}
//Getters
std::string Plane::getNumberPlate() const{return this->numberPlate;}

int Plane::getCapacity() const {return this->capacity;}

std::vector<Flight> Plane::getFlightPlan() const {return this->flightPlan;}

//Setters
void Plane::setFlightPlan(const std::vector<Flight> &flightPlan) { this->flightPlan = flightPlan;}

void Plane::setCapacity(int capacity) {this->capacity = capacity;}

void Plane::setNumberPlate(std::string numberPlate) {this->numberPlate = numberPlate;}

