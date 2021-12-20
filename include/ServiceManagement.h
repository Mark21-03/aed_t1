#ifndef AED_T1_SERVICEMANAGEMENT_H
#define AED_T1_SERVICEMANAGEMENT_H

#include <list>
#include <queue>
#include <fstream>
#include "../include/Service.h"
#include "../include/Output.h"

class ServiceManagement {
private:
    list<Service> doneServices;
    queue<Service> toDoServices;
    std::string path;
public:

    /**
     * Constructs a ServiceManagement, loading all services in given file path
     * @param path file path where services are stored
     */
    explicit ServiceManagement(const std::string &path);

    /**
     * Default ServiceManagement Constructor
     */
    ServiceManagement() = default;

    /**
     * Sets the list of done services with a given one
     * @param newDoneServices new list to be set
     */
    void setDoneServices(list<Service> newDoneServices);

    /**
     * Sets the queue of To-do services with a given on
     * @param newToDoServices new queue to be set
     */
    void setToDoServices(queue<Service> newToDoServices);

    /**
     * Gives a copy of done service's list
     * @return done service's list copy
     */
    list<Service> getDoneServices() const;

    /**
     * Gives a copy of to-do service's queue
     * @return to-do service's queue copy
     */
    queue<Service> getToDoServices() const;

    /**
     * Adds a service to the end of done services list
     * @param service service to be added
     */
    void addDoneServices(Service service);

    /**
     * Adds a service to the to-do services queue taking into consideration
     * the date of the service being added, inserting it in the correct position
     * @param service service to be added
     */
    void addToDoService(Service service);

    /**
     * Changes the order in the to-do queue, by changing the position
     * of a service based on a new given date
     * @param service service to be rescheduled
     * @param newDate new rescheduled date to be set
     */
    void changeTodoServicePriority(const Service &service, const Date &newDate);

    /**
     * Removes a given service from the to-do queue returning boolean it was deleted
     * @param service service to be removed
     * @return boolean true if it was found and deleted else false
     */
    bool deleteTodoService(const Service &service);

    /**
     * Removes service at the front of to-do queue and adds it to the done services list
     */
    void DoneLatestService();

    /**
     * Returns boolean telling if a given service is in the to-do queue
     * @param service service to be searched
     * @return boolean true if given service is in to-do queue
     */
    bool findTodoService(const Service &service);

    /**
     * Shows done services from done service's list in the specified date range
     * @param ostream1 ostream to be used
     * @param min min data interval
     * @param max max data interval
     */
    void showDoneServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const;

    /**
     * Shows to-do services from done service's list in the specified date range
     * @param ostream1 ostream to be used
     * @param min min data interval
     * @param max max data interval
     */
    void showToDoServicesFromRange(ostream &ostream1, const Date &min, const Date &max) const;

    /**
     * Saves to file the changes made to the to-do queue or done list
     */
    void saveToFile();
};

#endif //AED_T1_SERVICEMANAGEMENT_H
