#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"

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
     *
     */
    void addService();
    /**
     *
     */
    void eraseService();
    /**
     * @brief verifies if beach with certain name exist
     * @param name
     * @return pos of beach in Beaches' vector if beach with name exists, -1 otherwise
     */
    unsigned int beachExists(string name);
    /**
     * @brief displays the information about all beaches
     */
    void displayBeaches();
    /**
     *
     */
    void updateFile();

};




#endif //AEDA_COMPANY_H
