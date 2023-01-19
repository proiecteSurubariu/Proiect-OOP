#pragma once
#include<iostream>
#include<string.h>
#include"Clienti.h"
#include"Eveniment.h"
#include"Rezervari.h"
#include"Film.h"
#include<fstream>

using namespace std;
class cumparaBilet
{


public:
	void menu();
	void cumparator();
	void evenimente();
	void cumparare();
	Film citireFilm();
	void scriereFilm(Film f);
	

};

