//
// Created by ricar on 14/12/2021.
//

#ifndef AED_T1_INPUT_H
#define AED_T1_INPUT_H

#include <ostream>
#include <string>
#include <iostream>


namespace in {

    std::string trimStr(std::istream& ios, std::string str);
    bool emptyStream(std::istream& ios = std::cin);
    void giveMenuInputError(std::string &s );
    inline void dealError(std::string& inputError, std::istream& ios = std::cin, std::ostream& ost = std::cout) {
        if (ios.eof()) {
            ost << "\nEnd of program.\n";
            exit(1); //detects CTRL+Z
        }

        ios.clear();
        ios.ignore(1000, '\n');
        in::giveMenuInputError(inputError);
    }

}

#endif //AED_T1_INPUT_H
