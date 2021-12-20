#include "include/Menu.h"
#include "include/LoginMenu.h"
#include <thread>


int main() {
    setlocale(LC_ALL, "pt_PT.UTF-8");
    LoginMenu loginMenu;
    loginMenu.displayLogin(cout);
    getchar();
    try {
        Manager manager;
        Menu menu(manager);
        menu.mainMenu();
    }catch (exception& e) {
        exit(0);
    }
    return 0;
}