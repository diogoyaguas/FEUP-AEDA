#ifndef AEDA_COMPANY_H
#define AEDA_COMPANY_H

#include "Beach.h"

class Company {
private:
    vector<Beach *> Beaches;
public:
    Company();
    vector<Beach *> getBeaches();
    void quickSort(vector<Beach *> &v);
    void  quickSort(vector<Beach *> &v,unsigned int left,unsigned int right);
    const unsigned int &median3(vector<Beach *> &v, unsigned int left, unsigned int right);
};

template <class T>
void swap ( T& a, T& b )
{
    T c(a); a=b; b=c;
}

#endif //AEDA_COMPANY_H
