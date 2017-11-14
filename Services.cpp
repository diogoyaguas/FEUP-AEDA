//
// Created by Beatriz Mendes on 06/11/2017.
//

#include "Services.h"

Services::Services(string type, string name, string priceRange, string stars)
:type(type), name(name), priceRange(priceRange), stars(stars)
{}

Services::Services(){}

Services::Services(string service){

    unsigned long last;
    unsigned long stop;

    //attribute type
    stop= service.find_first_of(';');
    this->type = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the begining of the char after space
    stop = service.find_first_of(';');
    this->name = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the begining of the char after space
    stop = service.find_first_of(';');
    this->priceRange = service.substr(0,stop);

    service = service.substr(stop+2); // +2 marks the begining of the char after space
    stop = service.find_first_of(';');
    this->stars = service.substr(0,stop);

}