//
// Created by ricar on 14/12/2021.
//

#ifndef AED_T1_INPUT_H
#define AED_T1_INPUT_H

#include <ostream>
#include <string>
#include <iostream>


namespace in {

    /**
     * Removes (trims) blank spaces from beginning and ending of given string
     * @param ios istream to be used
     * @param str string to be trimmed
     * @return trimmed string
     */
    std::string trimStr(std::istream& ios, std::string str);

    /**
     * Tests if istream is empty
     * @param ios istream to be tested
     * @return boolean true if istream is empty
     */
    bool emptyStream(std::istream& ios = std::cin);

    /**
     * Prints given string as a menu error
     * @param s string to be used as error message
     */
    void giveMenuInputError(std::string &s );

    /**
     * Deals error if CTRL-Z is pressed terminating the program with a message
     * @param inputError message to be displayed
     * @param ios istream to test if CTRL-Z was pressed
     * @param ost ostream to output the message
     */
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
