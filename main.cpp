#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

#include "Interfaces.h"
#include "Company.h"



int main() {

    cout << endl << "WELCOME! Loading file...\n";
    timer();

    Company company;



    cout << string(100, '\n');
    mainMenu();

    return 0;
}



