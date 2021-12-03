#include "../include/ServiceManagement.h"

void ServiceManagement::setDoneServices(list<Service> doneServices) { this->doneServices=doneServices;}
void ServiceManagement::setToDoServices(queue<Service> toDoServices) {this->toDoServices=toDoServices;}

list<Service> ServiceManagement::getDoneServices() const{return this->doneServices;}
queue<Service> ServiceManagement::getToDoServices() const {return this->toDoServices;}


void ServiceManagement::printAllDoneServices() const{

    for(Service s:doneServices){
        cout<<s<<endl;
    }

}

void ServiceManagement::addDoneServices(Service service) {
    doneServices.push_back(service);
    //possivelmente não estara a inserir por ordem ?
    //fazer antes um insert na pos correta?
}

void ServiceManagement::addToDoService(Service service) {
    toDoServices.push(service);
    //problema com as datas ?
}

// metodo remove o 1º elem da fila  toDoServices e passa-o para a lista doneServices
void ServiceManagement::DoneLatestService() {
    Service done = toDoServices.front();
    toDoServices.pop();
    addDoneServices(done);
}





