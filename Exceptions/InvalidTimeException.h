#ifndef AED_T1_INVALIDTIMEEXCEPTION_H
#define AED_T1_INVALIDTIMEEXCEPTION_H


#include <exception>

class InvalidTimeException : public std::exception {
    const char* what() const noexcept override
    {
        return "The time provided is invalid.";
    }
};


#endif //AED_T1_INVALIDTIMEEXCEPTION_H
