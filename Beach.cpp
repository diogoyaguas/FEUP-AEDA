#include "Beach.h"
#include <iomanip>
#include <vector>
#include <fstream>
#include "UsefulFunctions.h"

//Beach

Beach::Beach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat,
             float &longi) :
        county(county), name(name), blueflag(blueflag), max_capacity(max_capacity), lat(lat), longi(longi) {
}

// get methods
string Beach::get_county() const { return county; }

string Beach::get_name() const { return name; }

bool Beach::get_blue_flag() const { return blueflag; }

bool Beach::get_lifeguard() const { return lifeguard; }

unsigned long Beach::get_max_capacity() const { return max_capacity; }

float Beach::get_latitude() const { return lat; }

float Beach::get_longitude() const { return longi; }

vector<string> Beach::getBasicServices() const { return basicServices; }

vector<priority_queue<Services>> Beach::getExtraServices() const { return extraServices; }

HashTable_services Beach::getServicesDown() const { return ServicesDown;}


// set methods
void Beach::set_name(string name) { this->name = name; }

void Beach::set_blue_flag() {
    if (this->blueflag) {
        this->blueflag = false;
    } else this->blueflag = true;
}

void Beach::set_lifeguard() {
    if (this->lifeguard) {
        this->lifeguard = false;
    } else this->lifeguard = true;
}

void Beach::set_max_capacity(unsigned long max_capacity) { this->max_capacity = max_capacity; }

void Beach::set_latitude(float lat) { this->lat = lat; }

void Beach::set_longitude(float longi) { this->longi = longi; }

//operator overloads
bool Beach::operator==(const Beach &b1) const {
    if (this->county == b1.get_county() && this->name == b1.get_name())
        return true;
    else return false;
}

bool Beach::operator<(const Beach &b1) const {
    if (this->county != b1.get_county())
        return this->county < b1.get_county();
    else return this->blueflag > b1.get_blue_flag();
}


//other methods

void Beach::displayBeachExtraInfo() {
    unsigned int size;

    if (blueflag && lifeguard) {

        cout << "Useful information: " << "Blue Flag" << endl << setw(29) << setfill(' ') << "Lifeguard" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20 + size) << setfill(' ') << basicServices.at(i) << endl;
        }
    } else if (blueflag && !lifeguard) {
        cout << "Useful information: " << "Blue Flag" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20 + size) << setfill(' ') << basicServices.at(i) << endl;
        }
    } else if (!blueflag && !lifeguard) {
        cout << "Useful information: " << "Lifeguard" << endl;
        for (unsigned int i = 0; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20 + size) << setfill(' ') << basicServices.at(i) << endl;
        }
    } else {
        cout << "Useful information: " << basicServices.at(0) << endl;
        for (unsigned int i = 1; i < basicServices.size(); i++) {

            size = basicServices.at(i).size();
            cout << setw(20 + size) << setfill(' ') << basicServices.at(i) << endl;
        }
    }

    if (extraServices.empty()) { throw -1; }

    cout << endl << "Services: " << endl;

    int n = 0;

    for (unsigned int i = 0; i < extraServices.size(); ++i) {

        priority_queue<Services> temp = extraServices.at(i);


        while (!temp.empty()) {

            n++;

            Services service = temp.top();
            temp.pop();
            cout << setw(15) << setfill(' ') << "Type: " << service.getType() << endl;
            cout << setw(15) << setfill(' ') << "Name: " << service.getName() << endl;
            cout << setw(22) << setfill(' ') << "Price Range: " << service.getPriceRange() << endl;
            cout << setw(16) << setfill(' ') << "Stars: " << service.getStars() << endl;
            cout << setw(15) << setfill(' ') << "Date: " << service.getDateInspection() << endl << endl;
        }
    }
    if (n == 0) { throw -1; }
}

void Beach::displayBeach() {
    cout << "County: " << county << endl;
    cout << "GPS coordinates: " << lat << " | " << longi << endl;
    cout << "Name: " << getType() << " Beach " << name << endl;
    cout << "Maximum Capacity: " << max_capacity << endl;
}

void Beach::add_BasicService(string service) { this->basicServices.push_back(service); }

void Beach::add_ExtraService(Services service) {

    for (unsigned int i = 0; i < this->extraServices.size(); ++i) {

        if (this->extraServices.at(i).top().getType() == service.getType()) {

            this->extraServices.at(i).push(service);
            return;
        }
    }

    priority_queue<Services> new_q;
    new_q.push(service);
    this->extraServices.push_back(new_q);

}

void Beach::erase_ExtraService(Services service) {

    for (unsigned int i = 0; i < this->extraServices.size(); ++i) {

        if (this->extraServices.at(i).top().getType() == service.getType()) {

            priority_queue<Services> temp;
            Services s_temp;

            while (!this->extraServices.at(i).empty()) {

                s_temp = this->extraServices.at(i).top();
                this->extraServices.at(i).pop();
                if (s_temp.getName() != service.getName()) {

                    temp.push(s_temp);
                }
            }

            while (!temp.empty()) {

                s_temp = temp.top();
                temp.pop();
                this->extraServices.at(i).push(s_temp);
            }
        }
    }


}

void Beach::add_ClosedService(Services service, string date, string type_of_closing) {

    struct_serviceShutDown close;
    close.date = date;
    close.service = service;
    close.type_of_closing = type_of_closing;
    this->ServicesDown.insert(close);
}

void Beach::writeBeachClosedServices(ofstream &file) {
    for (auto it = this->ServicesDown.begin(); it != this->ServicesDown.end() ; it++) {
        file << this->name << "; " << (*it).type_of_closing << "; " << (*it).date << "; ";
        (*it).service.writeService(file);
    }
}

void Beach::readClosedServices(string service){
    Services tmp_service_down;
    struct_serviceShutDown s;
    s.type_of_closing=divideString(';',service);
    s.date = divideString(';',service);
    s.service = Services(service);
}

double Beach::distanceToBeach(float lat, float longi) {
    int earthRadiusKm = 6371;
    double tempLat, tempL1;

    double dLat = degreesToRadians(lat - this->lat);
    double dLon = degreesToRadians(longi - this->longi);

    tempL1 = degreesToRadians(this->lat);
    tempLat = degreesToRadians(lat);

    double a = sin(dLat / 2) * sin(dLat / 2) + sin(dLon / 2) * sin(dLon / 2) * cos(tempL1) * cos(tempLat);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return earthRadiusKm * c;

}



//River Beach
RiverBeach::RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity,
                       float &lat, float &longi, float &width, float &maxDepth)
        : Beach(county, name, blueflag, lifeguard, max_capacity, lat, longi) {
    this->width = width;
    this->maxDepth = maxDepth;
}

RiverBeach::RiverBeach(string beach)
        : Beach() {
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found
    string basic_services; //temporary string only containing information relevant to attribute basic services
    string extra_services; //temporary string only containing information relevant to attribute basic services

    //attribute county
    this->county = divideString(';',beach);

    //attribute name
    this->name =  divideString(';',beach);


    //attribute blueflag
    if (stoi(divideString(';',beach))) {

        this->blueflag = true;

    } else
        this->blueflag = false;

    // attribute lifeguard
    if (stoi(divideString(';',beach))) {

        this->lifeguard = true;

    } else
        this->lifeguard = false;

    //attribute maximum capacity
    this->max_capacity = stoul(divideString(';',beach));

    //attribute latitude
    this->lat = stof(divideString(';',beach));

    //attribute longitude
    this->longi = stof(divideString(';',beach));

    //attribute width
    this->width = stof(divideString(';',beach));

    //attribute maximum depth
    this->maxDepth = stof(divideString(';',beach));

    //attribute basic serves
    basic_services = divideString(';',beach);
    unsigned long st;
    string bs;

    while (!basic_services.empty()) {
        bs = divideString(',',basic_services);

        if (bs == "not_found") {
            this->basicServices.push_back(basic_services);
            break;
        }
        this->basicServices.push_back(bs);
    }

    //attribute extra services
    stop = beach.find_first_of('(') + 1;
    last = beach.find_first_of(')') - 1;
    extra_services = beach.substr(stop, last - stop);
    string tempService;
    st = extra_services.find_first_of(';');
    if (extra_services.empty()) {
        add_ExtraService(Services());
    }

    while (st != string::npos) {
        tempService = extra_services.substr(0, st);
        add_ExtraService(Services(tempService));
        extra_services = extra_services.substr(st + 2);
        st = extra_services.find_first_of(';');

        if (st == string::npos) {
            st = extra_services.size();
            tempService = extra_services.substr(0, st);
            add_ExtraService(Services(tempService));
            st = string::npos;
        }
    }
}

void RiverBeach::writeBeach(ofstream &file) const {

    file << this->getType() << "; ";
    file << this->get_county() << "; ";
    file << this->get_name() << "; ";
    file << this->get_blue_flag() << "; ";
    file << this->get_lifeguard() << "; ";
    file << this->get_max_capacity() << "; ";
    file << this->get_latitude() << "; ";
    file << this->get_longitude() << "; ";

    file << this->get_width() << "; ";
    file << this->get_maxDepth() << "; ";

    if (!this->getBasicServices().empty()) {
        for (auto &bService: this->getBasicServices()) {
            if (bService == this->getBasicServices().at(this->getBasicServices().size() - 1)) {
                file << bService;
                break;
            }
            file << bService << ", ";
        }
    }
    file << "; ";
    file << "(";
    Services service;
    priority_queue<Services> temp;

    for (unsigned int i = 0; i < this->getExtraServices().size(); ++i) {
        temp = this->getExtraServices().at(i);
        if(i != 0) file << " ";

        if (!temp.empty()) {

            service = temp.top();
            temp.pop();
            service.writeService(file);

            while (!temp.empty()) {

                service = temp.top();
                temp.pop();
                file << " " ;
                service.writeService(file);
            }
        }
    }
    file << ")";
    file << endl;
}


void RiverBeach::displayBeach() {

    Beach::displayBeach();

    cout << "Width: " << width << endl;
    cout << "Maximum Depth:" << maxDepth << endl;

    Beach::displayBeachExtraInfo();


}


//Bayou Beach
BayouBeach::BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity,
                       float &lat, float &longi, float &aquaticArea)
        : Beach(county, name, blueflag, lifeguard, max_capacity, lat, longi) {
    this->aquaticArea = aquaticArea;
}

BayouBeach::BayouBeach(string beach)
        : Beach() {
    unsigned long last;
    unsigned long stop; //stop is pos for last ';' found
    string basic_services; //temporary string only containing information relevant to attribute basic services
    string extra_services; //temporary string only containing information relevant to attribute basic services


    //attribute county
    this->county = divideString(';',beach);

    //attribute name
    this->name =  divideString(';',beach);


    //attribute blueflag
    if (stoi(divideString(';',beach))) {

        this->blueflag = true;

    } else
        this->blueflag = false;

    // attribute lifeguard
    if (stoi(divideString(';',beach))) {

        this->lifeguard = true;

    } else
        this->lifeguard = false;

    //attribute maximum capacity
    this->max_capacity = stoul(divideString(';',beach));

    //attribute latitude
    this->lat = stof(divideString(';',beach));

    //attribute longitude
    this->longi = stof(divideString(';',beach));


    //attribute width
    this->aquaticArea = stof(divideString(';',beach));

    //attribute basic serves
    basic_services = divideString(';',beach);
    unsigned long st;
    string bs;

    while (!basic_services.empty()) {
        bs = divideString(',',basic_services);

        if (bs == "not_found") {
            this->basicServices.push_back(basic_services);
            break;
        }
        this->basicServices.push_back(bs);
    }

    //attribute extra services
    stop = beach.find_first_of('(') + 1;
    last = beach.find_first_of(')') - 1;
    extra_services = beach.substr(stop, last - stop);
    string tempService;
    st = extra_services.find_first_of(';');
    if (extra_services.empty()) {
        add_ExtraService(Services());
    }

    while (st != string::npos) {
        tempService = extra_services.substr(0, st);
        add_ExtraService(Services(tempService));
        extra_services = extra_services.substr(st + 2);
        st = extra_services.find_first_of(';');

        if (st == string::npos) {
            st = extra_services.size();
            tempService = extra_services.substr(0, st);
            add_ExtraService(Services(tempService));
            st = string::npos;
        }
    }
}

void BayouBeach::displayBeach() {

    Beach::displayBeach();

    cout << "Aquatic Area: " << aquaticArea << endl;

    Beach::displayBeachExtraInfo();
}

void BayouBeach::writeBeach(ofstream &file) const {

    file << this->getType() << "; ";
    file << this->get_county() << "; ";
    file << this->get_name() << "; ";
    file << this->get_blue_flag() << "; ";
    file << this->get_lifeguard() << "; ";
    file << this->get_max_capacity() << "; ";
    file << this->get_latitude() << "; ";
    file << this->get_longitude() << "; ";

    file << this->get_aquaticArea() << "; ";

    //write basic services
    if (!this->getBasicServices().empty()) {
        for (auto &bService: this->getBasicServices()) {
            if (bService == this->getBasicServices().at(this->getBasicServices().size() - 1)) {
                file << bService;
                break;
            }
            file << bService << ", ";
        }
    }

    //write extra services
    file << "; ";
    file << "(";
    Services service;
    priority_queue<Services> temp;

    for (unsigned int i = 0; i < this->getExtraServices().size(); ++i) {
        temp = this->getExtraServices().at(i);

        if(i != 0) file << " ";

        if (!temp.empty()) {

            service = temp.top();
            temp.pop();
            service.writeService(file);

            while (!temp.empty()) {

                service = temp.top();
                temp.pop();
                file << " " ;
                service.writeService(file);
            }
        }
    }
    file << ")";
    file << endl;
}

