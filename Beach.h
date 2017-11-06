

#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H

#include <string>
#include <vector>
#include "Service.h"
using namespace std;

class Beach {
protected:
    string name, district;
    bool blueflag, lifeguard;
    unsigned int max_capacity;
    float LAT, LONG;
    vector<string> basicServices;

public:
    Beach(string county, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float Long, vector<string> &basicServices);
    bool get_blue_flag();
    bool get_lifeguard();
    unsigned int get_max_capacity();
    float get_Latitude();
    float get_Longitude();
    virtual string getType() const=0;
    vector<Service> extraServices;
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
