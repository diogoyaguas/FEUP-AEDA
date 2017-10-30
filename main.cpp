#include <iostream>
#include <cmath>
#include "Beach.h"
#include <fstream>
using namespace std;

int mainMenu();
void timer();

int main() {

    fstream beachFile;
    string fileName = "BeachFile.txt";




    cout << endl << "WELCOME!Loading files...\n";

    timer();


    beachFile.open(fileName);
    if(!beachFile.is_open()){
        cout << "Error in opening file. Exiting program...";
        return 1;

    }

    cout << string(100, '\n');
    mainMenu();




    return 0;
}



