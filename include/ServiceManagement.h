#ifndef AED_T1_SERVICEMANAGEMENT_H
#define AED_T1_SERVICEMANAGEMENT_H

#include <list>
#include <queue>
#include "../include/Service.h"

class ServiceManagement{
private:
    list<Service> doneServices;
    queue<Service> toDoServices;
public:
    void setDoneServices(list<Service> doneServices);
    void setToDoServices(queue<Service> toDoServices);
    list<Service> getDoneServices() const;
    queue<Service> getToDoServices() const;
    void addDoneServices(Service service);
    void addToDoService(Service service);
    void DoneLatestService();
    void printAllDoneServices() const;
};

#endif //AED_T1_SERVICEMANAGEMENT_H
