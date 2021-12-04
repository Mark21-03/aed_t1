#include "include/MenuAlpha.h"

int main() {
    Manager manager("../Files/Flights/flights.txt");
    Menu menu(manager);
    menu.mainMenu();
    return 0;
}