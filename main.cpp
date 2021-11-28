#include <iostream>
#include <vector>

#include "Date.hpp"
#include "Plane.hpp"
#include "Flight.hpp"

using namespace std;

int main(){

    Date d("20-05-2010");
    cout<<d<<endl;

    Flight f(21368,d,12.3,"Lisbon","Porto");
    vector<Flight> v = {f};

    Plane a("A134",213,v);

    string str = a.getFlightPlan()[0].getOrigin();

    cout<<str<<endl;

}