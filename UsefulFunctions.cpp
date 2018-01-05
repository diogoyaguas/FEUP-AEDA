#include <ctime>
#include <iostream>
#include "UsefulFunctions.h"
using namespace std;

bool ValidMenuInput(int lowerL, int upperL, int input){
    if(input<=upperL && input>=lowerL)
        return true;
    else return false;
}

void ClearScreen() {

    cout << string(50,'\n');
}

string getActualDate() {

    int day, month, year;
    string date, sday, smonth, syear;

    // current date/time based on current system
    time_t now = time(0);

    tm *ltm = localtime(&now);

    // print various components of tm structure.
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day =  ltm->tm_mday;

    if(day < 10){

        sday = '0'+ to_string(day);
    } else sday = to_string(day);

    if(month < 10){

        smonth = '0'+ to_string(month);
    } else smonth = to_string(month);

    syear  = to_string(year);

    date = sday + "-" + smonth + "-" + syear;

    return date;

}

string divideString(char char_to_find, string & line){
    string temp;
    int stop=line.find_first_of(char_to_find);

    if(stop == string::npos)
        return "not_found";

    temp = line.substr(0,stop);
    line = line.substr(stop+2);

    return temp;
}

string insertDate(){

    string newDate;

    cout << "Insert the new date of inspection (e.g. " << getActualDate() << ")" << endl
         << "::: ";
    cin.ignore(1000, '\n');
    getline(cin, newDate);

    while (newDate.size() != 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a date with a valid type: " << endl << "::: ";
        cin >> newDate;
    }

    while (stoi(newDate.substr(6, 4)) > stoi(getActualDate().substr(6, 4))) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a date with a valid year: " << endl << "::: ";
        cin >> newDate;
    }
    if (stoi(newDate.substr(6, 4)) == stoi(getActualDate().substr(6, 4))) {

        while (stoi(newDate.substr(3, 2)) > stoi(getActualDate().substr(3, 2))) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a date with a valid month: " << endl << "::: ";
            cin >> newDate;
        }

        if (stoi(newDate.substr(3, 2)) == stoi(getActualDate().substr(3, 2))) {

            while (stoi(newDate.substr(3, 2)) > stoi(getActualDate().substr(3, 2))) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Please enter a date with a valid day: " << endl << "::: ";
                cin >> newDate;
            }
        }
    }

    return newDate;
}

