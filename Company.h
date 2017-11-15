#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"

class Company {
private:
    vector<Beach *> Beaches;
public:
    Company();
    vector<Beach *> getBeaches(){return Beaches;}
    void addBeach();
    void removeBeach();
    void alterRBeachInfo(unsigned int option, unsigned int i);

    unsigned int beachExists(string name);
};


#endif //AEDA_COMPANY_H
