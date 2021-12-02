#include "../include/ServiceManagement.h"

void ServiceManagement::setDoneServices(list<Service> doneServices) { this->doneServices=doneServices;}
void ServiceManagement::setToDoServices(queue<Service> toDoServices) {this->toDoServices=toDoServices;}

list<Service> ServiceManagement::getDoneServices() const{return this->doneServices;}
queue<Service> ServiceManagement::getToDoServices() const {return this->toDoServices;}

//fazer metodos pra adicionar uma limpeza ja feita a list doneServices e remover um feito da list??


