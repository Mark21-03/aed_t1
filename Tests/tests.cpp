#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "../include/Passenger.h"
#include "../include/ServiceManagement.h"

using testing::Eq;


TEST(test_passenger, genericTestOnClassPassenger) {

    Passenger aP(123456789, "Joaquim");

    ASSERT_EQ(aP.getName(), "Joaquim");
    ASSERT_EQ(aP.getID(), 123456789);

    aP.setName("Ricardo");
    aP.setID(1345);

    ASSERT_EQ(aP.getName(), "Ricardo");
    ASSERT_EQ(aP.getID(), 1345);

}

TEST(test_passenger, passengerBuyingTickets) {

    Passenger aP(123456789, "Joaquim");

    Date d;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Ticket at(f);

    aP.addTicket(at);

    Ticket r = aP.getNextFlights().front();
    ASSERT_EQ(r, at
    );

}

TEST(test_passenger, passengerOperator) {

    Passenger aP(123456789, "Joaquim Andre Araujo de Matos ");

    Date d;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, 3.5, "Porto", "Lisbon");

    Ticket at(f);
    Ticket at2(f2);

    aP.addTicket(at);
    aP.addTicket(at2);
    cout << aP ;
}

TEST(test_flights, inoutOperator) {
    Passenger aP(123456789, "Joaquim Andre Araujo de Matos ");
    Passenger aP2(12002, "Orlando Manuel da Silva Pinto");

    Date d;
    vector<Flight> v;

    ASSERT_EQ(aP.getName(), "Joaquim Andre Araujo de Matos ");
    ifstream ifs("../Files/Flights/flights.txt");


    Flight flight;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, 6.5, "Porto", "Roma");
    Flight f3(260, d, 1.5, "Porto", "Rio de Janeiro");


    while(ifs >> flight) { // TODO: THIS ISN'T READING ALL THE FLIGHTS
        v.push_back(flight);
        ifs.ignore();
    }

    Ticket at(v[0]);
    Ticket at2(v[1]);

    aP.addTicket(at);
    aP.addTicket(at2);

    ifs.close();

    std::ofstream ofs("../Files/Passengers/passengers.txt", ios::app);
    std::ofstream ofsF("../Files/Flights/flights.txt", ios::app);


   ASSERT_EQ(v[0].getOrigin(), "Porto"); // NOTE : THIS WILL FAIL TO MORE THAN ONE WORD: THE SOLUTION IS IN PASSENGER.H
   ASSERT_EQ(v[0].getDestiny(), "Lisbon");
   ASSERT_EQ(v[2].getDestiny() , "Rio de Janeiro");
    //ofs << aP << aP2;
    //ofsF << f << f2 << f3;


}

TEST(test_passenger, inOperatorsPassenger) { // NOTE: THIS TEST WAS FAILING

    ifstream s("../Files/Passengers/passengers.txt");
    Passenger p;
    s>>p;
    ASSERT_EQ(p.getID(),123456789);
    ASSERT_EQ(p.getName(),"Joaquim Andre Araujo de Matos");

}

TEST(test_passenger, CompareOperatorsPassenger) {

    Passenger p1(12357,"Marco");
    Passenger p2(12357,"André");
    Passenger p3(9305,"Carlos");

    ASSERT_EQ(p1 == p2,true);
    ASSERT_EQ(p1!=p2,false);
    ASSERT_EQ(p1<p2,false);
    ASSERT_EQ(p2 == p3,false);
    ASSERT_EQ(p1!=p3,true);
    ASSERT_EQ(p3<p2,true);

}

TEST(test_ServiceManagement, OperatorsManagement) {

    Date d1("2012/03/21");
    Date d2("2018/11/29");
    Date d3("2021/03/01");
    Service s1('c',d1,"Rui Rocha");
    Service s2('o',d2,"Pedro Moreira");
    Service s3('m',d3,"Alfredo Costa");

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;


}