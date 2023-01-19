#pragma once
#include<iostream>
#include<fstream>
#include "Eveniment.h"
using namespace std;
class Film :
    public Eveniment
{
    int locuri[5][5] = { {0} };
public:
    friend ostream& operator<<(ostream& , Film );
    friend ofstream& operator<<(ofstream& , Film );
    friend istream& operator>>(istream&, Film&);
    friend ifstream& operator>>(ifstream&, Film& f);
    int getLoc(int,int);
    void setLoc(int,int,int);

};

