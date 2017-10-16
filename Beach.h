//
// Created by Beatriz Mendes on 16/10/2017.
//

#ifndef AEDA_BEACH_H
#define AEDA_BEACH_H


class Beach {
private:
    bool blue_flag, lifeguard;
    unsigned int max_capacity;
    struct GPS_coordinates{
        unsigned float LAT, LONG;
    };


protected:
    bool get_blue_flag();
    bool get_lifeguard();
    unsigned int get_max_capacity();
    float get_Latitude();
    float get_Longitude();
};


#endif //AEDA_BEACH_H
