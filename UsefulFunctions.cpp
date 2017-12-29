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

    cout << date << endl;

    return date;

}

string divideString(char char_to_find, string & line){
    string temp;

        temp = line.substr(0,line.find_first_of(char_to_find));
        line = line.substr(line.find_first_of(char_to_find)+2);

    return temp;
}

