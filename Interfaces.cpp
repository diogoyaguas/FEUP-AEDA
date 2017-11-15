//file contains functions related to user's menus

#include <iostream>
using namespace std;
#include <iomanip>
#include "Interfaces.h"


bool ValidMenuInput(int lowerL, int upperL, int input){
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


void mainMenu(Company &company) {
    int option;

    cout << " MAIN MENU" << setw(40)<< setfill(' ') << " " << endl;
    cout << setfill('-') << setw(50)<<"-"<<endl;
    cout << "1. Search Beach." << endl;
    cout << "2. Compare Beaches." << endl;
    cout << "3. Add, alter or remove beach." << endl;
    cout << "4. Update Beaches' file." << endl;

    cout << endl << "Enter a number option: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 4, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    //redirect to next menu
    switch(option) {
        case 1:
            searchMenu(company);
            break;
        case 3:
            AddAlterRemoveMenu(company);
            break;

    }}



void searchMenu(Company &company){
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
    while(cin.fail()||!ValidMenuInput(1, 6, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    //do stuff

}

void AddAlterRemoveMenu(Company &company){

    int option;

    cout << string(100,'\n');
    cout << " ALTER BEACH FILE" << setw(37) << setfill(' ') << " " << endl;
    cout << setfill('-') << setw(47)<<"-"<<endl;
    cout << "1. Add beach." << endl;
    cout << "2. Remove beach." << endl;
    cout << "3. Alter beach." << endl;
    cout << "4. Return to main menu" << endl;

    cout << endl << "Enter a number option: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 4, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: ";
        cin >> option;
    }

    switch(option){
        case 1:
            company.addBeach();
            mainMenu(company);
            break;
        case 2:
            company.removeBeach();
            mainMenu(company);
            break;
        case 3:
            AlterBeachMenu(company);
            break;
        case 4:
            mainMenu(company);
            break;
    }
}

void AlterBeachMenu(Company &company){
    unsigned int displayOption=1;
    unsigned int option, i;
    string name;

    cout << "Insert beach name" << endl;
    cin >> name;

    i= company.beachExists(name);

    if(i!=-1) {

        //Display options
        cout << string(100, '\n');
        cout << "WHAT INFORMATION DO YOU WISH TO CHANGE?" << setw(37) << setfill(' ') << " " << endl;
        cout << setfill('-') << setw(47) << "-" << endl;
        cout << displayOption << ". Name" << endl;
        cout << ++displayOption << ". Blue Flag" << endl;
        cout << ++displayOption << ". Lifeguard" << endl;
        cout << ++displayOption << ". Maximum capacity" << endl;

        if(company.getBeaches().at(company.beachExists(name))->getType()=="River"){
            cout << ++displayOption << ". Change width" << endl;
            cout << ++displayOption << ". Change maximum depth" << endl;

        } else {
            cout << ++displayOption << ". Change aquatic area" << endl;
        }

        cout << ++displayOption << ". GPS coordinates" << endl;
        cout  << ++displayOption << ". Change services" << endl;


        //Collect input
        cout << endl << "Enter a number option: ";
        cin >> option;

        //verifies if input is valid
        while (cin.fail() || !ValidMenuInput(1, 7, option)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid option: ";
            cin >> option;
        }


        //Alter according if to it's type
        if(company.getBeaches().at(company.beachExists(name))->getType()=="River"){
            company.alterRBeachInfo(option,i);
            cout << "Information altered successfully!" << string(4,'\n');
            mainMenu(company);
        }else{

        }

    } else {
        cout << "ERROR: Beach with given name doesn't exist." << endl;
        AddAlterRemoveMenu(company);
    }
}
