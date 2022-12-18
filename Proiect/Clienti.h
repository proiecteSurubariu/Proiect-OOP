#pragma once
#include<iostream>
#include<string>
#include"Rezervari.h"
using namespace std;


class Clienti
{
private:
	char* numeClient;
	char* prenumeClient;
	char nrDeTelefonClient[11];
	Rezervari* rezervari;
	int nrRezervari;
	const int numarIdentificareClient;
	static int contorNumarIdentificare;

public:

	Clienti() :numarIdentificareClient(contorNumarIdentificare)
	{
		Clienti::contorNumarIdentificare = Clienti::contorNumarIdentificare + 1;
		numeClient = nullptr;
		prenumeClient = nullptr;
		strcpy_s(nrDeTelefonClient, 11, "0000000000");
		nrRezervari = 0;
		rezervari = nullptr;

	}
	Clienti(const char* numeClient, const char* prenumeClient, const char nrDeTelefonClient[11]) :numarIdentificareClient(contorNumarIdentificare)
	{
		Clienti::contorNumarIdentificare = Clienti::contorNumarIdentificare + 1;
		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		}
		else this->numeClient = nullptr;
		if (prenumeClient != nullptr) {
			this->prenumeClient = new char[strlen(prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
		}
		else this->prenumeClient = nullptr;

		if (strlen(nrDeTelefonClient) == 10) {
			strcpy_s(this->nrDeTelefonClient, 11, nrDeTelefonClient);
		}
		else strcpy_s(this->nrDeTelefonClient, 11, "0000000000");

		this->rezervari = nullptr;
		this->nrRezervari = 0;
	}

	Clienti(const char* numeClient, const char* prenumeClient, const char nrDeTelefonClient[11], Rezervari* rezervari, int nrRezervari) :numarIdentificareClient(contorNumarIdentificare)
	{
		Clienti::contorNumarIdentificare = Clienti::contorNumarIdentificare + 1;
		if (numeClient != nullptr) {
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		}
		else this->numeClient = nullptr;
		if (prenumeClient != nullptr) {
			this->prenumeClient = new char[strlen(prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
		}
		else this->prenumeClient = nullptr;

		if (strlen(nrDeTelefonClient) == 10) {
			strcpy_s(this->nrDeTelefonClient, 11, nrDeTelefonClient);
		}
		else strcpy_s(this->nrDeTelefonClient, 11, "0000000000");

		if (rezervari != nullptr && nrRezervari > 0)
		{
			this->rezervari = new Rezervari[nrRezervari];
			this->nrRezervari = nrRezervari;
			for (int i = 0; i < nrRezervari; i++)
			{
				this->rezervari[i] = rezervari[i];
			}
		}
		else
		{
			this->rezervari = nullptr;
			this->nrRezervari = 0;
		}

	}

	Clienti(const Clienti& c) :numarIdentificareClient(contorNumarIdentificare)

	{
		Clienti::contorNumarIdentificare = Clienti::contorNumarIdentificare + 1;
		if (c.numeClient != nullptr) {
			this->numeClient = new char[strlen(c.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
		}
		else this->numeClient = nullptr;

		if (c.prenumeClient != nullptr) {
			this->prenumeClient = new char[strlen(c.prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(c.prenumeClient) + 1, c.prenumeClient);
		}
		else this->prenumeClient = nullptr;


		if (strlen(c.nrDeTelefonClient) == 10) {
			strcpy_s(this->nrDeTelefonClient, 11, c.nrDeTelefonClient);
		}
		else strcpy_s(this->nrDeTelefonClient, 11, "0000000000");


		if (c.rezervari != nullptr && c.nrRezervari > 0) {
			this->nrRezervari = c.nrRezervari;
			this->rezervari = new Rezervari[c.nrRezervari];
			for (int i = 0; i < c.nrRezervari; i++) {
				this->rezervari[i] = c.rezervari[i];
			}

		}
		else {
			this->rezervari = nullptr;
			this->nrRezervari = 0;
		}
	}


	~Clienti() {
		if (this->numeClient != nullptr) {
			delete[] this->numeClient;
			this->numeClient = nullptr;
		}

		if (this->prenumeClient != nullptr) {
			delete[]this->prenumeClient;
			this->prenumeClient = nullptr;
		}

		if (this->rezervari != nullptr) {
			delete[]this->rezervari;
			this->rezervari = nullptr;
		}
	}

	const char* getNumeClient();
	const char* getPrenumeClient();
	const char* getNrDeTelefonClient();
	Rezervari* getRezervari();
	int getNrRezervari();
	int getNumarIdentificareClient();
	static int getContor();


	void setNumeClient(const char*);
	void setPrenumeClient(char*);
	void setNrDeTelefonClient(char[11]);
	void setRezervari(Rezervari*, int);
	void setNrRezervari(int);
	

	float sumaTotalaDePlata();
	float discount(int,int);

	static float sumaTotalaClienti(Clienti*,int);

	Clienti& operator=(const Clienti&);
	float operator+(Clienti);
	explicit operator string();
	

	friend ostream& operator<<(ostream& out, Clienti c);
	friend istream& operator>>(istream& in, Clienti& c);
	
	
};


