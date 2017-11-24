#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H

#include <string>
#include <vector>
#include "Services.h"
#include <math.h>

using namespace std;

class Beach {
protected:
    string name, county;
    bool blueflag, lifeguard;
    unsigned long max_capacity;
    float lat, longi;
    vector<string> basicServices;
    vector<Services> extraServices;

public:

    /**
     * @brief Constructor for class Beach.
     * @param county
     * @param name
     * @param blueflag
     * @param lifeguard
     * @param max_capacity
     * @param lat
     * @param longi
     * @param basicServices
     */
    Beach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi);

    /**
     * @brief Alternative constructor for class Beach.
     */
    Beach(){};

    // get methods
    /**
     * @return county
     */
    string get_county() const;

    /**
     * @return name
     */
    string get_name() const;
    /**
     * @return 1 if beach contains blue flag, 0 otherwise
     */
    bool get_blue_flag() const;

    /**
     * @return 1 if beach contains lifeguard, 0 otherwise
     */
    bool get_lifeguard() const;

    /**
     * @return maximum capacity
     */
    unsigned long get_max_capacity() const;

    /**
     * @return latitude
     */
    float get_latitude() const;

    /**
     * @return longitude
     */
    float get_longitude() const;

    /**
     * @return width;
     */
    virtual float get_width() const = 0;

    /**
     * @return maximun depth
     */
    virtual float get_maxDepth() const  = 0;

    /**
     * @return aquatic area
     */
    virtual float get_aquaticArea() const = 0;

    /**
     *
     * @return vector of Basic beach services
     */
    vector<string> getBasicServices() const;

    /**
     * @return vector of Extra beach services
     */
    vector<Services> getExtraServices() const;

    /**
     * @brief Helps identifying from which derived class ths object is.
     * @return "BayouBeach" if it's a class BayouBeach object, "RiverBeach" if it's a class RiverBeach object
     */
    virtual string getType() const=0;

    // set methods
    /**
     * @brief Changes name.
     * @param name
     */
    void set_name(string name);

    /**
     * @brief Changes blueflag.
     */
    void set_blue_flag();

    /**
     * @brief Changes lifeguard.
     */
    void set_lifeguard();

    /**
     * @brief Changes maximum capacity.
     * @param maximum capacity
     */
    void set_max_capacity(unsigned long max_capacity);

    /**
     * @brief Changes latitude.
     * @param latitude
     */
    void set_latitude(float lat);

    /**
     * @brief Changes longitude.
     * @param longitude
     */
    void set_longitude(float longi);

    /**
     * @brief Changes extra services.
     * @param extraServices
     */
    void set_ExtraServices(vector<Services> &extraServices);

    /**
     * @brief Changes width.
     * @param width
     */
    virtual void set_width(float width) = 0;

    /**
     * @brief Changes maximum depth.
     * @param maximum depth
     */
    virtual void set_maxDepth(float maxDept) = 0;

    /**
     * @brief Changes aquatic area.
     * @param Aquatic area
     */
    virtual void set_aquaticArea(float aquaticArea) = 0;

    // other functions
    double degreesToRadians(double degrees) {return degrees * M_PI / 180;}

    /**
     * @brief Calculates distance from location's GPS coordinates to beach's coordinates.
     * @param 2nd latitude
     * @param 2nd longitude
     * @return distance
     */
    double distanceToBeach(float lat,float longi);

    /**
     * @brief Displays all information about the beach.
     */
    virtual void displayBeach() = 0;

    /**
     * @brief Adds Basic service to the vector.
     * @param service
     */
    void add_BasicService(string service);

    /**
     * @brief Adds Extra service to the vector.
     * @param service
     */
    void add_ExtraService(Services service);

    /**
     * @brief Erase extra service from the vector.
     * @param service
     */
    void erase_ExtraService(string service);

    /**
     * @brief Writes information about the beach in .txt file.
     * @param file
     */
    virtual void writeBeach(ofstream & file) const = 0;

};

class RiverBeach: public Beach{
    float width, maxDepth;
public:
    /**
     * @brief Constructor for class RiverBeach.
     * @param county
     * @param name
     * @param blueflag
     * @param lifeguard
     * @param max_capacity
     * @param lat
     * @param longi
     * @param width
     * @param maxDepth
     * @param basicServices
     */
    RiverBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi,  float &width, float &maxDepth);
    /**
     * @brief Helper construtor which recognizes and associates Beach's object's given attributes.
     * @param line from txt file representing an object of class beach
     */
    RiverBeach(string beach);

    string getType() const{return "River";};
    float get_width() const{return width;};
    float get_maxDepth() const{return maxDepth;};
    float get_aquaticArea() const{return -1;};

    void set_width(float width){ this->width = width;};
    void set_maxDepth(float maxDept) { this->maxDepth = maxDept;};
    void set_aquaticArea(float aquaticArea) {};

    void displayBeach();
    void writeBeach(ofstream & file) const;
};

class BayouBeach: public Beach{
    float aquaticArea;
public:
    /**
     * @brief Constructor class BayouBeach.
     * @param county
     * @param name
     * @param blueflag
     * @param lifeguard
     * @param max_capacity
     * @param lat
     * @param longi
     * @param aquaticArea
     * @param basicServices
     */
    BayouBeach(string &county, string &name, bool &blueflag, bool &lifeguard, unsigned long &max_capacity, float &lat , float &longi, float &aquaticArea);
    /**
     * @brief Helper construtor which recognizes and associates Beach's object's given attributes.
     * @param line from txt file representing an object of class beach
     */
    BayouBeach(string beach);

    string getType() const{return "Bayou";}
    float get_width() const{return -1;};
    float get_maxDepth() const{return -1;};
    float get_aquaticArea() const{return aquaticArea;};

    void set_width(float width){};
    void set_maxDepth(float maxDept) {};
    void set_aquaticArea(float aquaticArea){this->aquaticArea = aquaticArea;};

    void displayBeach();
    void writeBeach(ofstream & file) const;
};

#endif //AEDA_BEACH_H
