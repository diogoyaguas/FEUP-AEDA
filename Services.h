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
    string getType() const { return type; }

    /**
     * @return name
     */
    string getName() const { return name; }

    /**
     * @return price range
     */
    string getPriceRange() const { return priceRange; }

    /**
     * @return stars
     */
    string getStars() const { return stars; }

    /**
     * @return dateInspection
     */
    string getDateInspection() const { return dateInspection; }

    /**
     * @return year of inspection
     */
    int getYearInspection() const {
        string s1 = dateInspection.substr(6, 4);
        return stoi(s1);
    }

    /**
     * @return month of inspection
     */
    int getMonthInspection() const {
        string s1 = dateInspection.substr(3, 2);
        return stoi(s1);
    }

    /**
     * @return day of inspection
     */
    int getDayInspection() const {
        string s1 = dateInspection.substr(0, 2);
        return stoi(s1);
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

    /**
     * @brief Write service information on .txt file.
     * @param file
     */
    virtual void writeService(ofstream &file) const;
};

class InterestPoint :  public Services {
    float lat;
    float longi;

public:
    InterestPoint(Services service, float lat, float longi);
    float getLatitude() const {return lat;}
    float getLongitude() const {return longi;}
    void writeService(ofstream &file) const;
};

#endif //AEDA_SERVICES_H
