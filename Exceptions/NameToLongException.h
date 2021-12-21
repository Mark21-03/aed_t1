#ifndef AED_T1_NAMETOLONGEXCEPTION_H
#define AED_T1_NAMETOLONGEXCEPTION_H


#include <exception>

/**
 * Exception class to be thrown when trying to set a name with more chars then the allowed number
 */
class NameToLongException : public std::exception {
    const char *what() const noexcept override {
        return "The String passed is too long to be accepted.";
    }
};

#endif //AED_T1_NAMETOLONGEXCEPTION_H
