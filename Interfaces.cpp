//file contains functions related to user's menus

#include <iostream>
using namespace std;
#include <iomanip>


bool ValidInput(int lowerL, int upperL, int input){
    if(input<=upperL && input>=lowerL)
        return true;
    else return false;
}

int mainMenu() {
    int option;


    cout << " MAIN MENU" << setw(40) << " " << endl;
    cout << setfill('-') << setw(50)<<"-"<<endl;
    cout << "1. Search Beach." << endl;
    cout << "2. Do stuff." << endl;

    cout << endl << "Enter a number option: ";
    cin >> option;

    while(cin.fail()||!ValidInput(1, 1, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    return 0;
}


void timer(){

    clock_t startProgram;
    double duration;
    startProgram = clock();

    while(duration != 0.8){
        duration = ( clock() - startProgram ) / (double) CLOCKS_PER_SEC;
    }

}