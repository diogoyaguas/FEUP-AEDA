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


        if (type == "rio") {

            Beaches.push_back(new RiverBeach(beach.substr(stop + 2)));
        } else if (type == "albufeira") {

            Beaches.push_back(new BayouBeach(beach.substr(stop + 2)));
        }
    }
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
    while (counter < utilities) {
        cout << endl << counter++ << "st utility: ";
        cin >> utility;
        Beaches.at(Beaches.size() - 1)->getBasicServices().push_back(utility);
        counter++;

    }

    cout << endl << "How many services does the beach have? (eg, Hotel, Bar): ";
    cin >> services;
    counter = 0;
    while (counter < services) {
        cout << endl << counter++ << "st service: ";
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
}

void Company::alterBeachInfo() {

    int option;
    string name;
    unsigned long maxCap;
    float maxDepth, width, LAT, LONG, aquaticArea;

    cout << "Insert beach name" << endl;
    cin >> name;

    for (unsigned int i = 0; i < Beaches.size(); ++i) {

        if (Beaches.at(i)->get_name() == name) {

            if (Beaches.at(i)->get_Type() == "River") {
                cout << "What do you want to change?" << endl;
                cout << "1. Change name" << endl;
                cout << "2. Change if have Blue Flag" << endl;
                cout << "3. Change if have Lifeguard" << endl;
                cout << "4. Change maximum capacity" << endl;
                cout << "5. Change width" << endl;
                cout << "6. Change maximum depth" << endl;
                cout << "7. Change GPS coordinates" << endl;
                cout << "8. Change services" << endl;
                cout << endl << "Enter a number option: ";
                cin >> option;

                //verifies if input is valid
                while (cin.fail() || !ValidInput(1, 8, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: ";
                    cin >> option;
                }

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
                        cin >> maxCap;
                        Beaches.at(i)->set_max_capacity(maxCap);
                        break;
                    case 5:
                        cout << "Insert new width: " << endl;
                        cin >> width;
                        Beaches.at(i)->set_width(width);
                        break;
                    case 6:
                        cout << "Insert new maximum depth: " << endl;
                        cin >> maxDepth;
                        Beaches.at(i)->set_maxDepth(maxDepth);
                        break;
                    case 7:
                        cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): " << endl;
                        cin >> LAT >> LONG;
                        Beaches.at(i)->set_Latitude(LAT);
                        Beaches.at(i)->set_Longitude(LONG);
                        break;
                    case 8:
                        break;
                }
            }


            if (Beaches.at(i)->get_Type() == "Bayou") {
                cout << "What do you want to change?" << endl;
                cout << "1. Change name" << endl;
                cout << "2. Change if have blue flag" << endl;
                cout << "3. Change if have lifeguard" << endl;
                cout << "4. Change maximum capacity" << endl;
                cout << "5. Change aquatic area" << endl;
                cout << "6. Change GPS coordinates" << endl;
                cout << "7. Change services" << endl;
                cout << endl << "Enter a number option: ";
                cin >> option;

                //verifies if input is valid
                while (cin.fail() || !ValidInput(1, 7, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: ";
                    cin >> option;

                }

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
                        cin >> maxCap;
                        Beaches.at(i)->set_max_capacity(maxCap);
                        break;
                    case 5:
                        cout << "Insert new aquatic area: " << endl;
                        cin >> aquaticArea;
                        Beaches.at(i)->set_aquaticArea(aquaticArea);
                        break;
                    case 6:
                        cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): " << endl;
                        cin >> LAT >> LONG;
                        Beaches.at(i)->set_Latitude(LAT);
                        Beaches.at(i)->set_Longitude(LONG);
                        break;
                    case 7:
                        break;
                }
            }
        }
    }


}

void Company::removeBeach() {
    string name;

    cout << "Insert beach name: ";
    cin >> name;

    for (int i = 0; i < Beaches.size(); ++i) {

        if (Beaches.at(i)->get_name() == name) {

            Beaches.erase(Beaches.begin() + Beaches.size());
            cout << "Beach " << name << " erased" << endl;

        } else if (i == Beaches.size() - 1 && Beaches.at(i)->get_name() != name) {

            cout << "There is no beach with the given name.";

        }
    }


}

