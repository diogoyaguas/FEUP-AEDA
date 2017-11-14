//file contains functions related to user's menus

#include <iostream>
using namespace std;
#include <iomanip>
#include "Interfaces.h"


bool ValidInput(int lowerL, int upperL, int input){
    if(input<=upperL && input>=lowerL)
        return true;
    else return false;
}

void timer(){

    clock_t startProgram;
    double duration;
    startProgram = clock();

    while(duration != 0.6){
        duration = ( clock() - startProgram ) / (double) CLOCKS_PER_SEC;
    }
}


void mainMenu() {
    int option;

    cout << " MAIN MENU" << setw(40)<< setfill(' ') << " " << endl;
    cout << setfill('-') << setw(50)<<"-"<<endl;
    cout << "1. Search Beach." << endl;
    cout << "2. Compare Beaches." << endl;
    cout << "3. Update Beaches' file." << endl;

    cout << endl << "Enter a number option: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidInput(1, 3, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    //redirect to next menu
    switch(option) {
        case 1:
            searchMenu();

    }}



void searchMenu(){
    int option;

    cout << string(100,'\n');
    cout << " SEARCH BEACH" << setw(37) << setfill(' ') << " " << endl;
    cout << setfill('-') << setw(47)<<"-"<<endl;
    cout << "1. Search by county" << endl;
    cout << "2. Search by name." << endl;
    cout << "3. Search by Blue Flag" << endl;
    cout << "4. Search by Lifeguard" << endl;
    cout << "5. Search closest beach" << endl;
    cout << "6. Search by Services" << endl;

    cout << endl << "Enter a number option: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidInput(1, 6, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    //do stuff

}
