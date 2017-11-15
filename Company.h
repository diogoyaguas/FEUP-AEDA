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
    void alterBeachInfo();
};

template <class T>
void swap ( T& a, T& b )
{
    T c(a); a=b; b=c;
}

#endif //AEDA_COMPANY_H
