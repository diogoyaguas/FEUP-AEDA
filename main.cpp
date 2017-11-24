#include <iostream>
#include "Interfaces.h"
#include <algorithm>

using namespace std;



int main() {

    Company company;

    cout << company.beachExists("Teixo") << endl;

    ClearScreen();
    
    mainMenu(company);

    return 0;
}



