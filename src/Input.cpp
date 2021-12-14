//
// Created by ricar on 14/12/2021.
//
#include "../include/Input.h"

namespace in {

    std::string trimStr(std::istream& ios, std::string str) {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
        return str;
    }

    bool emptyStream(std::istream& ios) {
        std::string bufferContent;
        getline(ios, bufferContent);
        trimStr(ios, bufferContent);
        if (bufferContent.empty())
            return true;
        return false;
    }

    void giveMenuInputError(std::string &s) {
        s = "\nInvalid input was given.\nPlease provide a number from the menu.\n\n";
    }

}