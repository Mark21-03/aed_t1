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
    FilePath = path;

    std::ifstream ifs(path);

    Service service;
    int n; ifs >> n;
    for (int i = 0; i < n; ++i) { // scheduled services
        ifs >> service;
        toDoServices.push(service);
    }

    ifs >> n;
    for (int i = 0; i < n; ++i) { // the already done services
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

ServiceManagement::~ServiceManagement() {

    std::ofstream ofs(FilePath);

    // scheduled services
    ofs << toDoServices.size()<<endl;
    while (!toDoServices.empty()) {
        ofs << toDoServices.front();
        toDoServices.pop();
    }

    // the already done services
    ofs << doneServices.size()<<endl;
    for (auto it = doneServices.begin();it!=doneServices.end();it++) {
        ofs << *it;
    }

}







