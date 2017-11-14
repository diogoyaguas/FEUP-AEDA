//
// Created by Beatriz Mendes on 14/11/2017.
//

#include "Company.h"
#include <fstream>

Company::Company() {
    string fileBeach = "BeachFile.txt";
    ifstream file;
    string beach, type;
    unsigned long stop;

    //verify file is successfully opened

    file.open(fileBeach);

    if(!file.is_open()){
        cout << "Error in opening file. Exiting program...";
        exit(1);

    }

    while (getline(file, beach))
    {
        stop = beach.find_first_of(';');
        type = beach.substr(0, stop);


        if (type == "rio") {

            Beaches.push_back(new RiverBeach(beach.substr(stop + 2)));
        }

        else if (type == "albufeira") {

            Beaches.push_back(new BayouBeach(beach.substr(stop + 2)));
        }
    }
}

vector<Beach *> Company::getBeaches(){
    return Beaches;
}