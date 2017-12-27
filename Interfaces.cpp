//file contains functions related to user's menus

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Interfaces.h"

using namespace std;

void returnMainMenu(){
    int option;

    cout << endl << "0. Return to main menu" << endl << "::: ";
    cin >> option;

    while (cin.fail() || !ValidMenuInput(0, 0, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: " << endl << "::: ";
        cin >> option;
    }
}



bool ValidMenuInput(int lowerL, int upperL, int input){
    if(input<=upperL && input>=lowerL)
        return true;
    else return false;
}



void mainMenu(Company &company) {

    int option;

    cout << " MAIN MENU" << setw(40)<< setfill(' ') << " " << endl;
    cout << setfill('-') << setw(50)<<"-"<<endl;
    cout << "1. Display all beaches" << endl;
    cout << "2. Search beach." << endl;
    cout << "3. Compare beaches." << endl;
    cout << "4. Add, alter or remove beach." << endl;
    cout << "5. Update beaches' file." << endl;

    cout << endl << "Enter a number option: " << endl << "::: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 5, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: "<< endl << "::: ";
        cin >> option;
    }

    //redirect to next menu
    switch(option) {
        case 1:
            company.displayBeaches();
            ClearScreen();
            mainMenu(company);
            break;
        case 2:
            searchMenu(company);
            ClearScreen();
            mainMenu(company);
            break;
        case 3:
            compareMenu(company);
            ClearScreen();
            mainMenu(company);
            break;
        case 4:
            AddAlterRemoveMenu(company);
            ClearScreen();
            break;
        case 5:
            company.updateFile();
            ClearScreen();
            mainMenu(company);
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

    switch(option) {

        case 1:
            company.searchCounty();
            break;
        case 2:
            company.searchName();
            break;
        case 3:
            company.searchBlueflag();
            break;
        case 4:
            company.searchLifeguard();
            break;
        case 5:
            company.searchClosest();
            break;
    }

}

void AddAlterRemoveMenu(Company &company){

    int option;

    cout << string(100,'\n');
    cout << " ALTER BEACH FILE" << setw(37) << setfill(' ') << " " << endl;
    cout << setfill('-') << setw(47)<<"-"<<endl;
    cout << "1. Add beach" << endl;
    cout << "2. Alter beach" << endl;
    cout << "3. Remove beach" << endl;
    cout << "4. Add service" << endl;
    cout << "5. Alter service" << endl;
    cout << "6. Remove service" << endl;
    cout << "7. Return to main menu" << endl;

    cout << endl << "Enter a number option: " << endl << "::: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 7, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: "<< endl << "::: ";
        cin >> option;
    }

    switch(option){
        case 1:
            try{company.addBeach();}
            catch(int x){
                cout << endl << "ERROR: Beach already exists!" << endl;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 2:
            AlterBeachMenu(company);
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 3:
            company.removeBeach();
            ClearScreen();
            mainMenu(company);
            break;
        case 4:
            try{company.addService();}
            catch(int x){
                cout << endl << "ERROR: Service already exists!" << endl;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 5:
            try{company.alterService();}
            catch(int x){
                cout << endl << "ERROR: Service already exists!" << endl;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 6:
            company.eraseService();
            ClearScreen();
            mainMenu(company);
            break;
        case 7:
            ClearScreen();
            mainMenu(company);
            break;
    }
}

void AlterBeachMenu(Company &company){

    unsigned int displayOption=1;
    unsigned int option;
    int i, x;
    string name;

    cout << "Insert beach name" << endl << "::: ";
    cin.ignore(1000, '\n');
    getline(cin,name);


    if(i!=-1) {

        //Display options
        cout << string(100, '\n');
        cout << "WHAT INFORMATION DO YOU WISH TO CHANGE?" << setw(37) << setfill(' ') << " " << endl;
        cout << setfill('-') << setw(47) << "-" << endl;
        cout << displayOption << ". Name" << endl;
        cout << ++displayOption << ". Blue Flag" << endl;
        cout << ++displayOption << ". Lifeguard" << endl;
        cout << ++displayOption << ". Maximum capacity" << endl;

        if(company.beachExists(name)->getType()=="River"){
            cout << ++displayOption << ". Change width" << endl;
            cout << ++displayOption << ". Change maximum depth" << endl;

        } else {
            cout << ++displayOption << ". Change aquatic area" << endl;
        }

        cout << ++displayOption << ". GPS coordinates" << endl;
        cout  << ++displayOption << ". Change services" << endl;

        //Collect input
        cout << endl << "Enter a number option: "<< endl << "::: ";
        cin >> option;

        //verifies if input is valid
        while (cin.fail() || !ValidMenuInput(1, 7, option)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid option: "<< endl << "::: ";
            cin >> option;
        }

        //Alter according if to it's type
        if(company.beachExists(name)->getType()=="River"){

            try{company.alterRBeachInfo(option,company.beachExists(name));} catch(int x){
                x = -1;
                cout << endl << "ERROR: Beach already exists!" << endl;
            }
        }else{
            try{company.alterBBeachInfo(option,company.beachExists(name));}catch(int x){
                x = -1;
                cout << endl << "ERROR: Beach already exists!" << endl;
            }
        }

        //If 'if' verifies and function reaches here succeed
        if(x != -1) cout << "Information altered successfully!" << string(4,'\n');

    } else {
        cout << "ERROR: Beach with given name doesn't exist." << endl;
        AddAlterRemoveMenu(company);
    }
}

void compareMenu(Company &company){

    string b1, b2;

    int ind1, ind2;

    cout << "Insert the name of the two beaches you wish to compare:" << endl << "::: ";
    cin >> b1;
    cout << "::: ";
    cin >> b2;

    company.compareBeaches(company.beachExists(b1),company.beachExists(b2));

    returnMainMenu();
}


void ClearScreen() {

    cout << string(50,'\n');
}


