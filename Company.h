#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"

class Company {
private:
    vector<Beach *> Beaches;
public:
    /**
     * Constructor of class Company
     */
    Company();
    /**
     * @return vector Beaches
     */
    vector<Beach *> getBeaches(){return Beaches;}
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
     * @brief verifies if beach with certain name exist
     * @param name
     * @return pos of beach in Beaches' vector if beach with name exists, -1 otherwise
     */
    unsigned int beachExists(string name);
};

template <class T>
void fail (T &value){

    while(cin.fail()){

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid value: ";
        cin >> value;
    }
}


#endif //AEDA_COMPANY_H
