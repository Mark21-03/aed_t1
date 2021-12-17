#ifndef AED_T1_INVALIDDATE_H
#define AED_T1_INVALIDDATE_H

#include <iostream>

using namespace std;

class invalidDate{
public:
    invalidDate(std::string reason) : reason(reason) {};
    const std::string& what()const {
        return reason;
    }
private:
    std::string reason;

};


#endif
