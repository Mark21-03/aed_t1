#include <iostream>
#include <set>
#include "BST.h"
#include "Time.h"

using namespace std;


typedef std::set<Time> TimeTable;

/**
 * Represents a type of transport that a airport has.
 * It has information about the timeTable of the transport as well as the distance to the airport.
 */
class Transport {
private:
    /**
     * The type of the transport.
     */
    char type;
    /**
     * The Time table of the transports.
     */
    TimeTable timetable;
    /**
     * The distance to the airport.
     */
    float distance;

public:

    /**
     * Constructs default Transport object as a null
     */
    Transport() {
        this->type = 'N';
        this->distance = -1;
    };

    /**
     * Constructs a new Transport with given type but null distance
     * @param type Defines Transport type ( B - Bus , S- Subway, T - Train)
     */
    inline explicit Transport(char type) {
        this->type = type;
        distance = 0;
    }

    /**
     * Constructs a new Transport with given type and respective distance
     * @param type Defines Transport type ( B - Bus , S- Subway, T - Train)
     * @param distance distance (in Kms) from the airport
     */
    inline Transport(char type, float distance) {
        this->type = type;
        this->distance = distance;
    }

    /**
     * Gives transport char type
     * @return transport char type  ( B - Bus , S- Subway, T - Train)
     */
    inline char getType() const { return this->type; }

    /**
     * Sets transport char type if its one of the following  ( B - Bus , S- Subway, T - Train)
     * @param type transport char type
     * @return boolean if given char type is valid and if it actually set the type
     */
    bool setType(const char &newType);

    /**
     * Gives transport distance to the airport
     * @return distance to the airport (float Kms)
     */
    inline float getDistance() const { return this->distance; }

    /**
     * Sets transport distance to airport to given value
     * @param distance float distance (in Km) from the airport
     */
    inline void setDistance(const float &newDistance) { this->distance = newDistance; }

    /**
     * Sets the Timetable (set<Time>) to given value
     * @param TimeTable given value to be set
     */
    inline void setTimeTable(const TimeTable &TimeTable) { this->timetable = TimeTable; }

    /**
     * Gives current Transport timetable
     * @return Timetable (set<Time>)
     */
    inline const TimeTable &getTimeTable() const { return this->timetable; }
};


inline bool Transport::setType(const char &newType) {
    if (newType == 'S' || newType == 'T' || newType == 'B' || newType == 'N') {
        this->type = newType;
        return true;
    }
    return false;
}


/**
 * Tests if the left-hand transport is smaller. First comparison by alphabetical type,
 * then by smaller distance and finally by timetables using < set operator of STL
 * @param t1 left-hand transport to be compared
 * @param t2 right-hand transport to be compared
 * @return boolean result of the comparison
 */
inline bool operator<(const Transport &t1, const Transport &t2) {
    if (t1.getType() != t2.getType())
        return t1.getType() < t2.getType();
    return t1.getDistance() < t2.getDistance();

}


/**
 * Allows for outputting TimeTable type to given ostream
 * @param os ostream to be used
 * @param t TimeTable type to be outputted
 * @return ostream used (changed)
 */
inline ostream &operator<<(ostream &os, const TimeTable &t) {

    for (auto it: t)
        os << it.getTime() << " ";

    return os;
}

/**
 * Allows for outputting Transport object to given ostream
 * @param os ostream to be used
 * @param t Transport to be outputted
 * @return ostream used (changed)
 */
inline ostream &operator<<(ostream &os, Transport &t) {
    os << t.getType() << " " << t.getDistance() << " " << t.getTimeTable();
    return os;
}


/**
 * Allows for istream to create a Transport with Type and Distance
 * @param is istream that gives the data
 * @param t Transport that receives the data
 * @return istream (changed)
 */
inline istream &operator>>(istream &is, Transport &t) {
    char type;
    float distance;
    unsigned numTimes;
    is >> type >> distance >> numTimes;
    t.setDistance(distance);
    t.setType(type);

    TimeTable times;
    Time aux;
    for (unsigned int i = 0; i < numTimes; i++) {
        is >> aux;
        times.insert(aux);
    }
    t.setTimeTable(times);

    return is;
}

/**
 * Tests if two transports are the same by comparing all their attributes
 * @param t1 left-hand transport to be compared
 * @param t2 right-hand transport to be compared
 * @return boolean result of the comparison
 */
inline bool operator==(const Transport &t1, const Transport &t2) {
    return t1.getDistance() == t2.getDistance() && t1.getType() == t2.getType() &&
           t1.getTimeTable() == t2.getTimeTable();
}

