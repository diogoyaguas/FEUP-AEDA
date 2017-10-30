//
// Created by Beatriz Mendes on 16/10/2017.
//



#include "Beach.h"

//Beach
Beach::Beach(string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG):
name(name), blueflag(blueflag), max_capacity(max_capacity), LAT(LAT), LONG(LONG)
{}

bool Beach::get_blue_flag(){return blueflag;}

bool Beach::get_lifeguard(){return lifeguard;}

unsigned int Beach::get_max_capacity(){return max_capacity;}

float Beach::get_Latitude(){return LAT;}

float Beach::get_Longitude(){return LONG;}



//River Beach
RiverBeach::RiverBeach(string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG)
        :Beach(name, blueflag, lifeguard, max_capacity,  LAT ,  LONG)
{}


//Bayou Beach
BayouBeach::BayouBeach(string name, bool blueflag, bool lifeguard, unsigned int max_capacity, float LAT , float LONG)
        :Beach(name, blueflag, lifeguard, max_capacity,  LAT ,  LONG){}