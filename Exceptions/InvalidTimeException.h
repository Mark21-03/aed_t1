#ifndef AED_T1_INVALIDTIMEEXCEPTION_H
#define AED_T1_INVALIDTIMEEXCEPTION_H


#include <exception>

/**
 * Exception class to be thrown when an invalid time tries to be set outside the format HH:MM:SS
 */
class InvalidTimeException : public std::exception {
    const char *what() const noexcept override {
        return "The time provided is invalid.";
    }
};


#endif //AED_T1_INVALIDTIMEEXCEPTION_H
