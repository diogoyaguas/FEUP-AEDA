#include "Company.h"
#include <fstream>

Company::Company() {
    string fileBeach = "BeachFile.txt";
    ifstream file;
    string beach, type;
    unsigned long stop;

    //verify file is successfully opened

    file.open(fileBeach);

    if(!file.is_open()){
        cout << "Error in opening file. Exiting program...";
        exit(1);

    }

    while (getline(file, beach))
    {
        stop = beach.find_first_of(';');
        type = beach.substr(0, stop);


        if (type == "rio") {

            Beaches.push_back(new RiverBeach(beach.substr(stop + 2)));
        }

        else if (type == "albufeira") {

            Beaches.push_back(new BayouBeach(beach.substr(stop + 2)));
        }
    }
}

vector<Beach *> Company::getBeaches(){
    return Beaches;
}

const unsigned int &Company::median3(vector<Beach *> &v, unsigned int left, unsigned int right)
{
    unsigned int center = (left+right) /2;

    if (v.at(center)->get_max_capacity() < v.at(left)->get_max_capacity())
        swap(v.at(left)->get_max_capacity(), v.at(center)->get_max_capacity());

    if (v.at(right)->get_max_capacity() < v.at(left)->get_max_capacity())
        swap(v.at(left)->get_max_capacity(), v.at(right)->get_max_capacity());

    if (v.at(right)->get_max_capacity() < v.at(center)->get_max_capacity())
        swap(v.at(center)->get_max_capacity(), v.at(right)->get_max_capacity());


    //place pivot in position right-1
    swap(v.at(center-1)->get_max_capacity(), v.at(right-1)->get_max_capacity());
    return v.at(right-1)->get_max_capacity();
}

void Company::quickSort(vector<Beach *> &v){

    quickSort(v,0,v.size()-1);
}

void Company::quickSort(vector<Beach *> &v, unsigned int left, unsigned int right)
{
        int x = median3(v,left,right); // x is the new pivot
        int i = left; int j = right-1; // passo de partição
        for(; ; ) {
            while (v.at(++i)->get_max_capacity() < x) ;
            while (x < v.at(--j)->get_max_capacity()) ;
            if (i < j)
                swap(v.at(i), v.at(j));
            else break;
        }
        swap(v.at(i)->get_max_capacity(), v.at(right-1)->get_max_capacity()); //restores pivot
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);

}




