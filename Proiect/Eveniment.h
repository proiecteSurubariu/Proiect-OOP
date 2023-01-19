#pragma once
#include<iostream>
#include <string>

using namespace std;


class Eveniment
{
private:
	string numeEveniment;
	string locatie;
	string data;
	string ora;
	float pret;
	

public:

	Eveniment() {
		numeEveniment = "N/A";
		locatie = "N/A";
		data = "01.01.2001";
		ora = "00:00";
		pret = 0;
	}

	Eveniment(string numeEveniment, string locatie, float pret) :Eveniment() {
		this->numeEveniment = numeEveniment;
		this->locatie = locatie;
		this->pret = pret;
	}
	Eveniment(string numeEveniment, string locatie,string data,string ora, float pret) :Eveniment() {
		this->numeEveniment = numeEveniment;
		this->locatie = locatie;
		this->data = data;
		this->ora = ora;
		this->pret = pret;
	}


	Eveniment(const Eveniment& Eveniment) {
		this->numeEveniment = Eveniment.numeEveniment;
		this->locatie = Eveniment.locatie;
		this->pret = Eveniment.pret;
		this->data = Eveniment.data;
		this->ora = Eveniment.ora;
	}


	~Eveniment() {

	}

	string getNumeEveniment();
	string getLocatieEveniment();
	string getDataEveniment();
	string getOraEveniment();
	float getPretEveniment();

	void setNumeEveniment(string);
	void setLocatieEveniment(string);
	void setDataEveniment(string);
	void setOraEveniment(string);
	void setPretEveniment(float);

	Eveniment& operator=(const Eveniment&);

	friend ostream& operator<<(ostream& out, Eveniment e);
	friend istream& operator>>(istream& in, Eveniment& e);
	friend class Rezervari;

	bool verificareLocatie(string);
	float pretCinemarti();

	Eveniment& operator++();
	Eveniment operator++(int x);
	bool operator<(Eveniment);
	bool operator>(Eveniment);
	friend class cumparaBilet;
};