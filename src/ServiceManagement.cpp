#include "../include/ServiceManagement.h"


void ServiceManagement::setDoneServices(list<Service> doneServices) { this->doneServices=doneServices;}
void ServiceManagement::setToDoServices(queue<Service> toDoServices) {this->toDoServices=toDoServices;}

list<Service> ServiceManagement::getDoneServices() const{return this->doneServices;}
queue<Service> ServiceManagement::getToDoServices() const {return this->toDoServices;}

void ServiceManagement::addDoneServices(Service service) {
    doneServices.push_back(service);
}

void ServiceManagement::addToDoService(Service service) {

    queue<Service> aux = toDoServices;
    queue<Service> q;

    bool inserted = false;

    while(!aux.empty()){
        Service temp = aux.front();

        if(!inserted && (temp.getDate()>=service.getDate())){
            q.push(service);
            inserted = true;
        }else{
            q.push(temp);
            aux.pop();
        }

    }

    toDoServices = q;

}


void ServiceManagement::DoneLatestService() {
    Service done = toDoServices.front();
    toDoServices.pop();
    addDoneServices(done);
}


ServiceManagement::ServiceManagement(const string &path) : path(path){

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


bool ServiceManagement::deleteTodoService(const Service &service) {

    bool found = false;
    queue<Service> auxQ = toDoServices;
    queue<Service> qDeleted;

    while(!auxQ.empty()){
        Service temp = auxQ.front();

        if(temp != service)
            qDeleted.push(temp);
        else
            found = true;

        auxQ.pop();
    }

    toDoServices = qDeleted;

    return found;
}

void ServiceManagement::changeTodoServicePriority(const Service &service, const Date &newDate) {

    //Remove Service to be updated
    deleteTodoService(service);

    //Now add the correct order
    queue<Service> aux = toDoServices;
    queue<Service> q;

    Service newService = service;
    newService.setDate(newDate);

    bool inserted = false;

    while(!aux.empty()){
        Service temp = aux.front();

        if(!inserted && (temp.getDate()>=service.getDate())){

            q.push(newService);
            inserted = true;
        }else{
            q.push(temp);
            aux.pop();
        }

    }

    toDoServices = q;


}

bool ServiceManagement::findTodoService(const Service &service) {

    queue<Service> q = toDoServices;

    while(!q.empty()){

        if(q.front() == service)
            return true;

            q.pop();
    }

    return false;
}

void ServiceManagement::saveToFile() {

    std::ofstream ofs(path);

    ofs << toDoServices.size() <<'\n';
    while (!toDoServices.empty()) {
        ofs << toDoServices.front();
        toDoServices.pop();
    }
    ofs << doneServices.size() << '\n';
    while (!doneServices.empty()) {
        ofs << doneServices.front();
        doneServices.pop_front();
    }

    ofs.close();
}






