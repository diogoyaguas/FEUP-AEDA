#ifndef AEDA_SERVICES_H
#define AEDA_SERVICES_H

#include <iostream>

using namespace std;

class Services {
    string type; // Restaurant, Bar, Hotel, Renting, PointsOfInterest
    string name, priceRange, stars, dateInspection;

public:
    /**
     * @brief Constructor class Services.
     * @param type
     * @param name
     * @param priceRange
     * @param stars
     * @param dateInspection
     */
    Services(string type, string name, string priceRange, string stars, string dateInspection);

    /**
     * @brief Helper construtor for class Services which creates an object from information in file.
     * @param string containing service attributes separated by collumns
     */
    Services(string service);

    /**
     * @brief Alternative constructor
     */
    Services();

    /**
     * @return type
     */
    string getType() { return type; }

    /**
     * @return name
     */
    string getName() { return name; }

    /**
     * @return price range
     */
    string getPriceRange() { return priceRange; }

    /**
     * @return stars
     */
    string getStars() { return stars; }

    /**
     *
     * @return dateInspection
     */
    string getDateInspection() { return dateInspection; }

    string getYearInspection() const {
        string s1 = dateInspection.substr(dateInspection.find_last_of('-', 0), 4);
        return s1;
    }

    string getMonthInspection() const {
        string s1 = dateInspection.substr(dateInspection.find_first_of('-', 0), 2);
        return s1;
    }

    string getDayInspection() const {
        string s1 = dateInspection.substr(0, 2);
        return s1;
    }

    /**
     * Changes type.
     * @param type
     */
    void setType(string type) { this->type = type; }

    /**
     * Changes name.
     * @param name
     */
    void setName(string name) { this->name = name; }

    /**
     * Changes price range.
     * @param price
     */
    void setPriceRange(string price) { this->priceRange = price; }

    /**
     * Changes stars.
     * @param stars
     */
    void setStars(string stars) { this->stars = stars; }

    bool operator<(const Services &s1) const {

        if (getYearInspection() < s1.getYearInspection()) return true;
        else if (getYearInspection() == s1.getYearInspection()) {

            if (getMonthInspection() < s1.getMonthInspection()) return true;
            else if (getMonthInspection() == s1.getMonthInspection()) {

                if (getDayInspection() < s1.getDayInspection()) return true;
                else return false;
            }
        }
        return false;
    }
};

#endif //AEDA_SERVICES_H
