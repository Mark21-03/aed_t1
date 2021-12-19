#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <fstream>
#include <algorithm>
#include "../include/Passenger.h"
#include "../include/ServiceManagement.h"
#include "../include/Time.h"
#include "../include/Manager.h"
#include "../include/Menu.h"

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
    Time time1(0,0,0);

    Flight f(140, d, time1, 3.5, "Porto", "Lisbon");
//    Ticket at(f);

    //aP.addTicket(at);

   // Ticket r = aP.getNextFlights().front();
   // ASSERT_EQ(r, at);

}

TEST(test_passenger, passengerOperator) {

    Passenger aP(123456789, "Joaquim Andre Araujo de Matos ");

    Date d;
    Time time1(0,0,0);

    Flight f(140,  d, time1, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, time1, 3.5, "Porto", "Lisbon");

    //Ticket at(f);
    //Ticket at2(f2);
//
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
    ifstream ifs("../Files/flights.txt");


    Flight flight;
    Time time1(12,0,0);
    Flight f(140,  d, time1, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, time1, 6.5, "Porto", "Roma");
    Flight f3(260, d, time1, 1.5, "Porto", "Rio de Janeiro");

    cout << f << endl;
    cout << f3 << endl;

    int i = 0;
    try {
    while(ifs >> flight) {
        i++;
        v.push_back(flight);
    }
    }catch (InvalidTimeException& e) {
        cout << i;

        exit(1);
    }

    // Ticket at(v[0]);
    // Ticket at2(v[1]);

    // aP.addTicket(at);
    // aP.addTicket(at2);

    ifs.close();

    std::ofstream ofs("../Files/Passengers/passengers.txt", ios::app);
    std::ofstream ofsF("../Files/Flights/flights.txt", ios::app);


   ASSERT_EQ(v[0].getOrigin(), "Cairo International Airport");
   ASSERT_EQ(v[0].getDestiny(), "Budapest Ferihegy International Airport");
   ASSERT_EQ(v[2].getDestiny() , "Budapest Ferihegy International Airport");



}

TEST(test_passenger, inOperatorsPassenger) { // NOTE: THIS TEST WAS FAILING

    ifstream s("../Files/passengers.txt");
    Passenger p;
    s>>p;
    ASSERT_EQ(p.getID(),0);
    ASSERT_EQ(p.getName(),"Frederica Neves");

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
    Service s1('c',d1,"Rui Rocha", "CS-AKJ");
    Service s2('o',d2,"Pedro Moreira","CS-AKJ");
    Service s3('m',d3,"Alfredo Costa", "CS-AKJ");

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;

    istringstream istringstream1("99 2012/03/21Rui Rocha                                    CS-AKJ");

    Service s;
    istringstream1 >> s;

    ASSERT_EQ(s.getType(), cleaning);
    ASSERT_EQ(s.getDate().getDate(), "2012/03/21");

}

TEST(Test_Baggage, BaggageStruct) {


    Baggage b1(7.34,3);
    Baggage b2(2.34,1,true);

    ASSERT_EQ(b1.getQuantity(),3);
    ASSERT_EQ(b1.getHandheld(),false);
    ASSERT_EQ(b2.getWeight(),(float)2.34);
    ASSERT_EQ(b2.getHandheld(),true);

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
    //Manager manager;
    //cout << "Manager:" << endl;
    // manager.showSortedFlights(std::cout); // as we are using dependency injection we could have passed other ostream and verified the string
}

TEST(Test_Menu, MenuManagerBehaviour) {
    //manager manager;
    //Menu menu(manager);


    // menu.mainMenu();

}
TEST(Test_Plane, InOutOperators) {
    std::list<flightNumber> lF{0,30,40}; // NOT ON TEST HERE
    Plane plane("CS-AKJ" , "A321", 200, lF);

    std::ifstream ifs("../Files/planes.txt");

    Plane plane2;

    ifs >> plane2;

    ASSERT_EQ(plane.getNumberPlate(), plane2.getNumberPlate());
    ASSERT_EQ(plane.getCapacity(), plane2.getCapacity());

    ifs.close();
}

TEST(Test_Plane, genericTestOnClassPlane){
    std::list<flightNumber> fp={20,40,50};
    Plane p1("B11", "A00",140,fp);

    ASSERT_EQ(p1.getCapacity(),140);
    ASSERT_EQ(p1.getNumberPlate(), "B11");
    ASSERT_EQ(p1.getFlightPlan(), fp);

    p1.setCapacity(210);
    p1.setNumberPlate("A10");
    p1.setFlightPlan({10,30,40});

    list<flightNumber> lTest={10,30,40};

    ASSERT_EQ(p1.getFlightPlan(), lTest);
    ASSERT_EQ(p1.getNumberPlate(), "A10");
    ASSERT_EQ(p1.getCapacity(), 210);
}

TEST (Test_Plane, CompareOperatorsPlane){
    Plane p1("B00", "rr", 150, {10,30});
    Plane p2("A80", "rr" ,260, {10,30});
    Plane p3("B00","rr" ,300, {40,70,80});

    ASSERT_EQ(p1==p3, true);
    ASSERT_EQ(p1!=p3, false);
    ASSERT_EQ(p1<p3, false);
    ASSERT_EQ(p2==p3, false);
    ASSERT_EQ(p2<p3, true);
    ASSERT_EQ(p1!=p2, true);
    ASSERT_EQ(p1<p2, false);
}

TEST(Test_Plane, inOperatorsPlane) { // NOTE: THIS TEST WAS FAILING

    ifstream i("../Files/planes.txt");
    Plane p1;
    i>>p1;
    ASSERT_EQ(p1.getNumberPlate(), "CS-AKJ");
    ASSERT_EQ(p1.getCapacity(),200);
    ASSERT_EQ(p1.getFlightPlan().size(), 6);
}

TEST(Test_Plane, outOperatorPlane){
    list<flightNumber> fl={20,30,50};
    Plane p1("B20", "EEE", 160, fl);

    cout<<p1;
}

TEST(Test_Service, inOperator) {
    ServiceManagement serviceManagement("../Files/services.txt");

    for ( auto a : serviceManagement.getDoneServices() ) {
        cout << a.getInfo() << endl;
    }

}

TEST(Test_Menu, menuLoopBUG) {

}

TEST(Test_time, randomTime) {
    Time t;
    srand(time(NULL));
    t.setRandomTime();

    cout << t;
}

/*
TEST(ddd,kffm) {
ifstream i("../Files/Planes/planes.txt");
vector<Plane> v;

Plane plane;

while(i >> plane) {
    v.push_back(plane);
}

sort(v.begin(),v.end());
i.close();
std::ofstream o("../Files/Planes/planes.txt");

for(auto f: v) {
    o<<f;
}

}
*/
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
}*/

/*
TEST(Creator_test, CreationFlights) {
srand(time(nullptr));
std::ofstream ofsF("../Files/flights.txt");

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

for(unsigned int i = 0; i< 365; i++) {

    Date date;

    int add = rand() % 365 ; // creating flights for a year

    while (add) {
        add--; date++;
    }

    int o = rand() % airports.size();
    int d;
    do {
        d =rand() % airports.size();
    }
    while(d == o );
    int occupation = rand() % 170;
    float r =  1.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(4.0f-1.0f)));
    Time time2;
    time2.setRandomTime();

    Flight flight(i,date, time2 ,occupation ,r ,airports[o], airports[d]);
    ofsF << flight;
}

}
*/

/*
TEST(Creator_test, creatingPlanes) { // THIS TEST FAILS IF THE NUMBER OF FLIGHTS TO BE ATTRIBUTE TO A PLANE IS MORE THAN 0
    std::ofstream ofP("../Files/Planes/planes.txt");

    std::vector<int> v;
    std::vector<string> s;
    std::vector<pair<string, int>> mapTypeToCapacity = {
            {"A310" , 220} ,
            {"A310" , 170} ,
            {"A321" ,200} ,
            {"A330" ,440} ,
            {"A340" ,370} ,
            {"B737" ,188} ,
            {"B747" ,524}
    };
    std::srand(time(nullptr));

for(int i = 0; i< 365; i++) {
    v.push_back(i);
}
int nFlights = 365;
    for (int i=0; i<8; i++) {
        string plate ;
        char ch1, ch2, ch3;
        const std::string se = "CS-";
        do{
            ch1 = rand() % 26 + 'A'; // https://en.wikipedia.org/wiki/List_of_aircraft_registration_prefixes
            ch2 = rand() % 26 + 'A';
            ch3 = rand() % 26 + 'A';
            plate = se + ch1 + ch2 +ch3 ;
        }while(find(s.begin(),s.end(), plate) != s.end());

        s.push_back(plate);


        int o = rand() % mapTypeToCapacity.size();//minimum of 50 passengers and maximum of 600 in every existing plane

        auto pair = mapTypeToCapacity[o];

        std::string pType = pair.first;
        int capacity = pair.second;

        int sizeFp = rand() % 90;
        list<int> flightPlan;
        for (int i=0; i < sizeFp; i++) {
            int fnumber = rand() % (nFlights--);
            if(!v.empty()) {
                flightPlan.push_back(v[fnumber]);
                v.erase(v.begin() + fnumber);
            }
            if(!nFlights)
                break;
        }
        Plane p1(plate, pType, capacity,flightPlan);
        ofP << p1;
    }
    ofP.close();
ASSERT_EQ(v.size(), 0);
}*/
/*
TEST(Creator_test, Services) {
    vector<std::string> v{
            "CS-AKJ",
            "CS-HLH",
            "CS-JYZ",
            "CS-KRJ",
            "CS-OZA",
            "CS-PBO",
            "CS-SPM",
            "CS-TSZ"
    };


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

    std::vector<std::string > names;

    for(int i = 0; i < 20; i++) {
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
        names.push_back(name);
    }
    ofstream ofs("../Files/Services/services.txt");

    ofs << 15 << std::endl;

vector<Service> m2;
    for(int i = 0; i < 15; i++) {
        int n = rand() %names.size();
        vector<char> c {'c', 'm', 'o'};
        int z = rand() % 3; // nomes próprios
        Date d;

        int er = rand() % 100;

        while(er != 0) {d++;er--;}

        int r = rand() % 8;
        Service service(c[z], d, names[n],v[r]);

m2.push_back(service);
}

sort(m2.begin(),m2.end());

for (auto& s: m2) {
ofs << s;
}

    ofs << 30 << std::endl;

    vector<Service> m;

    for(int i = 0; i < 30; i++) { // DONE S
        int n = rand() %names.size();
        vector<char> c {'c', 'm', 'o'};
        int z = rand() % 3; // nomes próprios
        Date d;

        int e = rand() % 100;

        while(e != 0) {d--;e--;}

        int r = rand() % 8;
        Service service(c[z], d, names[n],v[r]);
        m.push_back(service);
    }

    sort(m.begin(),m.end());

    for (auto& s: m) {
        ofs << s;
    }
}
*/

TEST(Creator_test, tickets) {
/*
    vector<Plane> planes;
    vector<Passenger> passengers;
    vector<Flight> flights;
std::ifstream ofsPlanes("../Files/planes.txt");
std::ifstream ofsFlights("../Files/flights.txt");
std::ofstream ofsTickets("../Files/tickets.txt");



Plane p;
Passenger pa;
Flight flight1;

while(ofsPlanes >> p) planes.push_back(p);
while(ofsFlights >> flight1) flights.push_back(flight1);

ofsPlanes.close();
ofsFlights.close();


vector<char> ve {'x','e'};


for(auto& f : flights) {

    vector<Ticket> ticketsOfflight;
for(int i = 0; i < f.getOccupation(); i++) {
    unsigned int p = rand() & 1000;
    float r3 = 50.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(500.0f-50.0f)));
    int ba = (bool)(rand() % 2);
    bool b = ba == 0;
    char t = ve[rand()&2];
    ClassType C = t == 'x' ? executive:economic;


    ticketsOfflight.emplace_back(f.getNumber(),p,r3,b,C);

}

    for(auto& t: ticketsOfflight) {
        ofsTickets << t;
    }

    }
*/
}

TEST(Test_TimeTable, generateTimetable){
    srand(time(NULL));

    Manager manager;
    BST<Transport>  *tree = manager.getTransportTree();


    auto generateRandomTimeTable = [=](){
        Time t;
        set<Time> s;

        int numTimes = rand()%10+5;

        for(int i = 0; i<numTimes;i++){
            t.setRandomTime();
            s.insert(t);
        }
        return s;
    };


   for(auto it = tree->begin();it!=tree->end();it++){
       set<Time> times = generateRandomTimeTable();


       cout<<(*it).getType()<<" "<<(*it).getDistance()<<" "<<times.size()<<" "<<times<<endl;

    }

   //tree->printTree();

}


TEST(Test_TicketBaggage, Test_TicketBaggage){

/*
    string tickets_path = "../Files/tickets.txt";
    fstream ifs(tickets_path);

    flightNumber flightNumber1;
    unsigned int pId;
    float price;
    int cType;
    Baggage baggage;

    Ticket t;

    multiset<Ticket> ms;

    srand(time(NULL));
    std::ifstream ifs_ticket(tickets_path);


    Ticket ticket;
    while (ifs_ticket >> ticket) {
        Baggage bag(rand()%10+5,rand()%3+1);
        ticket.setBaggage(bag);
        ms.insert(ticket);
    }


    for(auto t:ms){
        cout<<t<<endl;
    }

    for (auto & t: ms) {
        ifs << t;
    }

    ifs_ticket.close();

/*
    std::ofstream ofsTickets(tickets_path);

    for (auto & t: ms) {
        ifs << t;
    }*/



/*  0 0 101 469.18 0
    0 0 101 132.92 0
    0 0 101 344.24 0
    0 0 101 469.24 0*/


    Manager manager;

    multiset<Ticket> * t = manager.getTickets();

    ASSERT_EQ(t->begin()->getBaggage().getWeight(),5);
    ASSERT_EQ(t->begin()->getBaggage().getQuantity(),1);

}

TEST(Test_PassengerBirth, Test_PassengerBirth){

    /*
    srand(time(NULL));

    string passengersPath = "../Files/passengers.txt";

    fstream fs(passengersPath);

    Passenger aux;

    vector<Passenger> v;

    while(fs>>aux){

        int RandDay = rand()%27+1;
        int RandMonth = rand()%12+1;
        int RandYear = rand()%65+1940;
        Date RandDate(RandYear,RandMonth,RandDay);

        aux.setBirth(RandDate);

        v.push_back(aux);
    }

    cout<<endl;
    for(auto i:v) cout<<i;


    ofstream ofs(passengersPath);

    for(auto i:v)
        ofs<<i;
*/

    Manager manager;

    //cout<<manager.passengers[123].getName()<<endl;
    //cout<<manager.passengers[123].getID()<<endl;
    //cout<<manager.passengers[123].getBirthDate()<<endl;

}