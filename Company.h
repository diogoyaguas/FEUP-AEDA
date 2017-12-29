#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"
#include <iomanip>
#include <math.h>
#include <set>

struct SortOrder{
    bool operator()(const Beach * b1, const Beach * b2) const{
        if (b1->get_county()!= b2->get_county())
            return b1->get_county() < b2->get_county();
        else return b1->get_blue_flag() > b2->get_blue_flag();
    }
};

class Company {
private:
    set <Beach *, SortOrder> beaches;
public:
    /**
     * Constructor of class Company.
     */
    Company();

    /**
     * @return vector Beaches
     */
    set<Beach *, SortOrder> getBeaches(){return beaches;}

    /**
     * @brief Adds beach to Beaches' vector with user's input information.
     */
    void addBeach();

    /**
     * @brief Removes beach to Beaches' vector with user's input information.
     */
    void removeBeach();

    /**
     * @brief Alters river beach to Beaches' vector with user's input information.
     * @param option chose in  Alter Beach Menu
     * @param position of beach in Beaches' vector
     */
    void alterRBeachInfo(unsigned int option, Beach * b);

    /**
     * @brief Alters bayou beach to Beaches' vector with user's input information.
     * @param option chose in  Alter Beach Menu
     * @param position of beach in Beaches' vector
     */
    void alterBBeachInfo(unsigned int option, Beach * b);

    /**
     *@brief Adds a service to a certain beach.
     */
    void addService();

    /**
     * @brief Alters a service.
     */
    void alterService();
    /**
     *@brief Erases a service from a certain beach.
     */
    void eraseService();

    /**
     * @brief Verifies if beach with certain name exist.
     * @param name
     * @return pos of beach in Beaches' vector if beach with name exists, -1 otherwise
     */
    Beach * beachExists(string name);

    /**
     * @brief Displays the information about all beaches.
     */
    void displayBeaches();

    /**
     *@brief Updates the file containing the information about the beaches according to the changes made in the program.
     */
    void updateFile();

    /**
     * @brief Searchs beach by county and displays its information.
     */
    void searchCounty();

    /**
     * @brief Search beach by name and displays its information.
     */
    void searchName();

    /**
     * @brief Search beach by blue flag and displays its information.
     */
    void searchBlueflag();

    /**
     * @brief Search beach by lifeguard and displays its information.
     */
    void searchLifeguard();

    /**
     * @brief Search beach by closest beach and displays its information.
     */
    void searchClosest();

    /**
     * @brief Displays information about 2 beaches side by side.
     * @param 1st Beach
     * @param 2nd Beach
     */
    void compareBeaches(Beach * b1, Beach * b2);

    /**
     *
     */
    void alterDateofInspection();

    /**
    *
    */
    void closeService();

    /**
     *
     */
    void reopenService();

    void updateCloseServicesFile();

};

#endif //AEDA_COMPANY_H
