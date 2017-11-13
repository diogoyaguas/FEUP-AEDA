#include <iostream>
#include <cmath>
#include "Beach.h"
#include <fstream>
#include <vector>
using namespace std;

#include "Interfaces.h"

int readBeachFile();


int main() {

    cout << endl << "WELCOME! Loading file...\n";
    timer();


    readBeachFile();


    cout << string(100, '\n');
    mainMenu();

    return 0;
}



