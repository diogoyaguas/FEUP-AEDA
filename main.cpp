#include <iostream>
#include <cmath>
#include "Beach.h"
#include <fstream>
#include <vector>
using namespace std;

int mainMenu();
void timer();
int readBeachFile();
vector<Beach> Beaches;

int main() {


    cout << endl << "WELCOME! Loading files...\n";
    timer();


    readBeachFile();


    cout << string(100, '\n');
    mainMenu();

    return 0;
}



