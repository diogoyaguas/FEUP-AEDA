//
// Created by Beatriz Mendes on 16/10/2017.
//



#include "Beach.h"

//Beach
Beach::Beach(string district,string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, vector<string> &basicServices):
district(district),name(name), blueflag(blueflag), max_capacity(max_capacity), LAT(LAT), LONG(LONG)
{
    this->basicServices=basicServices;
}

bool Beach::get_blue_flag(){return blueflag;}

bool Beach::get_lifeguard(){return lifeguard;}

unsigned int Beach::get_max_capacity(){return max_capacity;}

float Beach::get_Latitude(){return LAT;}

float Beach::get_Longitude(){return LONG;}



//River Beach
RiverBeach::RiverBeach(string district, string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG,  float width, float maxDepth, vector<string> &basicServices)
        :Beach(district, name, blueflag, lifeguard, max_capacity,  LAT ,  LONG, basicServices) {
    this->width=width;
    this->maxDepth=maxDepth;
}


//Bayou Beach
BayouBeach::BayouBeach(string district,string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG, float aquaticArea, vector<string> &basicServices)
        :Beach(district,name, blueflag, lifeguard, max_capacity,  LAT ,  LONG, basicServices){
    this->aquaticArea=aquaticArea;
}