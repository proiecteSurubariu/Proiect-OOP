#include "Clienti.h"
#include<iostream>

int Clienti::contorNumarIdentificare = 1;

Clienti& Clienti::operator=(const Clienti& c) {
	if (this != &c) {
		if (c.numeClient != nullptr) {

			if (this->numeClient != nullptr)
				delete[] this->numeClient;

			this->numeClient = new char[strlen(c.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
		}

		if (c.prenumeClient != nullptr) {
			if (this->prenumeClient != nullptr)
				delete[]this->prenumeClient;
			this->prenumeClient = new char[strlen(c.prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(c.prenumeClient) + 1, c.prenumeClient);
		}

		if (strlen(c.nrDeTelefonClient) == 10)
			strcpy_s(this->nrDeTelefonClient, 11, c.nrDeTelefonClient);


		if (c.rezervari != nullptr && c.nrRezervari > 0) {
			if (rezervari != nullptr) {
				delete[]this->rezervari;
			}
			this->nrRezervari = c.nrRezervari;
			this->rezervari = new Rezervari[c.nrRezervari];
			for (int i = 0; i < c.nrRezervari; i++) {
				this->rezervari[i] = c.rezervari[i];
			}

		}

	}
	return *this;
}
float Clienti::operator+(Clienti c) {

	return this->sumaTotalaDePlata() + c.sumaTotalaDePlata();
}
Clienti:: operator string() {
	string nume = numeClient;
	nume = nume + " " + prenumeClient;
	return nume;
}



ostream& operator<<(ostream& out, Clienti c) {
	cout << endl << "Numar de identificare client: ";
	out << c.numarIdentificareClient;
	cout << endl << "Nume client: ";
	if (c.numeClient != nullptr)out << c.numeClient;
	else cout << "Nume invalid"<<endl;
	cout << endl << "Prenume client: ";
	if (c.prenumeClient != nullptr)
		out << c.prenumeClient;
	else cout << "Prenume invalid";
	cout << endl << "Numar de telefon client: ";
	if (c.nrDeTelefonClient != nullptr)out << c.nrDeTelefonClient;
	else cout << "Numar de telefon invalid";
	if (c.nrRezervari > 0 && c.rezervari != nullptr) {
		cout << endl << "Numarul de rezervari este: ";
		out << c.nrRezervari;
		cout << endl << "Rezervarile sunt: " << endl;
		for (int i = 0; i < c.nrRezervari; i++) {
			out << c.rezervari[i] << " ";
		}
	}
	else {
		cout << endl << "Clientul nu are nicio rezervare." << endl;
	}
	cout << endl;
	return out;

}
istream& operator>>(istream& in, Clienti& c)
{
	cout << endl << "Nume: ";
		string nume;
		cin >> nume;
		if (nume.length() > 0) {
			if (c.numeClient != nullptr) {
				delete[]c.numeClient;
			}
			c.numeClient = new char[nume.length() + 1];
			strcpy_s(c.numeClient, nume.length() + 1, nume.c_str());
		}
		else cout << "Numele introdus nu e valid"<<endl;
	

	cout << endl << "Prenume: ";
	
	cin >> nume;
	if (nume.length() > 0) {
		if (c.prenumeClient != nullptr) {
			delete[]c.prenumeClient;
		}
		c.prenumeClient = new char[nume.length() + 1];
		strcpy_s(c.prenumeClient, nume.length() + 1, nume.c_str());
	}
	else cout << "Prenumele introdus nu e valid" << endl;



	cout << endl << "Numar de telefon : ";
	string x;
	cin >> x;
	if (x.length() == 10) {
		strcpy_s(c.nrDeTelefonClient, 11, x.c_str());
	}
	else cout << "Numar de telefon invalid.";


	int a;
	cout << "Numarul de  rezervari: " << endl;
	cin >> a;
	if (a < 1) {
		cout << "Numar invalid.";
		c.nrRezervari = 0;
	}
	else c.nrRezervari = a;

	if (c.nrRezervari > 0) {
		if (c.rezervari != nullptr) {
			delete[]c.rezervari;
		}

		c.rezervari = new Rezervari[c.nrRezervari];
		cout << "Locurile rezervate: " << endl;
		for (int i = 0; i < c.nrRezervari; i++) {
			in >> c.rezervari[i];
			cout << " ";
		}
	}
	else c.rezervari = nullptr;
	return in;
}


const char* Clienti::getNumeClient() {

	if (numeClient != nullptr) {
		char* copy = new char[strlen(numeClient) + 1];
		strcpy_s(copy, strlen(numeClient) + 1, numeClient);
		return copy;

	}
	else {
		char* message = new char[35];
		strcpy_s(message, 35, "Clientul accesat nu este valid");
		return message;
	}
}
const char* Clienti::getPrenumeClient() {

	if (prenumeClient != nullptr) {
		char* copy = new char[strlen(prenumeClient) + 1];
		strcpy_s(copy, strlen(prenumeClient) + 1, prenumeClient);
		return copy;

	}
	else {
		char* message = new char[35];
		strcpy_s(message, 35, "Clientul accesat nu este valid");
		return message;
	}
}
const char* Clienti::getNrDeTelefonClient() {

	if (nrDeTelefonClient != nullptr) {
		char* copy = new char[11];
		strcpy_s(copy, 11, nrDeTelefonClient);
		return copy;
	}
	else cout << "Numarul de telefon nu exista"<<endl;
	
}
Rezervari* Clienti::getRezervari()
{
	if (rezervari != nullptr && nrRezervari > 0) {

		Rezervari* copy = new Rezervari[nrRezervari];
		for (int i = 0; i < nrRezervari; i++)
		{
			copy[i] = rezervari[i];
		}
		return copy;
	}
	else cout << "Nu exista rezervari";
}
int Clienti::getNrRezervari()
{
	return nrRezervari;
}
int Clienti::getNumarIdentificareClient()
{
	return numarIdentificareClient;

}
int Clienti::getContor()
{
	return Clienti::contorNumarIdentificare;
}



void Clienti::setNumeClient(const char* numeClient) {
	if (numeClient != nullptr) {
		delete[]this->numeClient;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);

	}
	else cout << "Nume invalid." << endl;
}
void Clienti::setPrenumeClient(char* prenumeClient) {
	if (prenumeClient != nullptr) {
		delete[]this->prenumeClient;
		this->prenumeClient = new char[strlen(prenumeClient) + 1];
		strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
	}
	else cout << "Prenume invalid." << endl;
}
void Clienti::setNrDeTelefonClient(char nrDeTelefonClient[11]) {
	if (nrDeTelefonClient != nullptr) {
		strcpy_s(this->nrDeTelefonClient, strlen(nrDeTelefonClient) + 1, nrDeTelefonClient);
	}
	else cout << "Nr de telefon invalid." << endl;
	
}
void Clienti::setRezervari(Rezervari* r, int nr)
{
	if (r != nullptr && nr > 0)
	{
		if (this->rezervari != nullptr)
		{
			delete[] this->rezervari;
		}
		this->rezervari = new Rezervari[nr];
		for (int i = 0; i < nr; i++)
		{
			this->rezervari[i] = r[i];
		}

		this->nrRezervari = nr;
	}
	else cout << "Datele sunt invalide." << endl;

}


float Clienti::sumaTotalaDePlata() {
	float suma = 0;
	for (int i = 0; i < nrRezervari; i++) {
		suma += rezervari[i].pretTotal() * rezervari[i].getnrlocuriRezervate();
	}

	return suma;
}

float Clienti::sumaTotalaClienti(Clienti* c, int nrc) {
	float suma = 0;
	for (int i = 0; i < nrc; i++) {
		suma += c[i].sumaTotalaDePlata();
	}
	return suma;
}

float Clienti::discount(int x, int index) {
	float discount = 0;

	if (x > 1 && x < 90) {
		if (index < nrRezervari && index>0) {
			discount = rezervari[index - 1].pretTotal() - (rezervari[index - 1].pretTotal() * x / 100);
			return discount;
		}
		else throw exception("Index invalid");


	}
	else
		throw exception("Nu se poate acorda discountul.");

}