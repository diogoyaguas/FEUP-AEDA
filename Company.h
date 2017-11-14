#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"

class Company {
private:
    vector<Beach *> Beaches;
public:
    Company();
    vector<Beach *> getBeaches();
};


#endif //AEDA_COMPANY_H
