#ifndef AED_T1_INVALIDDATE_H
#define AED_T1_INVALIDDATE_H

#include <iostream>


/**
 * Exception class to be thrown when invalid date attributes try to be set
 */
class invalidDate {
public:
    /**
     * Default Constructor.
     */
    invalidDate(std::string reason) : reason(reason) {};

    const std::string &what() const {
        return reason;
    }

private:
    /**
     * the reason of the invalid Date exception.
     */
    std::string reason;

};


#endif
