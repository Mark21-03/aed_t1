#include "../include/ServiceManagement.h"


void ServiceManagement::setDoneServices(list<Service> doneServices) { this->doneServices=doneServices;}
void ServiceManagement::setToDoServices(queue<Service> toDoServices) {this->toDoServices=toDoServices;}

list<Service> ServiceManagement::getDoneServices() const{return this->doneServices;}
queue<Service> ServiceManagement::getToDoServices() const {return this->toDoServices;}

void ServiceManagement::addDoneServices(Service service) {
    doneServices.push_back(service);
}

void ServiceManagement::addToDoService(Service service) {
    toDoServices.push(service);
}


void ServiceManagement::DoneLatestService() {
    Service done = toDoServices.front();
    toDoServices.pop();
    addDoneServices(done);
}

ServiceManagement::ServiceManagement(const string &path) {
    std::ifstream ifs(path);

    Service service;
    int n; ifs >> n;
    for (int i = 0; i < n; ++i) { // the Todo
        ifs >> service;
        toDoServices.push(service);
    }

    ifs >> n;
    for (int i = 0; i < n; ++i) { // the Done
        ifs >> service;
        doneServices.push_back(service);
    }

    ifs.close();
}

void ServiceManagement::showDoneServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const {
    out::headerServices(ostream1);
    auto it = lower_bound(doneServices.begin(), doneServices.end(), Service('c', min,"",""));

    for (;it!=doneServices.end();it++) {
        if (it->getDate() > max) break;
        out::services(ostream1,it);
    }

}

void ServiceManagement::showToDoServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const {
    out::headerServices(ostream1);

    if (toDoServices.empty()) return;

    queue<Service> temp = toDoServices;
    Service front = temp.front();
    temp.pop();

    while (front.getDate() <= max) {
        if (front.getDate() >= min)
            out::services(ostream1,&front);
        if (temp.empty()) break;
        front = temp.front();
        temp.pop();
    }
}







