#ifndef AED_T1_SERVICEMANAGEMENT_H
#define AED_T1_SERVICEMANAGEMENT_H

#include <list>
#include <queue>
#include <fstream>
#include "../include/Service.h"
#include "../include/Output.h"

class ServiceManagement{
private:
    list<Service> doneServices;
    queue<Service> toDoServices;
public:

    ServiceManagement(const std::string& path);

    ServiceManagement() = default;

    void setDoneServices(list<Service> doneServices);
    void setToDoServices(queue<Service> toDoServices);
    list<Service> getDoneServices() const;
    queue<Service> getToDoServices() const;
    void addDoneServices(Service service);
    void addToDoService(Service service);
    void DoneLatestService();
    void showDoneServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const;
};

#endif //AED_T1_SERVICEMANAGEMENT_H
