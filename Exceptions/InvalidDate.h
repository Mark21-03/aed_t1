#ifndef DateException_H
#define DateException_H

#include <iostream>
using namespace std;

class InvalidDate // THIS SHOULD INERT FROM EXCEPTION CLASS : TODO
{
public:
    InvalidDate(std::string reason) :reason(reason) {};
    const std::string& what()const {
        return reason;
    }
private:
    std::string reason;

};


#endif
