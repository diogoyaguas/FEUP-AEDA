#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"
#include <iomanip>
#include <math.h>
#include <set>



typedef struct{
    InterestPoint InterestP; ///< Point of Interest
    string date; ///< Closing date
    string type_of_closing; ///< Type of closing
} struct_pointsShutDown;

struct sort_pointsShutDown {

    int operator()(const struct_pointsShutDown & f1) {
        return 0;
    }

    bool operator () (const struct_pointsShutDown & p1, const struct_pointsShutDown & p2)  const{

        if (stoi(p1.date.substr(6,4)) != stoi(p2.date.substr(6,4))) return stoi(p1.date.substr(6,4)) < stoi(p2.date.substr(6,4));
        else {

            if (stoi(p1.date.substr(3,2)) != stoi(p2.date.substr(3,2))) return stoi(p1.date.substr(3,2)) != stoi(p2.date.substr(3,2));
            else {

                if( stoi(p1.date.substr(0,2)) != stoi(p2.date.substr(0,2)))
                    return stoi(p1.date.substr(0,2)) < stoi(p2.date.substr(0,2));
                else return true;
            }
        }
    }
};

typedef unordered_set<struct_pointsShutDown, sort_pointsShutDown, sort_pointsShutDown> HashTable_points;

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
    vector <priority_queue<InterestPoint>> PointsOfInterest;
    HashTable_points PointOfInterest_Closed;
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
     * @brief Alter the date of inspection of a service.
     */
    void alterDateofInspection();

    /**
    * @brief Close a service, permanently or temporarily, on a specific date.
    */
    void closeService();

    /**
     * @brief Reopen a service closed temporarily.
     */
    void reopenService();

    /**
     * @brief Update the closed services .txt file.
     */
    void updateClosedServicesFile();

    /**
     * @brief Read the closed service .txt file.
     */
    void readClosedServicesFile();

    /**
     * @brief Display all the closed services of a specific beach.
     */
    void displayClosedServices();

    /**
     * @brief Reopen a service closed temporarily that don't belong to any beach.
     */
    void reopenClosedPoints();

    /**
     * @brief Close a service, permanently or temporarily, on a specific date, that don't belong to any beach.
     */
    void closePoint();

    /**
     * @brief Remove a closed point of interest from the hash table.
     * @param name
     */
    void removePointDown(string name);

    /**
     * @brief Reads the interest points .txt file.
     */
    void readInterestPointsFile();

    /**
     * @brief Reads the closed interest point .txt file.
     */
    void readClosedInterestPointsFile();

    /**
     * @brief Update the closed interest points .txt file.
     */
    void updateClosedInterestPointsFile();

    /**
     * @brief Update the interest points .txt file.
     */
    void updateInterestPointsFile();

    /**
     * @brief Erase a point of interest from the vector.
     * @param service
     */
    void erase_InterestPoints(InterestPoint point);

    /**
     * @brief Add a point of interest to the vector.
     * @param service
     */
    void add_InterestPoints(InterestPoint point);

    /**
     * @brief Close a point of interest, permanently or temporarily, on a specific date.
     * @param point
     * @param date
     * @param type_of_closing
     */
    void add_ClosedPoint(InterestPoint point, string date, string type_of_closing);
};

#endif //AEDA_COMPANY_H
