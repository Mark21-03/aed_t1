#include "include/Menu.h"
#include "include/LoginMenu.h"
#include <future>
#include <thread>


int main() {
    LoginMenu loginMenu;
    loginMenu.displayLogin(cout);
    try {
        Manager manager;
        Menu menu(manager);
        menu.mainMenu();
    }catch (exception& e) {
        exit(0);
    }
    return 0;
}