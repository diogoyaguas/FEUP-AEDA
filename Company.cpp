#include "Company.h"
#include "Interfaces.h"
#include <fstream>

Company::Company() {
    string fileBeach = "BeachFile.txt";
    ifstream file;
    string beach, type;
    unsigned long stop;

    //verify file is successfully opened

    file.open(fileBeach);

    if (!file.is_open()) {
        cout << "Error in opening file. Exiting program...";
        exit(1);

    }

    while (getline(file, beach)) {
        stop = beach.find_first_of(';');
        type = beach.substr(0, stop);


        if (type == "river") {

            Beaches.push_back(new RiverBeach(beach.substr(stop + 2)));
        } else if (type == "bayou") {

            Beaches.push_back(new BayouBeach(beach.substr(stop + 2)));
        }
    }
}

unsigned int Company::beachExists(string name){
    for (unsigned int i = 0; i < Beaches.size(); ++i) {

        if (Beaches.at(i)->get_name() == name) {
            return i;
        }
    }
        return -1;
}

void Company::addBeach() {
    string type, county, name, utility;
    bool lifeguard, blueflag;
    unsigned long max_capacity;
    float LAT, LONG, width, maxDepth, aquaticArea;
    vector<string> basicServices;
    int utilities, counter = 0, services;
    string sType, sName, sPriceRange, sStars;


    cout << "Insert type (Bayou or River): ";
    cin >> type;
    cout << endl << "Insert county (eg: Arcos de Valdevez): ";
    cin >> county;
    cout << endl << "Insert name: " << endl;
    cin >> name;
    cout << endl << "Insert 1 if contains blueflag, 0 otherwise: ";
    cin >> blueflag;
    cout << endl << "Insert 1 if contains lifeguard, 0 otherwise: ";
    cin >> lifeguard;
    cout << endl << "Insert maximum capacity (eg: 1000): ";
    cin >> max_capacity;
    cout << endl << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
         << endl;
    cin >> LAT >> LONG;


    if (type == "River") {
        cout << endl << "Insert width in meters (eg: 72): " << endl;
        cin >> width;
        cout << endl << "Insert depth in meters (eg: 12): " << endl;
        cin >> maxDepth;
        Beaches.push_back(new RiverBeach(county, name, blueflag, lifeguard, max_capacity, LAT, LONG, width, maxDepth));
    }

    if (type == "Bayou") {
        cout << endl << "Insert width in meters (eg: 1150500000): " << endl;
        cin >> aquaticArea;
        (new BayouBeach(county, name, blueflag, lifeguard, max_capacity, LAT, LONG, aquaticArea));
    }


    cout << endl << "How many basic utilities does the beach have? (eg: wc, showers...): ";
    cin >> utilities;
    while (counter < utilities) {
        cout << endl << ++counter << "st utility: ";
        cin >> utility;
        Beaches.at(Beaches.size() - 1)->getBasicServices().push_back(utility);

    }

    cout << endl << "How many services does the beach have? (eg, Hotel, Bar): ";
    cin >> services;
    counter = 0;
    while (counter < services) {
        cout << endl << ++counter << "st service: ";
        cout << endl << "Type (eg: Hotel, Bar): ";
        cin >> sType;
        cout << endl << "Name (eg: Tapada Grande): ";
        cin >> sName;
        cout << endl << "Price Range (eg: 1/3): ";
        cin >> sPriceRange;
        cout << endl << "Stars (eg: **): ";
        cin >> sStars;
        Beaches.at(Beaches.size() - 1)->getExtraServices().push_back(Services(sType, sName, sPriceRange, sStars));
    }

    cout << "Beach added successfully!" << string(4,'\n');
}

void Company::alterRBeachInfo(unsigned int option, unsigned int i) {
    string name, county;
    bool blueflag, lifeguard;
    unsigned long max_capacity;
    float LAT, LONG;
    float width, maxDepth;
    vector<string> basicServices;
    vector<Services> extraServices;

    switch (option) {
        case 1:
            cout << "Insert new name: " << endl;
            cin >> name;
            Beaches.at(i)->set_name(name);
            break;
        case 2:
            Beaches.at(i)->set_blue_flag();
            break;
        case 3:
            Beaches.at(i)->set_lifeguard();
            break;
        case 4:
            cout << "Insert new maximum capacity: " << endl;
            cin >> max_capacity;
            Beaches.at(i)->set_max_capacity(max_capacity);
            break;
        case 5:
            cout << "Insert new width: " << endl;
            cin >> width;
            Beaches.at(i)->set_width(width);
            break;
        case 6:
            cout << "Insert new depth area: " << endl;
            cin >> maxDepth;
            Beaches.at(i)->set_maxDepth(maxDepth);
            break;
        case 7:
            cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
                 << endl;
            cin >> LAT >> LONG;
            Beaches.at(i)->set_Latitude(LAT);
            Beaches.at(i)->set_Longitude(LONG);
            break;
        case 8:
            break;
    }

}

void Company::alterBBeachInfo(unsigned int option, unsigned int i) {
    string name, county;
    bool blueflag, lifeguard;
    unsigned long max_capacity;
    float LAT, LONG;
    float aquaticArea;
    vector<string> basicServices;
    vector<Services> extraServices;

    switch (option) {
        case 1:
            cout << "Insert new name: " << endl;
            cin >> name;
            Beaches.at(i)->set_name(name);
            break;
        case 2:
            Beaches.at(i)->set_blue_flag();
            break;
        case 3:
            Beaches.at(i)->set_lifeguard();
            break;
        case 4:
            cout << "Insert new maximum capacity: " << endl;
            cin >> max_capacity;
            Beaches.at(i)->set_max_capacity(max_capacity);
            break;
        case 5:
            cout << "Insert new width: " << endl;
            cin >> aquaticArea;
            Beaches.at(i)->set_width(aquaticArea);
            break;
        case 6:
            cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
                 << endl;
            cin >> LAT >> LONG;
            Beaches.at(i)->set_Latitude(LAT);
            Beaches.at(i)->set_Longitude(LONG);
            break;
        case 7:
            break;
    }

}

void Company::removeBeach() {
    string name;
    bool removed = false;

    cout << "Insert beach name: ";
    cin >> name;

    for (int i = 0; i < Beaches.size(); ++i) {

        if (Beaches.at(i)->get_name() == name) {

            Beaches.erase(Beaches.begin()+i);
            cout << endl<< name<< " beach erased successfully!" << string(4,'\n');
            removed = true;
        }
    }

    if(!removed){
        cout <<endl << "ERROR: There is no beach with the given name!" << string(4,'\n');
    }
}

