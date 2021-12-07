#include "../include/Manager.h"




void Manager::setPaths(){
    ifstream dirs(filesDir);

    getline(dirs,flights_path);
    getline(dirs,planes_path);
    getline(dirs,passengers_path);

}


Manager::Manager() {

    setPaths();

    std::ifstream ifs_flights(flights_path);

    Flight flight;
    while (ifs_flights >> flight) {
        flights.push_back(flight);
    }


    ifs_flights.close();


    std::ifstream ifs_passengers(passengers_path);



    Passenger passenger;
    while (ifs_passengers >> passenger) {
        passengers.push_back(passenger);
    }

    ifs_passengers.close();

    std::ifstream ifs_planes(planes_path);

    Plane plane;
    while (ifs_planes >> plane) {
        planes.push_back(plane);
    }

    ifs_planes.close();

}


void Manager::showSortedPassengers(ostream &ostream1) {

    ostream1<<"ID\t"<<"Name"<<endl;

    for (const auto& p: passengers) {
    ostream1 << SEPARATION << std::endl;
        ostream1 << p.getID()<<"\t"<<p.getName()<< '\n';
    }

}

void Manager::showSortedFlights(ostream &ostream1) {

    using namespace std;
    ostream1 << right;
    ostream1<<setfill(' ')<<"Number\t\t"<<setw(15)<<"Departure Date "<< setw(15) << "Departure Time"<<setw(30)<<"Origin "<<setw(40)<<"Destiny"<<"\n";
    ostream1 << SEPARATION << SEPARATION  <<"------------------------" <<"\n" << left<< setfill(' ') ; // MAYBE PUT THIS STUFF in a Macro

    for (const auto& f: flights) { // TODO : MAGIC NUMBERS ...
        ostream1 <<setw(15) << f.getNumber() <<setw(15)<<f.getDepartureDate().getDate() <<setw(15) << f.getDepartureTime().getTime()
        <<setw(50)<<f.getOrigin()<<setw(45)<<" ⟶ " + f.getDestiny()<< "\n";
    }
}




void Manager::showSortedPlanes(ostream &ostream1) {

    ostream1<<"Plate\t"<< "Type\t"<<"Capacity\t" <<"Number of Flights\r"<<'\n';
    ostream1 << SEPARATION << std::endl;

    for (const auto& p : planes) { // TODO :: ALL THIS FUNCTIONS CAN HAVE A DIFF OUTPUT - IN HERE (do not overload <<)
        ostream1 << p.getNumberPlate() << '\t' << p.getType() << '\t' << p.getCapacity() << "\t\t"<<p.getFlightPlan().size()<<'\n';
    }
}
