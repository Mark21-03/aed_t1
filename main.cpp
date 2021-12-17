#include "include/Menu.h"

int main() {
    try {
        Manager manager;
        Menu menu(manager);
        menu.mainMenu();
    }catch (exception& e) {
        exit(0);
    }
    return 0;
}