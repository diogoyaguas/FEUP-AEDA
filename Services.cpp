#include "Services.h"
#include <fstream>
#include <iomanip>

Services::Services(string type, string name, string priceRange, string stars, string dateInspection)
:type(type), name(name), priceRange(priceRange), stars(stars), dateInspection(dateInspection)
{}

Services::Services(){}

Services::Services(string service){

    unsigned long last;
    unsigned long stop;

    //attribute type
    stop= service.find_first_of(',');
    this->type = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the begining of the char after space
    stop = service.find_first_of(',');
    this->name = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the begining of the char after space
    stop = service.find_first_of(',');
    this->priceRange = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the begining of the char after space
    stop = service.find_first_of(',');
    this->stars = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the beginig of the char after spaces
    stop = service.find_first_of(',');
    this->dateInspection = service.substr(0,stop);

}


void Services::displayService() const {

    cout << setw(15) << setfill(' ') << "Type: " << this->getType() << endl;
    cout << setw(15) << setfill(' ') << "Name: " << this->getName() << endl;
    cout << setw(22) << setfill(' ') << "Price Range: " << this->getPriceRange() << endl;
    cout << setw(16) << setfill(' ') << "Stars: " << this->getStars() << endl;
    cout << setw(15) << setfill(' ') << "Date: " << this->getDateInspection() << endl << endl;

}
void Services::writeService(ofstream &file) const {

    if(!this->type.empty()) {
        file << this->type << ", ";
        file << this->name << ", ";
        file << this->priceRange << ", ";
        file << this->stars << ", ";
        file << this->dateInspection << ";";
    }
}


//

InterestPoint::InterestPoint() {}

InterestPoint::InterestPoint(Services service, float lat, float longi)
:Services(service.getType(), service.getName(), service.getPriceRange(), service.getStars(), service.getDateInspection()), lat(lat), longi(longi)
{}


void InterestPoint::writeService(ofstream &file) const{
    Services::writeService(file);
    file << " " << this->getLatitude();
    file << "; " << this->getLongitude();
}
