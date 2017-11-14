

#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H

#include <string>
#include <vector>
#include "Services.h"
using namespace std;

class Beach {
protected:
    string name, county;
    bool blueflag, lifeguard;
    unsigned long max_capacity;
    float LAT, LONG;
    vector<string> basicServices;
    vector<Services> extraServices;

public:
    /**
     * @brief constructor for class Beach
     * @param county
     * @param name
     * @param blueflag
     * @param lifeguard
     * @param max_capacity
     * @param LAT
     * @param Long
     * @param basicServices
     */
    Beach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &Long, vector<string> &basicServices);

    Beach(){}

    /**
     * @return 1 if beach contains blue flag, 0 otherwise
     */
    bool get_blue_flag();

    /**
     * @return 1 if beach contains lifeguard, 0 otherwise
     */
    bool get_lifeguard();

    /**
     * @return maximum capacity
     */
    unsigned long get_max_capacity();

    /**
     * @return Latitude
     */
    float get_Latitude();

    /**
     * @return longitude
     */
    float get_Longitude();

    /**
     * @return vector of Services beach contains
     */
    vector<Services> getExtraServices();

    /**
     * @brief helps identifying from which derived class ths object is
     * @return "BayouBeach" if it's a class BayouBeach object, "RiverBeach" if it's a class RiverBeach object
     */
    virtual string getType() const=0;

    /**
     * @brief calculates distance from location's GPS coordinates to beach's coordinates
     * @param 2nd latitude
     * @param 2nd longitude
     * @return distance
     */
    double distanceToBeach(float LAT,float LONG);

    virtual void displayBeach() = 0;
};


class RiverBeach: public Beach{
    float width, maxDepth;
public:
    /**
     * @brief constructor for class RiverBeach
     * @param county
     * @param name
     * @param blueflag
     * @param lifeguard
     * @param max_capacity
     * @param LAT
     * @param LONG
     * @param width
     * @param maxDepth
     * @param basicServices
     */
    RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG,  float &width, float &maxDepth, vector<string> &basicServices);
    /**
     * @brief helper construtor which recognizes and associates Beach's object's given attributes
     * @param line from txt file representing an object of class beach
     */
    RiverBeach(string beach);
    string getType() const{return "River";}
    void displayBeach();
};


class BayouBeach: public Beach{
    float aquaticArea;
public:
    /**
     * @brief constructor class BayouBeach
     * @param county
     * @param name
     * @param blueflag
     * @param lifeguard
     * @param max_capacity
     * @param LAT
     * @param LONG
     * @param aquaticArea
     * @param basicServices
     */
    BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG, float &aquaticArea, vector<string> &basicServices);
    /**
     * @brief helper construtor which recognizes and associates Beach's object's given attributes
     * @param line from txt file representing an object of class beach
     */
    BayouBeach(string beach);
    string getType() const{return "Bayou";}
    void displayBeach();
};



#endif //AEDA_BEACH_H
