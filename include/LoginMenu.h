#ifndef AED_T1_LOGINMENU_H
#define AED_T1_LOGINMENU_H


#include "Output.h"

/**
 *
 */
class LoginMenu {
    std::string menuImage;
public:
    LoginMenu();
    void displayLogin(ostream& os) const;
};


#endif //AED_T1_LOGINMENU_H
