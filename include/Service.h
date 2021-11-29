#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Date.h"
#include <queue>

class Service{
private:
    char type; //m=manutenção, l=limpeza
    Date date;
    string employer;
    queue<Service> doneServices;
public:
    Service()=default;
    Service(char type, Date date, string employer);

    void setType(char type);
    void setDate(Date date);
    void setEmployer(string employer);
    void setDoneServices(queue<Service> doneServices);

    char getType() const;
    Date getDate() const;
    string getEmployer() const;
    queue<Service> getDoneServices() const;
};

#endif //SERVICO_H
