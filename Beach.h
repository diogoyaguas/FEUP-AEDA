//
// Created by Beatriz Mendes on 16/10/2017.
//

#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H

#include <string>
using namespace std;

class Beach {
protected:
    string name;
    bool blueflag, lifeguard;
    unsigned int max_capacity;
    float LAT, LONG;

public:
    Beach(){}
    Beach(string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float Long);
    bool get_blue_flag();
    bool get_lifeguard();
    unsigned int get_max_capacity();
    float get_Latitude();
    float get_Longitude();
    virtual string getType() const=0;
};


class RiverBeach: public Beach{

public:
    RiverBeach(string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG);
    string getType() const{return "RB";}
};


class BayouBeach: public Beach{

public:
    string getType() const{return "BB";}
    BayouBeach(string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG);
};



#endif //AEDA_BEACH_H
