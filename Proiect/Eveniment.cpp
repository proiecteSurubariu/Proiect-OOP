#include "Eveniment.h"
#include<string>
#include<iostream>



Eveniment& Eveniment:: operator=(const Eveniment& Eveniment) {
	this->numeEveniment = Eveniment.numeEveniment;
	this->locatie = Eveniment.locatie;
	this->pret = Eveniment.pret;
	this->data = Eveniment.data;
	this->ora = Eveniment.ora;
	return *this;
}
Eveniment& Eveniment::operator++() {
	
	this->pret=this->pret+1;
	return *this;
 }
Eveniment Eveniment :: operator++(int x)
{
	this->pret++;
	Eveniment e = *this;
	return e;

}
bool Eveniment::operator<(Eveniment e) {
	if (this->pret < e.pret) return 1;
	return 0;
}
bool Eveniment::operator>(Eveniment e) {
	if (this->pret > e.pret) return 1;
	return 0;
}



ostream& operator<<(ostream& out, Eveniment e) {
	cout << endl << "\n\n\t\tNume Eveniment: ";
	out << e.numeEveniment;
	cout << endl << "\n\n\t\tLocatie Eveniment: ";
	out << e.locatie;
	cout << endl << "\n\n\t\tData eveniment: ";
	out << e.data;
	cout << endl << "\n\n\t\tOra eveniment: ";
	out << e.ora;
	cout << endl << "\n\n\t\tPret Eveniment:";
	
	out << e.pret;
	cout << endl;
	return out;
}
istream& operator>>(istream& in, Eveniment& e)
{
	cout << endl << "\n\n\t\tNume Eveniment: ";
	in >> e.numeEveniment;
	cout << endl << "\n\n\t\tLocatie Eveniment: ";
	in >> e.locatie;
	cout << endl << "\n\n\t\tData Eveniment: ";
	in >> e.data;
	cout << endl << "\n\n\t\tOra Eveniment: ";
	in >> e.ora;
	cout << endl << "\n\n\t\tPret Eveniment: "<<endl;
	float pr=0;
	
	do  {
		cin >> pr;
		if (pr < 1)cout << "\n\n\t\tPret invalid. Introduceti alt pret." << endl;
	} while (pr < 1);
	e.pret = pr;
	
	cout << endl;
	return in;
}


string Eveniment::getNumeEveniment() {
	return numeEveniment;
}
string Eveniment::getLocatieEveniment() {
	return locatie;
}
string Eveniment::getDataEveniment() {
	return data;
}
string Eveniment::getOraEveniment() {
	return ora;
}
float Eveniment::getPretEveniment() {
	return pret;
}


void Eveniment::setNumeEveniment(string numeEveniment) {
	if (numeEveniment.length() > 0) {
		this->numeEveniment = numeEveniment;
	}

	else {
		cout << endl << "\n\n\t\tNumele evenimentului introdus nu este valid" << endl;
	}

}
void Eveniment::setLocatieEveniment(string locatie) {
	if (locatie.length() > 0) {
		this->locatie = locatie;
	}
	else {
		cout << endl << "\n\n\t\tLocatia evenimentului introdus nu este valida" << endl;
	}
	
}
void Eveniment::setDataEveniment(string data) {
	if (data.length()==10) {
		this->data = data;
		
	}
	else cout << endl << "\n\n\t\tData evenimentului nu e valida" << endl;
}
void Eveniment::setOraEveniment(string ora) {
	if (ora.length() ==5) {
		this->ora = ora;
	}
	else cout << endl << "\n\n\t\tOra introdusa nu e valida" << endl;
}
void Eveniment::setPretEveniment(float pret) {
	if (pret>0) { this->pret = pret; }
	else {
		cout << endl << "\n\n\t\tPretul introdus nu este valid" << endl;
	}
}


bool Eveniment::verificareLocatie(string locatie) {
	return (locatie == this->locatie);

}
float Eveniment::pretCinemarti() {
	float pretf = pret - pret * 0.2;
	return pretf;
}



