//
// Created by Beatriz Mendes on 06/11/2017.
//

#ifndef AEDA_SERVICE_H
#define AEDA_SERVICE_H

#include <iostream>
using namespace std;

class Service {
    string type, name, priceRange, stars;

public:
    Service(string type, string name, string priceRange, string stars);
    string getType(){return type;}
    string getName(){return name;}
    string getPriceRange(){return priceRange;}
    string getStars(){return stars;}

};


#endif //AEDA_SERVICE_H
