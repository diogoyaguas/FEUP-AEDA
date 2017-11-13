//functions related to reading, adding or deleting info in files

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int readBeachFile(){

    fstream beachFile;
    istringstream BeachStream(textBeach);


    //verify file is successfully opened
    beachFile.open("BeachFile.txt");
    if(!beachFile.is_open()){
        cout << "Error in opening file. Exiting program...";
        return -1;

    }

    string type,county, name;

    if(type == "rio"){

        BeachStream.ignore(1000,';');

    }
    return 0;
}