//
// Created by Beatriz Mendes on 06/11/2017.
//

#ifndef AEDA_SERVICES_H
#define AEDA_SERVICES_H

#include <iostream>
using namespace std;

class Services {
    string type, name, priceRange, stars;

public:
    /**
     * @brief constructor class Services
     * @param type
     * @param name
     * @param priceRange
     * @param stars
     */
    Services(string type, string name, string priceRange, string stars);
    Services(string service);
    Services();
    string getType(){return type;}
    string getName(){return name;}
    string getPriceRange(){return priceRange;}
    string getStars(){return stars;}
};




#endif //AEDA_SERVICES_H
