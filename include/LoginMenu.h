#ifndef AED_T1_LOGINMENU_H
#define AED_T1_LOGINMENU_H


#include "Output.h"

/**
 * The log in menu of the application.
 */
class LoginMenu {
    /**
     * the menu intro image.
     */
    std::string menuImage;
public:
    /**
     * A default constructor to the login class.
     */
    LoginMenu();

    /**
     * Displays onto the ostream the login menu.
     * @param os the ostream to which the login screen will be shown
     */
    void displayLogin(ostream &os) const;
};


#endif //AED_T1_LOGINMENU_H
