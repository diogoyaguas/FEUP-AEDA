#include "Beach.h"
#include <cmath>
#include <iomanip>
#include <string>

//Beach
Beach::Beach(string &county,string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG):
county(county),name(name), blueflag(blueflag), max_capacity(max_capacity), LAT(LAT), LONG(LONG)
{
}

string Beach::get_name(){ return name;}

bool Beach::get_blue_flag(){return blueflag;}

bool Beach::get_lifeguard(){return lifeguard;}

unsigned long Beach::get_max_capacity(){return max_capacity;}

float Beach::get_Latitude(){return LAT;}

float Beach::get_Longitude(){return LONG;}

vector<string> Beach::getBasicServices(){return basicServices;}

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
RiverBeach::RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG,  float &width, float &maxDepth)
        :Beach(county, name, blueflag, lifeguard, max_capacity,  LAT ,  LONG) {
    this->width=width;
    this->maxDepth=maxDepth;
}

RiverBeach::RiverBeach(string beach)
:Beach()
{
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found
    string basic_services; //temporary string only containing information relevant to attribute basic services
    string extra_services; //temporary string only containing information relevant to attribute basic services

    //attribute county
    stop= beach.find_first_of(';');
    this->county = beach.substr(0,stop);

    //attribute name
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
    beach = beach.substr(stop+1);
    last = beach.find_first_of(';',stop);
    basic_services = beach.substr(stop-1,last-1);
    unsigned long st;

    while(stop!=string::npos && !basic_services.empty()){
        st = basic_services.find_first_of(',');
        this->basicServices.push_back(basic_services.substr(0,st));
        basic_services = basic_services.substr(st+2);
        stop = st;
    }

    //attribute extra services
    stop = beach.find_first_of('(')+1;
    last = beach.find_first_of(')')-1;
    extra_services = beach.substr(stop,last-stop);
    string tempService;
    st = extra_services.find_first_of(';');
    if(extra_services.empty()){
        extraServices.emplace_back(Services());
    }

    while(st != string::npos){
        tempService = extra_services.substr(0,st);
        extraServices.emplace_back(Services(tempService));
        extra_services=extra_services.substr(st+2);
        st = extra_services.find_first_of(';');

        if(st == string::npos){
            tempService = extra_services.substr(0,st);
            extraServices.emplace_back(Services(tempService));
        }
   }
}

void RiverBeach::displayBeach(){

    cout << "County: " << county << endl;
    cout << "GPS coordinates: " << LAT << " | " << LONG << endl;
    cout << "Name: " << getType() << " Beach " << name << endl;
    cout << "Maximum Capacity: " << max_capacity << endl;
    cout << "Width: " << width << endl;
    cout << "Maximum Depth:" << maxDepth << endl;

    unsigned int size;

    if(blueflag && lifeguard){

        cout << "Useful information: " <<  "Blue Flag" << endl << setw(30) << setfill(' ') << "Lifeguard" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++){

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }else if(blueflag && !lifeguard){
        cout << "Useful information: " <<  "Blue Flag" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++){

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }else if(!blueflag && !lifeguard){
        cout << "Useful information: " << "Lifeguard" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }
    else{
        cout << "Useful information: " << basicServices.at(0) << endl;
        for (unsigned int i = 1; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }

    cout << endl << "Services: " << endl;
    for(unsigned int i = 0; i < extraServices.size(); i++){
        cout << setw(15) << setfill(' ') << "Type: " << extraServices.at(i).getType() << endl;
        cout << setw(15) << setfill(' ') << "Name: " << extraServices.at(i).getName() << endl;
        cout << setw(22) << setfill(' ') << "Price Range: " << extraServices.at(i).getPriceRange() << endl;
        cout << setw(16) << setfill(' ') << "Stars: " << extraServices.at(i).getStars() << endl << endl;
    }
}

//Bayou Beach
BayouBeach::BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &LAT , float &LONG, float &aquaticArea)
        :Beach(county,name, blueflag, lifeguard, max_capacity,  LAT ,  LONG){
    this->aquaticArea=aquaticArea;
}

BayouBeach::BayouBeach(string beach)
:Beach()
{
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found
    string basic_services; //temporary string only containing information relevant to attribute basic services
    string extra_services; //temporary string only containing information relevant to attribute basic services

    //attribute county
    stop= beach.find_first_of(';');
    this->county = beach.substr(0,stop);

    //attribute name
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
    this->aquaticArea = stof(beach.substr(0,stop));

    //attribute basic serves
    beach = beach.substr(stop+2);
    last = beach.find(';');
    basic_services = beach.substr(0,last);
    unsigned long st;

    while(!basic_services.empty()){
        st = basic_services.find_first_of(',');
        this->basicServices.push_back(basic_services.substr(0,st));
        if(st==string::npos)
            break;
        basic_services = basic_services.substr(st+2);
        stop = st;
    }

    //attribute extra services
    stop = beach.find_first_of('(')+1;
    last = beach.find_first_of(')')-1;
    extra_services = beach.substr(stop,last-stop);
    string tempService;
    st = extra_services.find_first_of(';');
    if(extra_services.empty()){
        extraServices.emplace_back(Services());
    }

    if(st == string::npos){
        tempService = extra_services.substr(0,st);
        extraServices.emplace_back(Services(tempService));
    }

    while(st != string::npos){
        tempService = extra_services.substr(0,st);
        extraServices.emplace_back(Services(tempService));
        extra_services=extra_services.substr(st+2);
        st = extra_services.find_first_of(';');

        if(st == string::npos){
            tempService = extra_services.substr(0,st);
            extraServices.emplace_back(Services(tempService));
        }
    }
}


void BayouBeach::displayBeach() {

    cout << "County: " << county << endl;
    cout << "GPS coordinates: " << LAT << " | " << LONG << endl;
    cout << "Name: " << getType() << " Beach " << name << endl;
    cout << "Maximum Capacity: " << max_capacity << endl;
    cout << "Aquatic Area: " << aquaticArea << endl;

    unsigned int size;

    if(blueflag && lifeguard){

        cout << "Useful information: " <<  "Blue Flag" << endl << setw(30) << setfill(' ') << "Lifeguard" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++){

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }else if(blueflag && !lifeguard){
        cout << "Useful information: " <<  "Blue Flag" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++){

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }else if(!blueflag && !lifeguard){
        cout << "Useful information: " << "Lifeguard" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }
    else{
        cout << "Useful information: " << basicServices.at(0) << endl;
        for (unsigned int i = 1; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20+size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }

    cout << endl << "Services: " << endl;
    for(unsigned int i = 0; i < extraServices.size(); i++){
        cout << setw(15) << setfill(' ') << "Type: " << extraServices.at(i).getType() << endl;
        cout << setw(15) << setfill(' ') << "Name: " << extraServices.at(i).getName() << endl;
        cout << setw(22) << setfill(' ') << "Price Range: " << extraServices.at(i).getPriceRange() << endl;
        cout << setw(16) << setfill(' ') << "Stars: " << extraServices.at(i).getStars() << endl << endl;
    }
}