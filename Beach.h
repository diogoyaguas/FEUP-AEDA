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
    float lat, longi;
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
     * @param lat
     * @param longi
     * @param basicServices
     */
    Beach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi);

    Beach(){};

    // get methods
    string get_name();
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
     * @return latitude
     */
    float get_latitude();

    /**
     * @return longitude
     */
    float get_longitude();

    vector<string> getBasicServices();

    /**
     * @return vector of Services beach contains
     */
    vector<Services> getExtraServices();

    /**
     * @brief helps identifying from which derived class ths object is
     * @return "BayouBeach" if it's a class BayouBeach object, "RiverBeach" if it's a class RiverBeach object
     */
    virtual string getType() const=0;


    // set methods
    /**
     * @brief changes name
     * @param name
     */
    void set_name(string name);

    /**
     * @brief changes blueflag
     */
    void set_blue_flag();

    /**
     * @brief changes lifeguard
     */
    void set_lifeguard();

    /**
     * @brief changes maximum capacity
     * @param maximum capacity
     */
    void set_max_capacity(unsigned long max_capacity);

    /**
     * @brief changes latitude
     * @param latitude
     */
    void set_latitude(float lat);

    /**
     * @brief changes longitude
     * @param longitude
     */
    void set_longitude(float longi);

    /**
     * @brief changes basic services
     * @param basicServices
     */
    void set_BasicServices(vector<string> basicServices);


    void add_BasicService(string service);
    void add_ExtraService(Services service);

    /**
     * @brief changes extra services
     * @param extraServices
     */
    void set_ExtraServices(vector<Services> extraServices);

    /**
     * @brief changes width
     * @param width
     */
    virtual void set_width(float width) = 0;

    /**
     * @brief changes maximum depth
     * @param maximum depth
     */
    virtual void set_maxDepth(float maxDept) = 0;

    /**
     * @brief changes aquatic area
     * @param Aquatic area
     */
    virtual void set_aquaticArea(float aquaticArea) = 0;


    // other functions
    /**
     * @brief calculates distance from location's GPS coordinates to beach's coordinates
     * @param 2nd latitude
     * @param 2nd longitude
     * @return distance
     */
    double distanceToBeach(float lat,float longi);

    /**
     * @brief displays all information about the beach
     */
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
     * @param lat
     * @param longi
     * @param width
     * @param maxDepth
     * @param basicServices
     */
    RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi,  float &width, float &maxDepth);
    /**
     * @brief helper construtor which recognizes and associates Beach's object's given attributes
     * @param line from txt file representing an object of class beach
     */
    RiverBeach(string beach);
    string getType() const{return "River";}
    void set_width(float width){ this->width = width;};
    void set_maxDepth(float maxDept) { this->maxDepth = maxDept;};
    void set_aquaticArea(float aquaticArea){};
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
     * @param lat
     * @param longi
     * @param aquaticArea
     * @param basicServices
     */
    BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi, float &aquaticArea);
    /**
     * @brief helper construtor which recognizes and associates Beach's object's given attributes
     * @param line from txt file representing an object of class beach
     */
    BayouBeach(string beach);
    string getType() const{return "Bayou";}
    void set_width(float width){};
    void set_maxDepth(float maxDept) {};
    void set_aquaticArea(float aquaticArea){this->aquaticArea = aquaticArea;};
    void displayBeach();
};

#endif //AEDA_BEACH_H
