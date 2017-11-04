

#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H

#include <string>
using namespace std;

class Beach {
protected:
    string name, district;
    bool blueflag, lifeguard;
    unsigned int max_capacity;
    float LAT, LONG;

public:
    Beach(){}
    Beach(string district, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float Long);
    bool get_blue_flag();
    bool get_lifeguard();
    unsigned int get_max_capacity();
    float get_Latitude();
    float get_Longitude();
    virtual string getType() const=0;
};


class RiverBeach: public Beach{
    float width, maxDepth;
public:
    RiverBeach(string district, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, float width, float maxDepth);
    string getType() const{return "RB";}
};


class BayouBeach: public Beach{
    float aquaticArea;
public:
    string getType() const{return "BB";}
    BayouBeach(string district,string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, float aquaticArea);
};



#endif //AEDA_BEACH_H
