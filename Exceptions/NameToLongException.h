//
// Created by ricar on 29/11/2021.
//

#ifndef AED_T1_NAMETOLONGEXCEPTION_H
#define AED_T1_NAMETOLONGEXCEPTION_H


#include <exception>

class NameToLongException : public std::exception {
    const char* what() const noexcept override
    {
        return "The Name of the passenger is too long to be accepted.";
    }
};
#endif //AED_T1_NAMETOLONGEXCEPTION_H
