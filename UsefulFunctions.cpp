//
// Created by Beatriz Mendes on 27/12/2017.
//

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