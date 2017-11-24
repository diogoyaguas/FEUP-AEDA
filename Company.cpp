#include "Company.h"
#include "Interfaces.h"
#include <algorithm>
#include <fstream>

using namespace std;

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


        if (type == "River") {

            beaches.push_back(new RiverBeach(beach.substr(stop + 2)));
        } else if (type == "Bayou") {

            beaches.push_back(new BayouBeach(beach.substr(stop + 2)));
        }
    }
}

int Company::beachExists(string name) {

    for (unsigned int i = 0; i < beaches.size(); ++i) {

        if (beaches.at(i)->get_name() == name) {
            return i;
        }
    }
    return -1;
}

void Company::addBeach() {
    string type, county, name, utility;
    bool lifeguard, blueflag;
    unsigned long max_capacity;
    float lat, longi, width, maxDepth, aquaticArea;
    vector<string> basicServices;
    int utilities, counter = 0, services, temp;
    string sType, sName, sPriceRange, sStars;

    cout << "Insert type (Bayou or River): " << endl << "::: ";
    cin >> type;
    while (type != "River" && type != "Bayou") {

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid type: ";
        cin >> type;
    }

    cout << endl << "Insert county (eg: Arcos de Valdevez): " << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, county);

    cout << endl << "Insert name: " << endl << "::: ";
    getline(cin, name);
    if(beachExists(name) != -1) { throw  -1;}

    cout << endl << "Insert 1 if contains blueflag, 0 otherwise: " << endl << "::: ";
    cin >> temp;
    while (cin.fail() && temp != 0 && temp != 1) {

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid value: ";
        cin >> temp;
    }
    blueflag = temp;


    cout << endl << "Insert 1 if contains lifeguard, 0 otherwise: " << endl << "::: ";
    cin >> temp;
    while (cin.fail() && temp != 0 && temp != 1) {

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid value: ";
        cin >> temp;
    }
    lifeguard = temp;

    cout << endl << "Insert maximum capacity (eg: 1000): " << endl << "::: ";
    cin >> max_capacity;
    fail(max_capacity);

    cout << endl << "Insert latitude and longitude coordinates(eg: 40.268799): " << endl << "::: ";
    cin >> lat;
    fail(lat);

    cout << "::: ";
    cin >> longi;
    fail(longi);

    if (type == "River") {

        cout << endl << "Insert width in meters (eg: 72): " << endl << "::: ";
        cin >> width;
        fail(width);

        cout << endl << "Insert depth in meters (eg: 12): " << endl << "::: ";
        cin >> maxDepth;
        fail(maxDepth);

        beaches.push_back(new RiverBeach(county, name, blueflag, lifeguard, max_capacity, lat, longi, width, maxDepth));
    }

    if (type == "Bayou") {

        cout << endl << "Insert width in meters (eg: 1150500000): " << endl << "::: ";
        cin >> aquaticArea;
        fail(aquaticArea);

        beaches.push_back(new BayouBeach(county, name, blueflag, lifeguard, max_capacity, lat, longi, aquaticArea));
    }

    cout << endl << "How many basic utilities does the beach have? (eg: wc, showers...): " << endl << "::: ";
    cin >> utilities;
    fail(utilities);
    counter = 0;
    cin.ignore(1000, '\n');
    while (counter < utilities) {
        cout << endl << "service" << ++counter << ": ";
        getline(cin, utility);
        beaches.at(beaches.size() - 1)->add_BasicService(utility);
    }

    cout << endl << "How many services does the beach have? (eg, Hotel, Bar): " << endl << "::: ";
    cin >> services;
    fail(services);
    cin.ignore(1000, '\n');
    counter = 0;
    while (counter < services) {
        cout << endl << "Service " << ++counter << ": ";

        cout << endl << "Type (eg: Hotel, Bar): ";
        getline(cin, sType);

        cout << endl << "Name (eg: Tapada Grande): ";
        getline(cin, sName);

        cout << endl << "Price Range (eg: 1/3): ";
        cin >> sPriceRange;
        while (sPriceRange != "1/3" && sPriceRange != "2/3" && sPriceRange != "3/3") {
            cin.ignore(1000, '\n');
            cout << "Please enter a valid value: ";
            cin >> sPriceRange;
        }

        cout << endl << "Stars (eg: **): ";
        cin >> sStars;
        while (sStars != "*" && sStars != "**" && sStars != "***" && sStars != "****" && sStars != "*****") {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid value: ";
            cin >> sStars;
        }

        beaches.at(beaches.size() - 1)->add_ExtraService(Services(sType, sName, sPriceRange, sStars));
        cin.ignore(1000, '\n');
    }
    cout << "Beach added successfully!" << string(4, '\n');
}

void Company::alterRBeachInfo(unsigned int option, unsigned int i) {
    string name, county;
    bool blueflag, lifeguard;
    unsigned long max_capacity;
    float lat, longi;
    float width, maxDepth;
    vector<string> basicServices;
    vector<Services> extraServices;

    switch (option) {
        case 1:
            cout << "Insert new name: " << endl;
            cin.ignore(1000, '\n');
            getline(cin, name);
            if(beachExists(name) != -1) { throw  -1;}
            beaches.at(i)->set_name(name);
            break;
        case 2:
            beaches.at(i)->set_blue_flag();
            break;
        case 3:
            beaches.at(i)->set_lifeguard();
            break;
        case 4:
            cout << "Insert new maximum capacity: " << endl;
            cin >> max_capacity;
            beaches.at(i)->set_max_capacity(max_capacity);
            break;
        case 5:
            cout << "Insert new width: " << endl;
            cin >> width;
            beaches.at(i)->set_width(width);
            break;
        case 6:
            cout << "Insert new depth area: " << endl;
            cin >> maxDepth;
            beaches.at(i)->set_maxDepth(maxDepth);
            break;
        case 7:
            cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
                 << endl;
            cin >> lat >> longi;
            beaches.at(i)->set_latitude(lat);
            beaches.at(i)->set_longitude(longi);
            break;
        case 8:
            break;
    }

}

void Company::alterBBeachInfo(unsigned int option, unsigned int i) {
    string name, county;
    bool blueflag, lifeguard;
    unsigned long max_capacity;
    float lat, longi;
    float aquaticArea;
    vector<string> basicServices;
    vector<Services> extraServices;

    switch (option) {
        case 1:
            cout << "Insert new name: " << endl;
            cin.ignore(1000, '\n');
            getline(cin, name);
            if(beachExists(name) != -1) { throw  -1;}
            beaches.at(i)->set_name(name);
            break;
        case 2:
            beaches.at(i)->set_blue_flag();
            break;
        case 3:
            beaches.at(i)->set_lifeguard();
            break;
        case 4:
            cout << "Insert new maximum capacity: " << endl;
            cin >> max_capacity;
            beaches.at(i)->set_max_capacity(max_capacity);
            break;
        case 5:
            cout << "Insert new width: " << endl;
            cin >> aquaticArea;
            beaches.at(i)->set_width(aquaticArea);
            break;
        case 6:
            cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
                 << endl;
            cin >> lat >> longi;
            beaches.at(i)->set_latitude(lat);
            beaches.at(i)->set_longitude(longi);
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

    for (int i = 0; i < beaches.size(); ++i) {

        if (beaches.at(i)->get_name() == name) {

            beaches.erase(beaches.begin() + i);
            cout << endl << name << " beach erased successfully!" << string(4, '\n');
            removed = true;
        }
    }

    if (!removed) {
        cout << endl << "ERROR: There is no beach with the given name!" << string(4, '\n');
    }
}

void Company::addService() {

    string name, sType, sName, sPriceRange, sStars;
    unsigned int services, counter;
    int i;

    ClearScreen();

    cout << "Insert name of the beach you wish to add a service to" << endl << ":::";
    cin >> name;

    i = beachExists(name);

    if (i != -1) {

        cout << endl << "How many services do you wish to add? (eg, Hotel, Bar): " << endl << "::: ";
        cin >> services;
        fail(services);
        cin.ignore(1000, '\n');
        counter = 0;
        while (counter < services) {
            cout << endl << "Service " << ++counter << ": ";

            cout << endl << "Type (eg: Hotel, Bar): ";
            getline(cin, sType);

            cout << endl << "Name (eg: Tapada Grande): ";
            getline(cin, sName);

            cout << endl << "Price Range (eg: 1/3): ";
            cin >> sPriceRange;
            while (sPriceRange != "1/3" && sPriceRange != "2/3" && sPriceRange != "3/3") {
                cin.ignore(1000, '\n');
                cout << "Please enter a valid value: ";
                cin >> sPriceRange;
            }

            cout << endl << "Stars (eg: **): ";
            cin >> sStars;
            while (sStars != "*" && sStars != "**" && sStars != "***" && sStars != "****" && sStars != "*****") {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a valid value: ";
                cin >> sStars;
            }

            for(auto & beach_service : beaches.at(i)->getExtraServices()){

                if(beach_service.getName() == sName) {throw -1;}
            }

            beaches.at(i)->add_ExtraService(Services(sType, sName, sPriceRange, sStars));
            cin.ignore(1000, '\n');

            cout << endl << "Added successfully!" << endl;

        }
    }
}

void Company::alterService() {

    string name, service, sType, sName, sPriceRange, sStars;
    unsigned int option;
    int i;
    vector<Services> newServices;

    ClearScreen();

    cout << "Insert name of the beach you wish to alter a service to" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, name);

    i = beachExists(name);

    if (i != -1) {

        cout << "Insert name of the service you wish to alter" << endl << ":::";
        getline(cin, service);

        for (unsigned int j = 0; j < beaches.at(i)->getExtraServices().size(); ++j) {

            if (beaches.at(i)->getExtraServices().at(j).getName() == service) {

                cout << "What information do you wish to alter?" << endl;
                cout << "1. Alter type" << endl;
                cout << "2. Alter name" << endl;
                cout << "3. Alter price range" << endl;
                cout << "4. Alter number of stars" << endl;
                cout << "5. Return to main menu" << endl;
                cout << endl << "Enter a number option: " << endl << ":::";
                cin >> option;

                //verifies if input is valid
                while (cin.fail() || !ValidMenuInput(1, 5, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: " << endl << ":::";
                    cin >> option;
                }

                switch (option) {

                    case 1:
                        cout << "Insert the new type of service" << endl << ":::";
                        cin.ignore(1000, '\n');
                        getline(cin, sType);
                        newServices = beaches.at(i)->getExtraServices();
                        newServices.at(j).setType(sType);
                        beaches.at(i)->set_ExtraServices(newServices);
                        break;
                    case 2:
                        cout << "Insert the new name" << endl << ":::";
                        cin.ignore(1000, '\n');
                        getline(cin, sName);

                        for(auto & beach_service : beaches.at(i)->getExtraServices()){

                            if(beach_service.getName() == sName) {throw -1;}
                        }

                        newServices = beaches.at(i)->getExtraServices();
                        newServices.at(j).setName(sName);
                        beaches.at(i)->set_ExtraServices(newServices);
                        break;
                    case 3:
                        cout << "Insert the new price range" << endl << ":::";
                        cin.ignore(1000, '\n');
                        cin >> sPriceRange;
                        while (sPriceRange != "1/3" && sPriceRange != "2/3" && sPriceRange != "3/3") {
                            cin.ignore(1000, '\n');
                            cout << "Please enter a valid value: ";
                            cin >> sPriceRange;
                        }
                        newServices = beaches.at(i)->getExtraServices();
                        newServices.at(j).setPriceRange(sPriceRange);
                        beaches.at(i)->set_ExtraServices(newServices);
                        break;
                    case 4:
                        cout << "Insert the new number of stars" << endl << ":::";
                        cin.ignore(1000, '\n');
                        cin >> sStars;
                        while (sStars != "*" && sStars != "**" && sStars != "***" && sStars != "****" &&
                               sStars != "*****") {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Please enter a valid value: ";
                            cin >> sStars;
                        }
                        newServices = beaches.at(i)->getExtraServices();
                        newServices.at(j).setStars(sStars);
                        beaches.at(i)->set_ExtraServices(newServices);
                        break;
                    case 5:
                        break;
                }

                cout << endl << "Altered successfully!" << endl;
            }
        }
    }
}

void Company::eraseService() {

    string name, service;
    int i;

    ClearScreen();

    cout << "Insert name of the beach you wish to remove a service from" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, name);

    i = beachExists(name);

    if (i != -1) {

        cout << "Insert name of the service you wish to remove" << endl << ":::";
        cin >> service;

        beaches.at(i)->erase_ExtraService(service);
    }
}

void Company::displayBeaches() {

    int option;

    for (unsigned int i = 0; i < beaches.size(); i++) {

        beaches.at(i)->displayBeach();
    }

    returnMainMenu();

}

void Company::updateFile() {

    ofstream file;
    file.open("BeachFile.txt");

    for (auto &beach: beaches) {
        beach->writeBeach(file);
    }

}

void Company::searchCounty() {

    string county;
    int option;

    ClearScreen();

    cout << "Insert the name of the county you wish to search for beaches" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, county);

    ClearScreen();

    for (auto &beach: beaches) {

        if (beach->get_county() == county) {

            beach->displayBeach();
        }
    }

    returnMainMenu();
}

void Company::searchName() {

    string name;
    int option;

    ClearScreen();

    cout << "Insert the name of the beach you wish to search for" << endl << ":::";
    cin.ignore(1000, '\n');
    getline(cin, name);

    ClearScreen();

    for (auto &beach: beaches) {

        if (beach->get_name() == name) {

            beach->displayBeach();
        }
    }

    returnMainMenu();
}

void Company::searchBlueflag() {

    int option;

    ClearScreen();

    for (auto &beach: beaches) {

        if (beach->get_blue_flag()) {

            beach->displayBeach();
        }
    }

    returnMainMenu();
}

void Company::searchLifeguard() {

    int option;

    ClearScreen();

    for (auto &beach: beaches) {

        if (beach->get_lifeguard()) {

            beach->displayBeach();
        }
    }

    returnMainMenu();
}

void Company::searchClosest() {

    unsigned int option, temp, ind;
    float lat, longi;
    double distance;
    string name;

    ClearScreen();

    cout << "Search for the closest beach by:" << endl;
    cout << "1. Actual location" << endl;
    cout << "2. Actual beach" << endl << ":::";
    cin >> option;
    while (cin.fail() || !ValidMenuInput(1, 2, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    ClearScreen();

    switch (option) {

        case 1:
            cout << "Insert the latitude and the longitude of your actual location" << endl << ":::";
            cin >> lat >> longi;
            distance = beaches.at(0)->distanceToBeach(lat, longi);

            for (unsigned int i = 1; i < beaches.size(); ++i) {

                if (beaches.at(i)->distanceToBeach(lat, longi) <= distance) {

                    distance = beaches.at(i)->distanceToBeach(lat, longi);
                    temp = i;
                }
            }

            cout << "Distance between your actual location and closest beach: " << distance << " km" << endl;
            cout << "Information of the beach: " << endl;
            beaches.at(temp)->displayBeach();
            break;
        case 2:
            cout << "Insert the name of your actual beach" << endl << ":::";
            cin.ignore(1000, '\n');
            getline(cin, name);
            ind = beachExists(name);

            if (ind != -1) {

                lat = beaches.at(ind)->get_latitude();
                longi = beaches.at(ind)->get_longitude();
                distance = beaches.at(0)->distanceToBeach(lat, longi);

                for (unsigned int i = 1; i < beaches.size(); ++i) {

                    if (beaches.at(i)->distanceToBeach(lat, longi) <= distance && i != ind) {

                        distance = beaches.at(i)->distanceToBeach(lat, longi);
                        temp = i;
                    }
                }

                cout << "Distance between your actual beach and closest beach: " << distance << " km" << endl;
                cout << endl << "Information of the beach: " << endl;
                beaches.at(temp)->displayBeach();
                break;
            }
    }

    returnMainMenu();
}

void Company::compareBeaches(Beach *b1, Beach *b2) {
    unsigned long size, size1, size2;

    cout << string(100, '\n') << left;
    cout << "COMPARE BEACHES:" << endl;
    cout << "Distance between beaches: " << b1->distanceToBeach(b2->get_latitude(), b2->get_longitude()) << "Km"
         << endl;
    cout << string(69, '-') << endl;
    cout << "| TYPE:     | " << setw(25) << b1->getType() << " | " << setw(25) << b2->getType() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "| COUNTY:   | " << setw(25) << b1->get_county() << " | " << setw(25) << b2->get_county() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "| NAME:     | " << setw(25) << b1->get_name() << " | " << setw(25) << b2->get_name() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "| CAPACITY: | " << setw(25) << b1->get_max_capacity() << " | " << setw(25) << b2->get_max_capacity()
         << " |" << endl;
    cout << "| MAXIMUM   | " << right << setw(28) << " | " << setw(27) << " |" << endl << left;
    cout << string(69, '-') << endl;
    cout << "| GPS       | " << "(" << fixed << setprecision(5) << right;

    if (fabs(b1->get_latitude()) < 10 && fabs(b1->get_longitude()) < 10) {
        cout << b1->get_latitude() << "," << b1->get_longitude() << ")" << setw(10) << " | ";
    } else if (fabs(b1->get_latitude()) > 10 && fabs(b1->get_longitude()) > 10) {
        cout << b1->get_latitude() << "," << b1->get_longitude() << ")" << setw(8) << " | ";
    } else {
        cout << b1->get_latitude() << "," << b1->get_longitude() << ")" << setw(9) << " | ";
    }

    if (fabs(b2->get_latitude()) < 10 && fabs(b2->get_longitude()) < 10) {
        cout << "(" << b2->get_latitude() << "," << b2->get_longitude() << ")" << setw(9) << " |" << endl;
    } else if (fabs(b2->get_latitude()) > 10 && fabs(b2->get_longitude()) > 10) {
        cout << "(" << b2->get_latitude() << "," << b2->get_longitude() << ")" << setw(7) << " |" << endl;
    } else {
        cout << "(" << b2->get_latitude() << "," << b2->get_longitude() << ")" << setw(8) << " |" << endl;
    }

    cout << "| COORD:    | " << right << setw(28) << " | " << setw(27) << " |" << endl << left;
    cout << string(69, '-') << endl;


    cout << "| USEFUL:   | ";
    if (b1->get_lifeguard()) {
        cout << setw(25) << "Lifeguard" << " | ";
    } else {
        cout << setw(25) << "No lifeguard" << " | ";
    }

    if (b2->get_lifeguard()) {
        cout << setw(25) << "Lifeguard" << " | " << endl;
    } else {
        cout << setw(25) << "No lifeguard" << " | " << endl;
    }

    cout << "| INFO:     | ";
    if (b1->get_blue_flag()) {
        cout << setw(25) << "Blueflag" << " | ";
    } else {
        cout << setw(25) << "No blueflag" << " | ";
    }

    if (b2->get_blue_flag()) {
        cout << setw(25) << "Blueflag" << " | " << endl;
    } else {
        cout << setw(25) << "No blueflag" << " | " << endl;
    }

    size1 = b1->getBasicServices().size();
    size2 = b2->getBasicServices().size();
    if (size1 > size2)
        size = size1;
    else
        size = size2;


    for (unsigned int i = 0; i < size; i++) {
        if (i < size1)
            cout << "|           | " << setw(25) << b1->getBasicServices().at(i) << " | ";
        else
            cout << "|           | " << right << setw(28) << " | " << left;
        if (i < size2)
            cout << setw(25) << b2->getBasicServices().at(i) << " | " << endl;
        else
            cout << right << setw(28) << " | " << endl << left;
    }

    cout << string(69, '-') << endl << endl;


}
