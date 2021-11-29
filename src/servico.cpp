#include "../include/servico.h"

Service::Service(char type, Date date, string employer) {
    this->type=type;
    this->date=date;
    this->employer=employer;
}

//getters
char Service::getType() const {return this->type;}
Date Service::getDate() const{ return this->date;}
string Service::getEmployer() const {return this->employer;}
queue<Service> Service::getDoneServices() const {return this->doneServices;}

//setters
void Service::setType(char type) {this->type=type;}
void Service::setDate(Date date) {this->date=date;}
void Service::setEmployer(string employer) {this->employer=employer;}
void Service::setDoneServices(queue<Service> doneServices) {this->doneServices=doneServices;}





