

#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H

#include <string>
#include <vector>
#include "Services.h"
using namespace std;

class Beach {
protected:
    string name, district;
    bool blueflag, lifeguard;
    unsigned int max_capacity;
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
    Beach(string county, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float Long, vector<string> &basicServices);
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
    unsigned int get_max_capacity();
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
    virtual string getType() const=0;
    /**
     * @brief calculates distance from location's GPS coordinates to beach's coordinates
     * @param 2nd latitude
     * @param 2nd longitude
     * @return distance
     */
    float distanceToBeach(float LAT,float LONG);
};


class RiverBeach: public Beach{
    float width, maxDepth;
public:
    RiverBeach(string county, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, float width, float maxDepth , vector<string> &basicServices);
    string getType() const{return "RB";}
};


class BayouBeach: public Beach{
    float aquaticArea;
public:
    string getType() const{return "BB";}
    BayouBeach(string county,string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, float aquaticArea, vector<string> &basicServices);
};



#endif //AEDA_BEACH_H
