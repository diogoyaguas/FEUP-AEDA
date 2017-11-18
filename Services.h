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
    /**
     * @brief helper construtor for class Services which creates an object from information in file
     * @param string containing service attributes separated by collumns
     */
    Services(string service);
    Services();
    /**
     * @return type
     */
    string getType(){return type;}
    /**
     * @return name
     */
    string getName(){return name;}
    /**
     * @return price range
     */
    string getPriceRange(){return priceRange;}
    /**
     * @return stars
     */
    string getStars(){return stars;}
    /**
     *
     * @param type
     */
    void setType(string type) {this->type = type;}
    /**
     *
     * @param name
     */
    void setName(string name) {this->name = name;}
    /**
     *
     * @param price
     */
    void setPriceRange(string price) {this->priceRange = price;}
    /**
     *
     * @param stars
     */
    void setStars(string stars) {this->stars = stars;}
};

#endif //AEDA_SERVICES_H
