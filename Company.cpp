#include "Company.h"
#include "Interfaces.h"
#include <fstream>
#include "UsefulFunctions.h"
#include <unistd.h>


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

            beaches.insert(new RiverBeach(beach.substr(stop + 2)));
        } else if (type == "Bayou") {

            beaches.insert(new BayouBeach(beach.substr(stop + 2)));
        }
    }
    readClosedServicesFile();
    readInterestPointsFile();
    readClosedInterestPointsFile();
}


Beach *Company::beachExists(string name) {

    auto it = beaches.begin();


    for (it = beaches.begin(); it != beaches.end(); it++) {


        if ((*it)->get_name() == name)
            return (*it);
    }

    return nullptr; // não encontrou
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

    if (beachExists(name) != nullptr) { throw -1; }

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

        beaches.insert(new RiverBeach(county, name, blueflag, lifeguard, max_capacity, lat, longi, width, maxDepth));
    }

    if (type == "Bayou") {

        cout << endl << "Insert width in meters (eg: 1150500000): " << endl << "::: ";
        cin >> aquaticArea;
        fail(aquaticArea);

        beaches.insert(new BayouBeach(county, name, blueflag, lifeguard, max_capacity, lat, longi, aquaticArea));
    }

    cout << endl << "How many basic utilities does the beach have? (eg: wc, showers...): " << endl << "::: ";
    cin >> utilities;
    fail(utilities);
    counter = 0;
    cin.ignore(1000, '\n');
    while (counter < utilities) {
        cout << endl << "service" << ++counter << ": ";
        getline(cin, utility);
        (*beaches.end())->add_BasicService(utility);
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

        (*beaches.end())->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
        cin.ignore(1000, '\n');
    }
    cout << string(2, '\n') << "Beach added successfully!" << string(2, '\n');
    usleep(19000);
}


void Company::alterRBeachInfo(unsigned int option, Beach *b) {
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
            if (beachExists(name) == nullptr) { throw -1; }
            b->set_name(name);
            break;
        case 2:
            b->set_blue_flag();
            break;
        case 3:
            b->set_lifeguard();
            break;
        case 4:
            cout << "Insert new maximum capacity: " << endl;
            cin >> max_capacity;
            b->set_max_capacity(max_capacity);
            break;
        case 5:
            cout << "Insert new width: " << endl;
            cin >> width;
            b->set_width(width);
            break;
        case 6:
            cout << "Insert new depth area: " << endl;
            cin >> maxDepth;
            b->set_maxDepth(maxDepth);
            break;
        case 7:
            cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
                 << endl;
            cin >> lat >> longi;
            b->set_latitude(lat);
            b->set_longitude(longi);
            break;
        case 8:
            break;
    }

}


void Company::alterBBeachInfo(unsigned int option, Beach *b) {
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
            if (beachExists(name) == nullptr) { throw -1; }
            b->set_name(name);
            break;
        case 2:
            b->set_blue_flag();
            break;
        case 3:
            b->set_lifeguard();
            break;
        case 4:
            cout << "Insert new maximum capacity: " << endl;
            cin >> max_capacity;
            b->set_max_capacity(max_capacity);
            break;
        case 5:
            cout << "Insert new width: " << endl;
            cin >> aquaticArea;
            b->set_width(aquaticArea);
            break;
        case 6:
            cout << "Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): "
                 << endl;
            cin >> lat >> longi;
            b->set_latitude(lat);
            b->set_longitude(longi);
            break;
        case 7:
            break;
    }

}


void Company::removeBeach() {
    string name;

    cout << "Insert beach name: ";
    cin >> name;

    if (this->beachExists(name) == nullptr) { throw -1; }

    for (auto it = beaches.begin(); it != beaches.end(); it++) {

        if ((*it)->get_name() == name) {

            beaches.erase(it);
            cout << endl << name << "Beach erased successfully!" << string(4, '\n');
        }
    }
    usleep(19000);

}


void Company::addService() {

    string name, sType, sName, sPriceRange, sStars;
    unsigned int services, counter;

    ClearScreen();

    cout << "Insert name of the beach you wish to add a service to" << endl << "::: ";
    cin >> name;

    Beach *b = beachExists(name);

    if (b == nullptr) { throw -1; }

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

        for (unsigned int i = 0; i < b->getExtraServices().size(); ++i) {

            priority_queue<Services> temp = b->getExtraServices().at(i);

            while (!temp.empty()) {

                Services service = temp.top();
                temp.pop();
                if (service.getName() == sName) { throw -1; }
            }
        }

        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
        cin.ignore();

        cout << endl << "Added successfully!" << endl;
        usleep(19000);
    }

}


void Company::alterService() {

    string name, service, sType, sName, sPriceRange, sStars;
    unsigned int option;
    int i;
    priority_queue<Services> newServices;
    priority_queue<Services> temp_s;

    ClearScreen();

    cout << "Insert name of the beach you wish to alter a service to" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    Beach *b = beachExists(name);

    if (b == nullptr) { throw -1; }

    cout << "Insert name of the service you wish to alter" << endl << "::: ";
    getline(cin, service);

    for (unsigned int i = 0; i < b->getExtraServices().size(); ++i) {

        priority_queue<Services> temp = b->getExtraServices().at(i);

        while (!temp.empty()) {

            Services temp_service = temp.top();
            temp.pop();
            if (temp_service.getName() == service) {

                sType = temp_service.getType();
                sName = temp_service.getName();
                sPriceRange = temp_service.getPriceRange();
                sStars = temp_service.getStars();

                cout << "What information do you wish to alter?" << endl;
                cout << "1. Alter type" << endl;
                cout << "2. Alter name" << endl;
                cout << "3. Alter price range" << endl;
                cout << "4. Alter number of stars" << endl;
                cout << "5. Return to main menu" << endl;
                cout << endl << "Enter a number option: " << endl << "::: ";
                cin >> option;

                //verifies if input is valid
                while (cin.fail() || !ValidMenuInput(1, 5, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: " << endl << "::: ";
                    cin >> option;
                }

                Services old_s = Services(sType, sName, sPriceRange, sStars, getActualDate());

                switch (option) {

                    case 1:
                        b->erase_ExtraService(old_s);
                        cout << "Insert the new type of service" << endl << "::: ";
                        cin.ignore(1000, '\n');
                        getline(cin, sType);
                        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
                        break;
                    case 2:
                        cout << "Insert the new name" << endl << "::: ";
                        cin.ignore(1000, '\n');
                        getline(cin, sName);
                        temp_s = b->getExtraServices().at(i);
                        while (!temp_s.empty()) {

                            Services service = temp_s.top();
                            temp_s.pop();
                            if (service.getName() == sName) { throw -1; }
                        }
                        b->erase_ExtraService(old_s);
                        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
                        break;
                    case 3:
                        cout << "Insert the new price range" << endl << "::: ";
                        cin.ignore(1000, '\n');
                        cin >> sPriceRange;
                        while (sPriceRange != "1/3" && sPriceRange != "2/3" && sPriceRange != "3/3") {
                            cin.ignore(1000, '\n');
                            cout << "Please enter a valid value: ";
                            cin >> sPriceRange;
                        }
                        b->erase_ExtraService(old_s);
                        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
                        break;
                    case 4:
                        cout << "Insert the new number of stars" << endl << "::: ";
                        cin.ignore(1000, '\n');
                        cin >> sStars;
                        while (sStars != "*" && sStars != "**" && sStars != "***" && sStars != "****" &&
                               sStars != "*****") {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Please enter a valid value: ";
                            cin >> sStars;
                        }
                        b->erase_ExtraService(old_s);
                        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
                        break;
                    case 5:
                        break;
                }

                cout << endl << "Altered successfully!" << endl;
                usleep(19000);

                break;
            }

        }
    }
}


void Company::eraseService() {

    string name, r_service;

    ClearScreen();

    cout << "Insert name of the beach you wish to remove a service from" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    Beach *b = beachExists(name);

    if (b != nullptr) { throw -1; }

    cout << "Insert name of the service you wish to remove" << endl << "::: ";
    cin >> r_service;

    for (unsigned int i = 0; i < b->getExtraServices().size(); ++i) {

        priority_queue<Services> temp = b->getExtraServices().at(i);

        while (!temp.empty()) {

            Services service = temp.top();
            temp.pop();
            if (service.getName() == r_service) { b->erase_ExtraService(service); }
        }

    }
}


void Company::displayBeaches() {

    bool exists_ip_near = false;

    ClearScreen();

    for (auto it = beaches.begin(); it != beaches.end(); it++) {

        try { (*it)->displayBeach(); } catch (int x) {
            cout << endl << "This beach doesn't have any services associated." << endl;
        }


        for (auto i = PointsOfInterest.begin(); i != PointsOfInterest.end(); ++i) {
            priority_queue<InterestPoint> interestPts = (*i);

            while(!interestPts.empty()) {
                if((*it)->distanceToBeach(interestPts.top().getLatitude(), interestPts.top().getLongitude()) < 50) {
                    cout << endl << "Services / interest points close by:" << endl;
                    break;
                }
                interestPts.pop();
            }


            interestPts = (*i);

            while(!interestPts.empty()){

                if((*it)->distanceToBeach(interestPts.top().getLatitude(), interestPts.top().getLongitude()) < 50){
                    (*i).top().displayService();
                }
                string n;
                n = (*i).top().getName();
                interestPts.pop();
                n = (*i).top().getName();
            }

            cout << endl;
        }

    }
    returnMainMenu();
}


void Company::searchCounty() {

    string county;
    int option;
    bool found = false;

    ClearScreen();

    cout << "Insert the name of the county you wish to search for beaches" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, county);

    ClearScreen();

    for (auto &beach: beaches) {

        if (beach->get_county() == county) {

            beach->displayBeach();
            found = true;
        }
    }

    if (!found) { throw -1; }
}


void Company::searchName() {

    string name;
    int option;

    ClearScreen();

    cout << "Insert the name of the beach you wish to search for" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    ClearScreen();

    Beach *b = beachExists(name);
    if (b == nullptr) { throw -1; }

    b->displayBeach();
}


void Company::searchBlueflag() {
    bool found = false;

    ClearScreen();

    for (auto it = beaches.begin(); it != beaches.end(); it++) {

        if ((*it)->get_blue_flag()) {

            (*it)->displayBeach();
            found = true;
        }
    }
    if (!found) { throw -1; }

}


void Company::searchLifeguard() {

    bool found = false;
    ClearScreen();

    for (auto it = beaches.begin(); it != beaches.end(); it++) {

        if ((*it)->get_lifeguard()) {

            (*it)->displayBeach();
            found = true;
        }
    }
    if (!found) { throw -1; }
    returnMainMenu();
}


void Company::searchClosest() {

    unsigned int option, ind;
    float lat, longi;
    double distance;
    string name;
    set<Beach *>::iterator temp;

    ClearScreen();

    cout << "Search for the closest beach by:" << endl;
    cout << "1. Current location" << endl;
    cout << "2. Another beach" << endl << "::: ";
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
            cout << "Insert the latitude and the longitude of your current location" << endl << "::: ";
            cin >> lat >> longi;
            distance = (*beaches.begin())->distanceToBeach(lat, longi);

            for (auto it = beaches.begin(); it != beaches.end(); it++) {

                if ((*it)->distanceToBeach(lat, longi) <= distance) {

                    distance = (*it)->distanceToBeach(lat, longi);
                    temp = it;
                }
            }

            cout << "Distance from your current location to closest beach: " << distance << " km" << endl;
            cout << "Information about the beach: " << endl;
            (*temp)->displayBeach();
            break;
        case 2:
            cout << "Insert the name of the beach" << endl << "::: ";
            cin.ignore(1000, '\n');
            getline(cin, name);
            Beach *b = beachExists(name);

            if (b == nullptr) { throw -1; }

            lat = b->get_latitude();
            longi = b->get_longitude();
            distance = (*beaches.begin())->distanceToBeach(lat, longi);

            for (auto it = beaches.begin(); it != beaches.end(); it++) {

                if ((*it)->distanceToBeach(lat, longi) <= distance && (*it) != b) {

                    distance = b->distanceToBeach(lat, longi);
                    temp = it;
                }
            }

            cout << "Distance between the beach you entered and closest beach: " << distance << " km" << endl;
            cout << endl << "Information about the beach: " << endl;
            (*temp)->displayBeach();

            break;

    }

    returnMainMenu();
}


void Company::compareBeaches(Beach *b1, Beach *b2) {
    unsigned long size, size1, size2;

    cout << string(100, '\n') << left << setfill(' ');
    cout << "COMPARE BEACHES:" << endl;
    cout << "Distance between beaches: " << b1->distanceToBeach(b2->get_latitude(), b2->get_longitude()) << "Km"
         << endl;
    cout << string(69, '-') << endl;
    cout << "| TYPE:     | " << setw(25) << b1->getType() << " | " << setw(25) << b2->getType() << " |" << endl;
    cout << string(69, '-') << endl;
    cout << "| COUNTY:   | " << setw(25) << b1->get_county() << " | " << setw(25) << b2->get_county() << " |"
         << endl;
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


void Company::alterDateofInspection() {

    string name, service, sType, sName, sPriceRange, sStars, newDate;
    unsigned int option;
    int i;
    priority_queue<Services> newServices;
    priority_queue<Services> temp_s;

    ClearScreen();

    cout << "Insert name of the beach you wish to alter the date of inspection of a service" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    Beach *b = beachExists(name);

    if (b == nullptr) { throw -1; }

    cout << "Insert name of the service you wish to alter" << endl << "::: ";
    getline(cin, service);

    for (unsigned int i = 0; i < b->getExtraServices().size(); ++i) {

        priority_queue<Services> temp = b->getExtraServices().at(i);

        while (!temp.empty()) {

            Services temp_service = temp.top();
            temp.pop();
            if (temp_service.getName() == service) {

                sType = temp_service.getType();
                sName = temp_service.getName();
                sPriceRange = temp_service.getPriceRange();
                sStars = temp_service.getStars();
                Services old_s = Services(sType, sName, sPriceRange, sStars, getActualDate());

                cout << endl;
                cout << "What date do you wish to enter?" << endl;
                cout << "1. Current date" << endl;
                cout << "2. Past date" << endl;
                cout << "3. Return to main menu" << endl;
                cout << endl << "Enter a number option: " << endl << "::: ";
                cin >> option;

                //verifies if input is valid
                while (cin.fail() || !ValidMenuInput(1, 5, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: " << endl << "::: ";
                    cin >> option;
                }

                switch (option) {

                    case 1:
                        b->erase_ExtraService(old_s);
                        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, getActualDate()));
                        break;
                    case 2:
                        b->erase_ExtraService(old_s);
                        cout << "Insert the new date of inspection (e.g. " << getActualDate() << ")" << endl
                             << "::: ";
                        cin.ignore(1000, '\n');
                        getline(cin, newDate);


                        while (newDate.size() != 10) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Please enter a date with a valid type: " << endl << "::: ";
                            cin >> newDate;
                        }

                        while (stoi(newDate.substr(6, 4)) > stoi(getActualDate().substr(6, 4))) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Please enter a date with a valid year: " << endl << "::: ";
                            cin >> newDate;
                        }
                        if (stoi(newDate.substr(6, 4)) == stoi(getActualDate().substr(6, 4))) {

                            while (stoi(newDate.substr(3, 2)) > stoi(getActualDate().substr(3, 2))) {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Please enter a date with a valid month: " << endl << "::: ";
                                cin >> newDate;
                            }

                            if (stoi(newDate.substr(3, 2)) == stoi(getActualDate().substr(3, 2))) {

                                while (stoi(newDate.substr(3, 2)) > stoi(getActualDate().substr(3, 2))) {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Please enter a date with a valid day: " << endl << "::: ";
                                    cin >> newDate;
                                }
                            }
                        }
                        b->add_ExtraService(Services(sType, sName, sPriceRange, sStars, newDate));
                        break;
                    case 5:
                        break;
                }

                cout << endl << "Date altered successfully!" << endl;
                usleep(1000000);
                break;
            }

        }
    }
}



//services

void Company::closeService() {

    string name, service, sType, sName, sPriceRange, sStars, sDate, newDate, type_of_closing;
    unsigned int option, final;

    ClearScreen();

    cout << "Insert name of the beach you wish to close a service from" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    Beach *b = beachExists(name);

    if (b == nullptr) { throw -1; }

    cout << "Insert name of the service you wish to close" << endl << "::: ";
    getline(cin, service);

    for (unsigned int i = 0; i < b->getExtraServices().size(); ++i) {
        final = i;
        priority_queue<Services> temp = b->getExtraServices().at(i);

        while (!temp.empty()) {

            Services temp_service = temp.top();
            temp.pop();
            if (temp_service.getName() == service) {

                sType = temp_service.getType();
                sName = temp_service.getName();
                sPriceRange = temp_service.getPriceRange();
                sStars = temp_service.getStars();
                sDate = temp_service.getDateInspection();
                Services old_s = Services(sType, sName, sPriceRange, sStars, sDate);

                cout << endl << "When was this service closed?" << endl;
                cout << "1. Current date" << endl;
                cout << "2. Past date" << endl;
                cout << endl << "Enter a number option: " << endl << "::: ";
                cin >> option;


                //verifies if input is valid
                while (cin.fail() || !ValidMenuInput(1, 2, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: " << endl << "::: ";
                    cin >> option;
                }

                switch (option) {

                    case 1:
                        b->erase_ExtraService(old_s);
                        newDate = getActualDate();
                        break;
                    case 2:
                        b->erase_ExtraService(old_s);
                        newDate = insertDate();

                        break;
                    default:
                        break;
                }

                cout << endl << "Do you wish to close it temporarily or permanently?" << endl;
                cout << "1. Temporarily" << endl;
                cout << "2. Permanently" << endl;
                cout << endl << "Enter a number option: " << endl << "::: ";
                cin >> option;

                if (option == 1)
                    type_of_closing = "TEMP";
                else type_of_closing = "PERM";

                b->add_ClosedService(old_s, newDate, type_of_closing);

                cout << "Service closed successfully!" << endl;
                usleep(1000000);
                break;
            }

        }
        if (final == b->getExtraServices().size() - 1 && temp.empty()) { throw -1; }
    }
}


void Company::reopenService() {


    string name, service, sType, sName, sPriceRange, sStars, sDate, newDate;
    HashTable_services table;
    bool exists;

    ClearScreen();

    cout << "Insert name of the beach you wish to reopen a service" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    Beach *b = beachExists(name);

    if (b == nullptr) { throw -1; }

    table = b->getServicesDown();

    cout << "Insert name of the service you wish to reopen" << endl << "::: ";
    getline(cin, service);

    for (auto it = table.begin(); it != table.end(); ++it) {

        if ((*it).service.getName() == service) {

            if ((*it).type_of_closing == "PERM") { throw 0; }
            Services s((*it).service.getType(), (*it).service.getName(), (*it).service.getPriceRange(),
                       (*it).service.getStars(), (*it).service.getDateInspection());
            b->add_ExtraService(s);
            b->removeServiceDown(service);
            cout << "Service reopened successfully!" << endl;
            usleep(16000);
            exists = true;
            break;
        }
    }

    if (!exists) { throw 1; }

}


void Company::displayClosedServices() {

    ClearScreen();

    for (auto beach: beaches) {

        if (!beach->getServicesDown().empty()) {

            cout << endl << "County: " << beach->get_county() << endl;
            cout << "GPS coordinates: " << beach->get_latitude() << " | " << beach->get_longitude() << endl;
            cout << "Name: " << beach->getType() << " Beach " << beach->get_name() << endl;
            cout << "Services closed:" << endl << endl;

            for (auto it: beach->getServicesDown()) {

                cout << it.service.getType() << " " << it.service.getName() << endl;

                if (it.type_of_closing == "PERM") {
                    cout << "Service permanently closed in " << it.date << endl;
                } else if (it.type_of_closing == "TEMP") {
                    cout << "Service temporarily closed in " << it.date << endl;
                }
            }
            cout << setw(40) << setfill('-') << " " << endl;
        }
    }
    usleep(1000000);
}





//interest points

void Company::closePoint() {

    string service, sType, sName, sPriceRange, sStars, sDate, newDate, type_of_closing;
    unsigned int option, final;
    float sLat, sLongi;
    bool deleted = false;

    ClearScreen();
    cin.ignore(1000, '\n');

    cout << "Insert name of the service you wish to close" << endl << "::: ";
    getline(cin, service);

    for (unsigned int i = 0; i < this->PointsOfInterest.size(); ++i) {
        final = i;
        priority_queue<InterestPoint> temp = this->PointsOfInterest.at(i);

        while (!temp.empty()) {

            InterestPoint temp_point = temp.top();
            temp.pop();
            if (temp_point.getName() == service) {

                sType = temp_point.getType();
                sName = temp_point.getName();
                sPriceRange = temp_point.getPriceRange();
                sStars = temp_point.getStars();
                sDate = temp_point.getDateInspection();
                sLat = temp_point.getLatitude();
                sLongi = temp_point.getLongitude();

                Services old_s = Services(sType, sName, sPriceRange, sStars, sDate);
                InterestPoint old_p = InterestPoint(old_s, sLat, sLongi);

                cout << endl << "When was this service closed?" << endl;
                cout << "1. Current date" << endl;
                cout << "2. Past date" << endl;
                cout << endl << "Enter a number option: " << endl << "::: ";
                cin >> option;


                //verifies if input is valid
                while (cin.fail() || !ValidMenuInput(1, 2, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: " << endl << "::: ";
                    cin >> option;
                }


                switch (option) {

                    case 1:
                        newDate = getActualDate();
                        erase_InterestPoints(old_p);
                        deleted = true;
                        break;

                    case 2:
                        erase_InterestPoints(old_p);
                        newDate = insertDate();
                        deleted = true;
                        break;
                }

                cout << endl << "Do you wish to close it temporarily or permanently?" << endl;
                cout << "1. Temporarily" << endl;
                cout << "2. Permanently" << endl;
                cout << endl << "Enter a number option: " << endl << "::: ";
                cin >> option;

                //verifies if input is valid
                while (cin.fail() || !ValidMenuInput(1, 2, option)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Please enter a valid option: " << endl << "::: ";
                    cin >> option;
                }

                if (option == 1)
                    type_of_closing = "TEMP";
                else type_of_closing = "PERM";


                add_ClosedPoint(old_p, newDate, type_of_closing);

                cout << "Service closed successfully!" << endl;
                usleep(100000);
                break;
            }
        }
        if (!deleted) { throw -1; }
    }
}


void Company::reopenClosedPoints() {

    string name, point, sType, sName, sPriceRange, sStars, sDate, newDate;
    HashTable_points table;
    bool exists;

    ClearScreen();

    table = this->PointOfInterest_Closed;


    cout << "Insert name of the service you wish to reopen" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, point);

    for (auto it = table.begin(); it != table.end(); ++it) {


        if ((*it).InterestP.getName() == point) {

            if ((*it).type_of_closing == "PERM") { throw 0; }

            Services s(it->InterestP.getType(), (*it).InterestP.getName(), (*it).InterestP.getPriceRange(),
                       (*it).InterestP.getStars(), (*it).InterestP.getDateInspection());

            InterestPoint p(s, (*it).InterestP.getLatitude(), (*it).InterestP.getLongitude());


            add_InterestPoints(p);

            this->removePointDown(point);

            cout << "Service reopened successfully!" << endl;
            usleep(16000);
            exists = true;
            break;
        }
    }

    if (!exists) { throw 1; }
}


void Company::removePointDown(string name) {
    auto it = this->PointOfInterest_Closed.begin();
    for (; it != this->PointOfInterest_Closed.end(); ++it) {
        if ((*it).InterestP.getName() == name)
            break;
    }

    this->PointOfInterest_Closed.erase(it);
}


void Company::erase_InterestPoints(InterestPoint point) {

    for (unsigned int i = 0; i < this->PointsOfInterest.size(); ++i) {

        if (this->PointsOfInterest.at(i).top().getType() == point.getType()) {

            priority_queue<InterestPoint> temp;
            InterestPoint s_temp;

            while (!this->PointsOfInterest.at(i).empty()) {

                s_temp = this->PointsOfInterest.at(i).top();
                this->PointsOfInterest.at(i).pop();
                if (s_temp.getName() != point.getName()) {

                    temp.push(s_temp);
                }
            }

            while (!temp.empty()) {

                s_temp = temp.top();
                temp.pop();
                this->PointsOfInterest.at(i).push(s_temp);
            }
        }
    }


}


void Company::add_InterestPoints(InterestPoint point) {

    for (unsigned int i = 0; i < this->PointsOfInterest.size(); ++i) {

        if (this->PointsOfInterest.at(i).top().getType() == point.getType()) {

            this->PointsOfInterest.at(i).push(point);
            return;
        }
    }

    priority_queue<InterestPoint> new_q;
    new_q.push(point);
    this->PointsOfInterest.push_back(new_q);

}


void Company::add_ClosedPoint(InterestPoint point, string date, string type_of_closing) {

    string size;
    struct_pointsShutDown close;
    close.date = date;
    close.InterestP = point;
    close.type_of_closing = type_of_closing;
    this->PointOfInterest_Closed.insert(close);
    size = (*this->PointOfInterest_Closed.begin()).date;

}




//reading and updating
void Company::readClosedServicesFile() {
    fstream file;
    string service, beach_name;
    file.open("ClosedServicesFile.txt");

    while (getline(file, service)) {
        beach_name = divideString(';', service);
        for (auto it = beaches.begin(); it != beaches.end(); ++it) {
            if (beach_name == (*it)->get_name()) {
                (*it)->readClosedServices(service);
                break;
            }
        }
    }
}


void Company::readInterestPointsFile() {
    fstream file;
    string line, temp;
    Services service;
    float lat, longi;
    bool added = false;

    file.open("InterestPointsFile.txt");

    while (getline(file, line)) {
        temp = divideString(';', line);
        service = Services(temp);
        lat = stof(divideString(';', line));
        longi = stof(line);
        InterestPoint p(service, lat, longi);

        for (auto it = PointsOfInterest.begin(); it != PointsOfInterest.end(); ++it) {
            if ((*it).top().getType() == service.getType()) {
                (*it).push(p);
                added = true;
                break;
            }
        }

        if (!added) {
            priority_queue<InterestPoint> new_q;
            new_q.push(p);
            this->PointsOfInterest.push_back(new_q);
        }
    }
}


void Company::readClosedInterestPointsFile() {


    fstream file;
    string line, temp;
    string type_of_closing, date;
    Services service;
    float lat, longi;
    bool added = false;

    file.open("ClosedInterestPointsFile.txt");

    while (getline(file, line)) {

        temp = divideString(';', line);
        type_of_closing = temp;
        date = divideString(';', line);
        temp = divideString(';', line);
        service = Services(temp);
        lat = stof(divideString(';', line));
        longi = stof(line);
        InterestPoint p(service, lat, longi);
        add_ClosedPoint(p,date,type_of_closing);
    }
}


void Company::updateFile() {

    ofstream file;
    file.open("BeachFile.txt");

    for (auto it = beaches.begin(); it != beaches.end(); it++) {
        (*it)->writeBeach(file);
        if ((*it) != (*beaches.end()))
            file << endl;
    }

}


void Company::updateClosedServicesFile() {
    ofstream file;
    file.open("ClosedServicesFile.txt");

    for (auto it = this->beaches.begin(); it != this->beaches.end(); ++it) {
        if (!(*it)->getServicesDown().empty()) {
            (*it)->writeBeachClosedServices(file);
        }
    }
}


void Company::updateClosedInterestPointsFile() {

    ofstream file;
    file.open("ClosedInterestPointsFile.txt");
    string a;

    for (auto it = this->PointOfInterest_Closed.begin(); it != this->PointOfInterest_Closed.end(); ++it) {;
        file << (*it).type_of_closing;
        file << "; " << (*it).date << "; ";
        (*it).InterestP.writeService(file);
        a =  (*it).InterestP.getName();
        file << endl;
    }
    file.close();
}


void Company::updateInterestPointsFile() {
    ofstream file;
    file.open("InterestPointsFile.txt");

    for (auto it = this->PointsOfInterest.begin(); it != this->PointsOfInterest.end(); ++it) {;

        while (!(*it).empty()) {
            InterestPoint p = (*it).top();
            (*it).pop();
            p.writeService(file);
            file << endl;
        }
    }
    file.close();
}