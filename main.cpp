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

    for(unsigned int i = 0; i < company.getBeaches().size(); i++){

        company.getBeaches().at(i)->displayBeach();
    }

    cout << string(100, '\n');
    mainMenu();

    return 0;
}



