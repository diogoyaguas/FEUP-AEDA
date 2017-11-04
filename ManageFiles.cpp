//functions related to reading, adding or deleting info in files

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int readBeachFile(){

    fstream beachFile;
    string beachInfo, tempName, tempDistrict;


    //verify file is successfully opened
    beachFile.open("BeachFile.txt");
    if(!beachFile.is_open()){
        cout << "Error in opening file. Exiting program...";
        return 1;

    }

    /*while(beachFile.eof()) {
        //fazer cenas
    }*/
    return 0;
}