#include <iostream>
using namespace std;
#include "Interfaces.h"




int main() {


    Company company;

    cout << string(100, '\n');
    company.compareBeaches(company.getBeaches().at(4),company.getBeaches().at(3));
    //mainMenu(company);


    return 0;
}



