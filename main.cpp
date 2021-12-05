#include "include/MenuAlpha.h"

int main() {
    Manager manager("../Files/Flights/flights.txt", "../Files/Passengers/passengers.txt","../Files/Planes/planes.txt");
    Menu menu(manager);
    menu.mainMenu();
    return 0;
}