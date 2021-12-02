#include "../include/Service.h"

Service::Service(char type, Date date, string employer) {
    if (type == 'm')
        this->type = maintenance;
    else if (type == 'c')
        this->type = cleaning;
    else
        this->type = other;
    this->date=date;
    this->employer=employer;
}

//getters
ServiceType Service::getType() const {return this->type;}
Date Service::getDate() const{ return this->date;}
string Service::getEmployer() const {return this->employer;}

//setters
void Service::setType(char type) {
    if (type == 'm')
        this->type = maintenance;
    else if (type == 'c')
        this->type = cleaning;
    else
        this->type = other;
}
void Service::setDate(Date date) {this->date=date;}
void Service::setEmployer(string employer) {this->employer=employer;}





