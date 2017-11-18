#include "Beach.h"
#include <iomanip>
#include <vector>

//Beach
Beach::Beach(string &county,string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi):
county(county),name(name), blueflag(blueflag), max_capacity(max_capacity), lat(lat), longi(longi)
{
}

// get methods
string Beach::get_county() const {return county;}
string Beach::get_name()const {return name;}
bool Beach::get_blue_flag() const {return blueflag;}
bool Beach::get_lifeguard()const{return lifeguard;}
unsigned long Beach::get_max_capacity()const{return max_capacity;}
float Beach::get_latitude()const{return lat;}
float Beach::get_longitude()const{return longi;}
vector<string> Beach::getBasicServices()const{return basicServices;}
vector<Services> Beach::getExtraServices()const{return extraServices;}

// set methods
void Beach::set_name(string name){this->name = name;}
void Beach::set_blue_flag(){if(this->blueflag){
        this->blueflag = false;
    } else this->blueflag = true;}
void Beach::set_lifeguard(){if(this->lifeguard){
        this->lifeguard = false;
    } else this->lifeguard = true;}
void Beach::set_max_capacity(unsigned long max_capacity){this->max_capacity = max_capacity;}
void Beach::set_latitude(float lat){this->lat = lat;}
void Beach::set_longitude(float longi){this->longi = longi;}
void Beach::set_BasicServices(vector<string> basicServices){this->basicServices = basicServices;}
void Beach::set_ExtraServices(vector<Services> extraServices){this->extraServices = extraServices;}


void Beach::add_BasicService(string service){this->basicServices.push_back(service);}
void Beach::add_ExtraService(Services service){this->extraServices.push_back(service);}
void Beach::erase_ExtraService(string service){

    for(unsigned int i = 0; i < this->extraServices.size(); ++i){

        if(this->extraServices.at(i).getName() == service){

            this->extraServices.erase(this->extraServices.begin()+i);
        }
    }
}
double Beach::distanceToBeach(float lat, float longi) {
    int earthRadiusKm = 6371;
    double tempLat, tempL1;

    double dLat = degreesToRadians(lat - this->lat);
    double dLon = degreesToRadians(longi - this->longi);

    tempL1 = degreesToRadians(this->lat);
    tempLat = degreesToRadians(lat);

    double a = sin(dLat / 2) * sin(dLat / 2) + sin(dLon / 2) * sin(dLon / 2) * cos( tempL1) * cos(tempLat);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return earthRadiusKm * c;

}



//River Beach
RiverBeach::RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi,  float &width, float &maxDepth)
        :Beach(county, name, blueflag, lifeguard, max_capacity,  lat ,  longi) {
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

    //attribute latitude
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->lat = stof(beach.substr(0,stop));

    //attribute longitude
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->longi = stof(beach.substr(0,stop));

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
    last = beach.find(';');
    basic_services = beach.substr(0,last);
    unsigned long st;

    while(stop!=string::npos && !basic_services.empty()){
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
    cout << "GPS coordinates: " << lat << " | " << longi << endl;
    cout << "Name: " << getType() << " Beach " << name << endl;
    cout << "Maximum Capacity: " << max_capacity << endl;
    cout << "Width: " << width << endl;
    cout << "Maximum Depth:" << maxDepth << endl;

    unsigned int size;

    if(blueflag && lifeguard){

        cout << "Useful information: " <<  "Blue Flag" << endl << setw(29) << setfill(' ') << "Lifeguard" << endl;
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
BayouBeach::BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi, float &aquaticArea)
        :Beach(county,name, blueflag, lifeguard, max_capacity,  lat ,  longi){
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

    //attribute latitude
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->lat = stof(beach.substr(0,stop));

    //attribute longitude
    beach = beach.substr(stop+2);
    stop = beach.find_first_of(';');
    this->longi = stof(beach.substr(0,stop));

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
    cout << "GPS coordinates: " << lat << " | " << longi << endl;
    cout << "Name: " << getType() << " Beach " << name << endl;
    cout << "Maximum Capacity: " << max_capacity << endl;
    cout << "Aquatic Area: " << aquaticArea << endl;

    unsigned int size;

    if(blueflag && lifeguard){

        cout << "Useful information: " <<  "Blue Flag" << endl << setw(29) << setfill(' ') << "Lifeguard" << endl;
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

