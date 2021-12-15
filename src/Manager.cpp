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


void Manager::showSortedPassengersByID(ostream &ostream1, unsigned int min, unsigned int max) {

    out::headerPassengers(ostream1);

    auto it = lower_bound(passengers.begin(),passengers.end(), Passenger(min, ""));
    for (;it!=passengers.end();it++) {
        if (it->getID() > max) break;
        out::passenger(ostream1,it);
    }

}

void Manager::showSortedFlightsByID(ostream &ostream1, flightNumber min , flightNumber max) {

    using namespace std;

    out::headerFlights(ostream1);
    auto it = lower_bound(flights.begin(), flights.end(), Flight(min, Date(), Time(0,0,0),2.4, "", ""));

    for (;it!=flights.end();it++) {
        if (it->getNumber() > max) break;
        out::flights(ostream1,it);
    }
}


void Manager::showSortedPlanes(ostream &ostream1) {

    out::headerPlanes(ostream1);

    for (const auto& p : planes) { // TODO :: ALL THIS FUNCTIONS CAN HAVE A DIFF OUTPUT - IN HERE (do not overload <<)
       // put::planes
    }
}

void Manager::searchPassengers(int id){
    //enum attributePas {
      //  name,
    //};
    string attribute;
    string name;
    bool changed = false;
    for (auto it=passengers.begin();it!=passengers.end();it++){
        if ((*it).getID()==id) {
            std::cout << "Valid id. ";
            while (attribute != "name") {
              std::cout << "What attribute to change?";
              cin >> attribute;
              if (attribute == "name") {
                std::cout << "What name do you want?";
                cin >> name;
                passengers.erase(it);
                Passenger p1(id, name);
                passengers.push_back(p1);
                changed = true;
                break;
            } else {
                  cout<<"Invalid attribute! ";
            }
          }
        }
    }
    if (!changed) std::cout << "Invalid id!"<<endl;
}



