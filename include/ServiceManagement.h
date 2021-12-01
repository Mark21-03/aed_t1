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
    void setdoneServices(list doneServices);
    void setToDoServices(queue<Service> toDoServices);
    list<Service> getdoneServices() const;
    queue<Service> getToDoServices() const;
};

#endif //AED_T1_SERVICEMANAGEMENT_H
