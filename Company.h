#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"
#include <iomanip>
#include <math.h>

class Company {
private:
    vector<Beach *> beaches;
public:
    /**
     * Constructor of class Company
     */
    Company();
    /**
     * @return vector Beaches
     */
    vector<Beach *> getBeaches(){return beaches;}
    /**
     * @brief adds beach to Beaches' vector with user's input information
     */
    void addBeach();
    /**
     * @brief removes beach to Beaches' vector with user's input information
     */
    void removeBeach();
    /**
     * @brief alters river beach to Beaches' vector with user's input information
     * @param option chose in  Alter Beach Menu
     * @param position of beach in Beaches' vector
     */
    void alterRBeachInfo(unsigned int option, unsigned int i);
    /**
     * @brief alters bayou beach to Beaches' vector with user's input information
     * @param option chose in  Alter Beach Menu
     * @param position of beach in Beaches' vector
     */
    void alterBBeachInfo(unsigned int option, unsigned int i);
    /**
     *@brief adds a service to a certain beach
     */
    void addService();
    /**
     *
     */
    void alterService();
    /**
     *@brief erases a service from a certain beach
     */
    void eraseService();
    /**
     * @brief verifies if beach with certain name exist
     * @param name
     * @return pos of beach in Beaches' vector if beach with name exists, -1 otherwise
     */
    int beachExists(string name);
    /**
     * @brief displays the information about all beaches
     */
    void displayBeaches();
    /**
     *@brief updates the file containing the information about the beaches according to the changes made in the program
     */
    void updateFile();
    /**
     *
     */
    void searchCounty();
    /**
     *
     */
    void searchName();
    /**
     *
     */
    void searchBlueflag();
    /**
     *
     */
    void searchLifeguard();
    /**
     *
     */
    void searchClosest();
    /**
     * @brief displays information about 2 beaches side by side
     * @param 1st Beach
     * @param 2nd Beach
     */
    void compareBeaches(Beach * b1, Beach * b2);

};


#endif //AEDA_COMPANY_H
