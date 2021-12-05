#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <fstream>
#include "../include/Passenger.h"
#include "../include/ServiceManagement.h"
#include "../include/Time.h"
#include "../include/Manager.h"
#include "../include/MenuAlpha.h"

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

    //aP.addTicket(at);

   // Ticket r = aP.getNextFlights().front();
   // ASSERT_EQ(r, at);

}

TEST(test_passenger, passengerOperator) {

    Passenger aP(123456789, "Joaquim Andre Araujo de Matos ");

    Date d;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, 3.5, "Porto", "Lisbon");

    Ticket at(f);
    Ticket at2(f2);

    // aP.addTicket(at);
    // aP.addTicket(at2);
    cout << aP ;
}

TEST(test_flights, inoutOperator) {
    Passenger aP(123456789, "Joaquim Andre Araujo de Matos");
    Passenger aP2(12002, "Orlando Manuel da Silva Pinto");

    Date d;
    vector<Flight> v;

    ASSERT_EQ(aP.getName(), "Joaquim Andre Araujo de Matos");
    ifstream ifs("../Files/Flights/flights.txt");


    Flight flight;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, 6.5, "Porto", "Roma");
    Flight f3(260, d, 1.5, "Porto", "Rio de Janeiro");

    cout << f << endl;
    cout << f3 << endl;

    while(ifs >> flight) {
        v.push_back(flight);
    }

    Ticket at(v[0]);
    Ticket at2(v[1]);

    // aP.addTicket(at);
    // aP.addTicket(at2);

    ifs.close();

    std::ofstream ofs("../Files/Passengers/passengers.txt", ios::app);
    std::ofstream ofsF("../Files/Flights/flights.txt", ios::app);


   ASSERT_EQ(v[0].getOrigin(), "Copenhagen Airport");
   ASSERT_EQ(v[0].getDestiny(), "Beirut Rafic Hariri International Airport");
   ASSERT_EQ(v[2].getDestiny() , "Beirut Rafic Hariri International Airport");
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

TEST(Test_Baggage, BaggageStruct) {


    Baggage b1(7.34,3);
    Baggage b2(2.34,1,true);

    ASSERT_EQ(b1.quantity,3);
    ASSERT_EQ(b1.handheld,false);
    ASSERT_EQ(b2.weight,(float)2.34);
    ASSERT_EQ(b2.handheld,true);

}

TEST(Test_Time, TimeGetSetException) {

    Time t1(21,12,59);

    ASSERT_EQ(t1.getHour(),21);
    ASSERT_EQ(t1.getMinute(),12);
    t1.setTime(1,2,0);
    ASSERT_EQ(t1.getSecond(),0);

    // Current Time
    Time r;
    cout << r;

    try{
        Time t2(24,0,0);
        ASSERT_EQ(true,false); //this should never run
    }catch(InvalidTimeException){
        NULL;
    }
    try{
        Time t2(1,61,0);
        ASSERT_EQ(true,false); //this should never run
    }catch(InvalidTimeException){
        NULL;
    }
    try{
        Time t2(-1,0,60);
        ASSERT_EQ(true,false); //this should never run
    }catch(InvalidTimeException){
        NULL;
    }


}


TEST(Test_Time, TimeOverloading) {

    Time t1(21,12,0);
    Time t2(21,12,45);

    ASSERT_EQ(t1<t2,true);
    t1.setSecond(48);
    ASSERT_EQ(t1<t2,false);
    ASSERT_EQ(t1!=t2,true);
    t1.setTime(21,12,45);
    ASSERT_EQ(t1==t2,true);
    ASSERT_EQ(t1<=t2,true);

    stringstream in("3:24:19");
    in>>t2;cout<<t2<<endl; //should output 03:24:19
}

TEST(Test_Manager, ManagerBasicMethods) {
    Manager manager("../Files/Flights/flights.txt", "../Files/Passengers/passengers.txt", "../Files/Planes/planes.txt");

    cout << "Manager:" << endl;
    // manager.showSortedFlights(std::cout); // as we are using dependency injection we could have passed other ostream and verified the string
}

TEST(Test_Menu, MenuManagerBehaviour) {
    Manager manager("../Files/Flights/flights.txt", "../Files/Passengers/passengers.txt", "../Files/Planes/planes.txt");
    Menu menu(manager);


    // menu.mainMenu();

}
TEST(Test_Plane, InOutOperators) {
    std::list<int> lF{0,30,40};
    Plane plane("A00", 120, lF);

    std::ofstream ofs("../Files/Planes/planes.txt"); // WE COULD TEST WITH SSTRINGs

    ofs << plane;

    ofs.close();

    std::ifstream ifs("../Files/Planes/planes.txt");

    Plane plane2;

    ifs >> plane2;

    ASSERT_EQ(plane.getNumberPlate(), plane2.getNumberPlate());
    ASSERT_EQ(plane.getCapacity(), plane2.getCapacity());

    ASSERT_EQ(plane.getFlightPlan().size(), plane2.getFlightPlan().size());
    ifs.close();
}



/*
TEST(Creator_test, CreatingPassengers) {

    ofstream ofs("../Files/Passengers/passengers.txt", ios::app);

    vector<string> names_male {
            "João",
            "Rodrigo",
            "Francisco",
            "Martim",
            "Santiago",
            "Tomás",
            "Afonso",
            "Duarte",
            "Miguel",
            "Guilherme",
            "Tiago",
            "Gonçalo",
            "Diogo",
            "Gabriel",
            "Pedro",
            "Rafael",
            "Salvador",
            "Dinis",
            "Lucas",
            "Simão",
            "Gustavo",
            "David",
            "José",
            "Vicente",
            "Lourenço",
            "Diego",
            "Daniel",
            "António",
            "André",
            "Vasco",
            "Manuel",
            "Henrique",
            "Leonardo",
            "Bernardo",
            "Mateus",
            "Luís",
            "Eduardo",
            "Alexandre",
            "Leandro",
            "Filipe",
            "Enzo",
            "Ricardo",
            "Matias",
            "Rúben",
            "Samuel",
            "Bruno",
            "Isaac"
    };
    vector<string> name_female{
            "Eliana",
            "Cecília",
            "Sarah",
            "Liara",
            "Fátima",
            "Dânia",
            "Mayara",
            "Emily",
            "Márcia",
            "Carina",
            "Sónia",
            "Aléxia",
            "Flávia",
            "Lívia",
            "Susana",
            "Carmo",
            "Eliane",
            "Anamar",
            "Alana",
            "Clarisse",
            "Solange",
            "Leticia",
            "Sílvia",
            "Isa",
            "Telma",
            "Nayara",
            "Lídia",
            "Kiara",
            "Oriana",
            "Denise",
            "Liane",
            "Natacha",
            "Viviane",
            "Cíntia",
            "Frederica",
            "Rute",
            "Luz",
            "Magda",
            "Antónia",
            "Neuza",
            "Tamára",
            "Marina",
            "Naíma",
            "Dalila",
            "Samira",
            "Jade",
            "Angélica",
            "Angelina",
            "Milena"
    };
    vector<string> sur_names {
            "Soares",
            "Vieira",
            "Monteiro",
            "Moreira",
            "Cardoso",
            "Duarte",
            "Nunes",
            "Rocha",
            "Coelho",
            "Neves",
            "Reis",
            "Pires",
            "Cunha",
            "Machado",
            "Matos",
            "Fonseca",
            "Ramos",
            "Tavares",
            "Freitas",
            "Simões",
            "Cruz",
            "Antunes",
            "Figueiredo",
            "Barbosa",
            "Castro",
            "Araújo",
            "Azevedo",
            "Lima",
            "Lourenço",
            "Faria",
            "Morais",
            "Andrade",
            "Henriques",
            "Mota",
            "Pinheiro",
            "Afonso",
            "Barros",
            "Miranda",
            "Baptista"
    };
    std::srand(time(nullptr));
for(int i = 0; i < 1000; i++) {

    string name;
    bool b = (bool)(rand() % 2);

    int l = rand() % 2 +1;

    if(b) {
        int z = rand() % 2 +1; // nomes próprios
        for(int k= 0; k < z; k++) {
            name += names_male[rand() % names_male.size()];
            name += " ";
        }
    }else {
        int z = rand() % 2 +1; // nomes próprios
        for(int k= 0; k < z; k++) {
        name += name_female[rand() % name_female.size()];
        name += " ";
        }
    }


    for(int k= 0; k < l; k++) {
        name += sur_names[rand() % sur_names.size()];
        if(k + 1 < l) {
           name += " ";
        }
    }
    Passenger passenger(i, name);

    ofs << passenger;
    }
    ofs.close();
}
*/
/*
TEST(Creator_test, CreationFlights) {
std::ofstream ofsF("../Files/Flights/flights.txt", ios::app);

// TODO : ADD THE IATA CODE ... and maybe an airport struct

vector<string> airports{
        "Beirut Rafic Hariri International Airport" ,
        "Budapest Ferihegy International Airport" ,
        "Cairo International Airport" ,
        "Copenhagen Airport" ,
        "Dubai International Airport" ,
        "Metropolitan Area" ,
        "Paris Orly Airport" ,
        "Francisco de Sá Carneiro Airport"
};

for(int i = 0; i< 365; i++) {
    Date date;

    int add = rand() % 365 ;

    while (add) {
        add--; date++;
    }

    int o = rand() % airports.size();
    int d;
    while(d =rand() % airports.size() == o ); // TODO: THE DURATION COULD BE A TIME OBJECT
    float r =  1.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(4.0f-1.0f)));
    Flight flight(i,date, r ,airports[o], airports[d]);
    ofsF << flight;
}
}*/