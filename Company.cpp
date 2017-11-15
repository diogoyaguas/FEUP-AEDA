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


void Company::addBeach(){
    string type, county, name, utility;
    bool lifeguard, blueflag;
    unsigned long max_capacity;
    float LAT ,LONG,  width, maxDepth, aquaticArea;
    vector<string> basicServices;
    int utilities, counter=0, services;
    string sType, sName, sPriceRange, sStars;


    cout << "Insert type (Bayou or River): ";
    cin >> type;
    cout << endl << "Insert county (eg: Arcos de Valdevez): ";
    cin >> county;
    cout <<  endl <<"Insert name: " << endl;
    cin >> name;
    cout <<  endl <<"Insert 1 if contains blueflag, 0 otherwise: ";
    cin >> blueflag;
    cout <<  endl <<"Insert 1 if contains lifeguard, 0 otherwise: ";
    cin >> lifeguard;
    cout <<  endl <<"Insert maximum capacity (eg: 1000): ";
    cin >> max_capacity;
    cout <<  endl <<"Insert latitude and longitude coordinates separated by a space (eg: 40.268799 -7.143181): " << endl;
    cin >> LAT >> LONG;


    if(type=="River"){
        cout <<  endl <<"Insert width in meters (eg: 72): " << endl;
        cin >> width;
        cout <<  endl << "Insert depth in meters (eg: 12): " << endl;
        cin >> maxDepth;
        Beaches.push_back(new RiverBeach(county, name, blueflag, lifeguard, max_capacity, LAT, LONG, width, maxDepth));
    }

    if(type=="Bayou") {
        cout << endl << "Insert width in meters (eg: 1150500000): " << endl;
        cin >> aquaticArea;
        (new BayouBeach(county, name, blueflag, lifeguard, max_capacity, LAT, LONG, aquaticArea));
    }



    cout <<  endl <<"How many basic utilities does the beach have? (eg: wc, showers...): ";
    while(counter<utilities){
        cout <<  endl <<counter++ << "st utility: ";
        cin >> utility;
        Beaches.at(Beaches.size()-1)->getBasicServices().push_back(utility);
        counter++;

    }

    cout << endl << "How many services does the beach have? (eg, Hotel, Bar): ";
    cin >> services;
    counter=0;
    while (counter < services){
        cout <<  endl <<counter++ << "st service: ";
        cout <<  endl << "Type (eg: Hotel, Bar): ";
        cin >> sType;
        cout << endl << "Name (eg: Tapada Grande): ";
        cin >> sName;
        cout << endl << "Price Range (eg: 1/3): ";
        cin >> sPriceRange;
        cout << endl << "Stars (eg: **): ";
        cin >> sStars;
        Beaches.at(Beaches.size()-1)->getExtraServices().push_back(Services(sType, sName, sPriceRange, sStars));
    }
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







void Company::removeBeach(){
    string name;

    cout << "Insert beach name: ";
    cin >> name;

    for (int i = 0; i < Beaches.size(); ++i) {
        if(Beaches.at(i)->get_name()==name) {
            Beaches.erase(Beaches.begin() + Beaches.size());
        }

    }

    cout << "There is no beach with the given name.";
}


void Company::updateFile(){}

void Company::alterBeachInfo(){

}