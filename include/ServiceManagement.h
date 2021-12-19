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
    std::string path;
public:

    explicit ServiceManagement(const std::string& path);

    ServiceManagement() = default;

    void setDoneServices(list<Service> newDoneServices);
    void setToDoServices(queue<Service> newToDoServices);
    list<Service> getDoneServices() const;
    queue<Service> getToDoServices() const;
    void addDoneServices(Service service);
    void addToDoService(Service service);
    void changeTodoServicePriority(const Service& service, const Date& newDate);
    bool deleteTodoService(const Service &service);
    void DoneLatestService();
    bool findTodoService(const Service &service);
    void showDoneServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const;
    void showToDoServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const;

    void saveToFile() ;
};

#endif //AED_T1_SERVICEMANAGEMENT_H
