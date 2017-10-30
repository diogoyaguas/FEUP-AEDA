#include <iostream>
#include <cmath>
#include "Beach.h"
using namespace std;

int mainMenu();

int main() {

    cout << endl << "WELCOME!\nDirecting you to Main Menu...\n";
    clock_t start;
    double duration;
    start = clock();



    while(duration != 0.5){
        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    }

    cout << string(100, '\n');
    mainMenu();




    return 0;
}