//file contains functions related to user's menus

#include <iostream>
#include <iomanip>
#include "UsefulFunctions.h"
#include "Interfaces.h"
#include <unistd.h>

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


void mainMenu(Company &company) {

    int option;

    cout << " MAIN MENU" << setw(40)<< setfill(' ') << " " << endl;
    cout << setfill('-') << setw(50)<<"-"<<endl;
    cout << "1. Display all beaches" << endl;
    cout << "2. Search beach" << endl;
    cout << "3. Compare beaches" << endl;
    cout << "4. Add, alter or remove" << endl;
    cout << "5. Update files" << endl << endl;
    cout << "6. Exit" << endl;

    cout << endl << "Enter a number option: " << endl << "::: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 6, option)) {
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
            company.updateClosedServicesFile();
            ClearScreen();
            mainMenu(company);
            break;
        case 6:
            exit(1);
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
    cout << "5. Search closest beach" << endl << endl;
    cout << "6. Return to main menu" << endl;

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
            try{company.searchCounty();}
            catch(int x){
                cout << endl << "ERROR: Beach with given county doesn't exist! Redirecting to previous menu..." << endl;
                usleep(1000000);
                searchMenu(company);
                break;
            }
            returnMainMenu();
            break;
        case 2:
            try{company.searchName();}
            catch(int x){
                cout << endl << "ERROR: Beach with given name doesn't exist! Redirecting to previous menu..." << endl;
                sleep(1000000);
                searchMenu(company);
                break;
            }
            returnMainMenu();
            break;
        case 3:
            try{company.searchBlueflag();}
            catch(int x){
                cout << endl << "ERROR: There are no beach with blueflag! Redirecting to previous menu..." << endl;
                usleep(1000000);
                searchMenu(company);
                break;
            }
            returnMainMenu();
            break;
        case 4:
            try{company.searchLifeguard();}
            catch(int x){
                cout << endl << "ERROR: There are no beach with lifeguard! Redirecting to previous menu..." << endl;
                usleep(1000000);
                searchMenu(company);
                break;
            }
            returnMainMenu();
            break;
        case 5:
            try{company.searchClosest();}
            catch(int x){
                cout << endl << "ERROR: Beach doesn't exist! Redirecting to previous menu..." << endl;
                usleep(1000000);
                searchMenu(company);
                break;
            }
            returnMainMenu();
            break;
        case 6:
            ClearScreen();
            mainMenu(company);
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
    cout << "3. Remove beach" << endl << endl;
    cout << "4. Services" << endl << endl;
    cout << "5. Return to main menu" << endl;

    cout << endl << "Enter a number option: " << endl << "::: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 5, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: "<< endl << "::: ";
        cin >> option;
    }

    switch(option){
        case 1:
            try{company.addBeach();}
            catch(int x){
                cout << endl << "ERROR: Beach already exists! Redirecting to previous menu..." << endl;
                usleep(1000000);
                AddAlterRemoveMenu(company);
                break;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 2:
            try{AlterBeachMenu(company);}
            catch(int x){
                cout << endl << "ERROR: Beach already exists! Redirecting to previous menu..." << endl;
                usleep(1000000);
                AddAlterRemoveMenu(company);
                break;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 3:
            try{company.removeBeach();}
            catch(int x){
                cout << endl << "ERROR: Beach doesn't exists! Redirecting to previous menu..." << endl;
                usleep(1000000);
                AddAlterRemoveMenu(company);
                break;
            }
            ClearScreen();
            mainMenu(company);
            break;
        case 4:
            AlterServicesMenu(company);
            break;
        case 5:
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

    if(company.beachExists(name)==nullptr) {throw -1;}

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
        cout << ++displayOption << ". Return to main menu" << endl;

        //Collect input
        cout << endl << "Enter a number option: "<< endl << "::: ";
        cin >> option;

        //verifies if input is valid
        while (cin.fail() || !ValidMenuInput(1, 8, option)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid option: "<< endl << "::: ";
            cin >> option;
        }

        if(option == 8){returnMainMenu();}

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


void AlterServicesMenu(Company &company){
    int option;

    cout << string(100,'\n');
    cout << " SERVICES" << setw(37) << setfill(' ') << " " << endl;
    cout << setfill('-') << setw(47)<<"-"<<endl;
    cout << "1. Add service" << endl;
    cout << "2. Alter service" << endl;
    cout << "3. Remove service" << endl << endl;
    cout << "4. Inspection service" << endl;
    cout << "5. Close service" << endl;
    cout << "6. Reopen service" << endl;
    cout << "7. Display closed services" << endl << endl;
    cout << "8. Return to main menu" << endl;

    cout << endl << "Enter a number option: " << endl << "::: ";
    cin >> option;

    //verifies if input is valid
    while(cin.fail()||!ValidMenuInput(1, 8, option)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid option: "<< endl << "::: ";
        cin >> option;
    }

    switch(option){
        case 1:
            try{company.addService();}
            catch(int x){
                cout << endl << "ERROR: Service already exists! Redirecting to previous menu..." << endl;
                usleep(190000);
                AlterServicesMenu(company);
                break;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 2:
            try{company.alterService();}
            catch(int x){
                cout << endl << "ERROR: Service already exists! Redirecting to previous menu..." << endl;
                usleep(190000);
                AlterServicesMenu(company);
                break;
            }
            returnMainMenu();
            ClearScreen();
            mainMenu(company);
            break;
        case 3:
            try{company.eraseService();}
            catch(int x){
                cout << endl << "ERROR: Service doesn't exist! Redirecting to previous menu..." << endl;
                usleep(190000);
                AlterServicesMenu(company);
                break;
            }
            ClearScreen();
            mainMenu(company);
            break;
        case 4:
            try{company.alterDateofInspection();}
            catch(int x){
                cout << endl << "ERROR: Service doesn't exist! Redirecting to previous menu..." << endl;
                usleep(190000);
                AlterServicesMenu(company);
                break;
            }
            ClearScreen();
            mainMenu(company);
            break;
        case 5:
            try{company.closeService();}
            catch(int x){
                cout << endl << "ERROR: Service doesn't exist! Redirecting to previous menu..." << endl;
                usleep(190000);
                AlterServicesMenu(company);
                break;
            }
            ClearScreen();
            mainMenu(company);
            break;
        case 6:
            try{company.reopenService();}
            catch(int x){
                if(x == -1)
                    cout << endl << "ERROR: Beach doesn't exist! Redirecting to previous menu..." << endl;
                else
                    cout << endl << "ERROR: Service doesn't exist! Redirecting to previous menu..." << endl;
                usleep(190000);
                AlterServicesMenu(company);
                break;
            }
            ClearScreen();
            mainMenu(company);
            break;
        case 7:
            company.displayClosedServices();
            ClearScreen();
            mainMenu(company);
            break;
        case 8:
            ClearScreen();
            mainMenu(company);
            break;
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

