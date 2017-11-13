//
// Created by Beatriz Mendes on 16/10/2017.
//
#include "Beach.h"
#include <cmath>
#include <string>

//Beach
Beach::Beach(string county,string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, vector<string> &basicServices):
county(county),name(name), blueflag(blueflag), max_capacity(max_capacity), LAT(LAT), LONG(LONG)
{
    this->basicServices=basicServices;
}

Beach::Beach(){}

bool Beach::get_blue_flag(){return blueflag;}

bool Beach::get_lifeguard(){return lifeguard;}

unsigned int Beach::get_max_capacity(){return max_capacity;}

float Beach::get_Latitude(){return LAT;}

float Beach::get_Longitude(){return LONG;}

vector<Services> Beach::getExtraServices(){return extraServices;}

float Beach::distanceToBeach(float LAT, float LONG){
    float dLONG, dLAT, a, c, distance, earthRadius;
    earthRadius=6373;

    dLONG = this->LONG-LONG;
    dLAT= this->LAT - LAT;
    a= pow(sin(dLAT/2),2) + cos(LAT) * cos(this->LAT) * sin(dLONG/2);
    c= 2 * atan2(sqrt(a),sqrt(1-a));
    distance= c * 6373;

    return distance;
}

//River Beach
RiverBeach::RiverBeach(string county, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG,  float width, float maxDepth, vector<string> &basicServices)
        :Beach(county, name, blueflag, lifeguard, max_capacity,  LAT ,  LONG, basicServices) {
    this->width=width;
    this->maxDepth=maxDepth;
}

RiverBeach::RiverBeach(string beach) 
:Beach()
{
    unsigned int stop = beach.find_first_of(';');
    this->county = beach.substr(0,stop);

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->name = beach.substr(0,stop);

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    if(stoi(beach.substr(0,stop))){

        this->blueflag=true;

    }else
        this->blueflag=false;

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    if(stoi(beach.substr(0,stop))){

        this->lifeguard=true;

    }else
        this->lifeguard=false;


    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->max_capacity = stoul(beach.substr(0,stop));

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->LAT = stof(beach.substr(0,stop));

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->LONG = stof(beach.substr(0,stop));

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->width = stof(beach.substr(0,stop));

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->maxDepth = stof(beach.substr(0,stop));

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->LONG = stof(beach.substr(0,stop));

    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    unsigned int last = beach.find_first_of(';',stop);
    string bservices = beach.substr(stop,last);
    while(stop!=string::npos){
        this->basicServices.push_back(bservices.substr(0,stop));
        beach = bservices.substr(stop+2);
        stop = bservices.find_first_of(',');
    }
    stop = last;
    beach = beach.substr(stop+2);
    

}

//Bayou Beach
BayouBeach::BayouBeach(string county,string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, float aquaticArea, vector<string> &basicServices)
        :Beach(county,name, blueflag, lifeguard, max_capacity,  LAT ,  LONG, basicServices){
    this->aquaticArea=aquaticArea;
}