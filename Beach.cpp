//
// Created by Beatriz Mendes on 16/10/2017.
//
#include "Beach.h"
#include <cmath>
#include <string>

//Beach
Beach::Beach(string &county,string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG, vector<string> &basicServices):
county(county),name(name), blueflag(blueflag), max_capacity(max_capacity), LAT(LAT), LONG(LONG)
{
    this->basicServices=basicServices;
}


bool Beach::get_blue_flag(){return blueflag;}

bool Beach::get_lifeguard(){return lifeguard;}

unsigned long Beach::get_max_capacity(){return max_capacity;}

float Beach::get_Latitude(){return LAT;}

float Beach::get_Longitude(){return LONG;}

vector<Services> Beach::getExtraServices(){return extraServices;}

double Beach::distanceToBeach(float LAT, float LONG){
    double dLONG, dLAT, a, c, distance, earthRadius;
    earthRadius=6373;

    dLONG = this->LONG-LONG;
    dLAT= this->LAT - LAT;
    a= pow(sin(dLAT/2),2) + cos(LAT) * cos(this->LAT) * sin(dLONG/2);
    c= 2 * atan2(sqrt(a),sqrt(1-a));
    distance= c * 6373;

    return distance;
}

//River Beach
RiverBeach::RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG,  float &width, float &maxDepth, vector<string> &basicServices)
        :Beach(county, name, blueflag, lifeguard, max_capacity,  LAT ,  LONG, basicServices) {
    this->width=width;
    this->maxDepth=maxDepth;
}

RiverBeach::RiverBeach(string beach)
:Beach()
{
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found

    //attribute county
    stop= beach.find_first_of(';');
    this->county = beach.substr(0,stop);

    //name
    beach = beach.substr(stop+2); // +2 marks the begining of the char after space
    stop = beach.find_first_of(';');
    this->name = beach.substr(0,stop);

    //attribute blueflag
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    if(stoi(beach.substr(0,stop))){

        this->blueflag=true;

    }else
        this->blueflag=false;

    // attribute lifeguard
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    if(stoi(beach.substr(0,stop))){

        this->lifeguard=true;

    }else
        this->lifeguard=false;

    //attribute maximum capacity
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->max_capacity = stoul(beach.substr(0,stop));

    //attribute Latitude
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->LAT = stof(beach.substr(0,stop));

    //attribute Longitude
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->LONG = stof(beach.substr(0,stop));

    //attribute width
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->width = stof(beach.substr(0,stop));

    //attribute maximum depth
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->maxDepth = stof(beach.substr(0,stop));

    //attribute basic serves
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    last = beach.find_first_of(';',stop);
    string bservices = beach.substr(stop,last);

    while(stop!=string::npos && bservices.empty()){
        this->basicServices.push_back(bservices.substr(0,stop));
        beach = bservices.substr(stop+2);
        stop = bservices.find_first_of(',');
    }

    //attribute extra services
    stop = last+3; //+3 marks begining of information after space and parenthisis
    beach = beach.substr(stop+3,beach.size()-2); //size-2 represents the position of the last relevant char whithou the parenthisis



}

//Bayou Beach
BayouBeach::BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG, float &aquaticArea, vector<string> &basicServices)
        :Beach(county,name, blueflag, lifeguard, max_capacity,  LAT ,  LONG, basicServices){
    this->aquaticArea=aquaticArea;
}

