//
// Created by george on 2019-11-13.
//
#include <iostream>


using namespace std;

#ifndef TOLYC_FACER_H
#define TOLYC_FACER_H

class Facer {
public:
    Facer(const string &top="#", const string &bottom="#", const string &brow="~", const string &eyes=".");
    ~Facer();
public:
    string top;
    string bottom;
    string brow;
    string eyes;
public:
    void printFace() ;
    string getFace();
};


#endif //TOLYC_FACER_H
