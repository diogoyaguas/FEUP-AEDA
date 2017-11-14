//functions related to reading, adding or deleting info in files

#include <fstream>
#include <iostream>
#include "Beach.h"


using namespace std;

int readBeachFile(){

    string fileBeach = "BeachFile.txt";
    ifstream file(fileBeach);
    string beach, type;
    unsigned long stop;

    //verify file is successfully opened

    file.open("BeachFile.txt");
    if(!file.is_open()){
        cout << "Error in opening file. Exiting program...";
        return -1;

    }

   while (getline(file, beach))
   {
       stop = beach.find_first_of(';');
       type = beach.substr(0, stop);

       if (type == "rio") {

           //Beaches.push_back(RiverBeach(beach.substr(stop + 2)));

       } else
           //Beaches.push_back(BayouBeach(beach.substr(stop+2)));
           return 1;
   }

    return 0;
}