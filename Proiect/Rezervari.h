#pragma once
#include<iostream>
#include<string>
#include"Eveniment.h"
#include"Clienti.h"
#include"cumparaBilet.h"
using namespace std;

class Rezervari
{
private:
	int* locuriRezervate;
	int nrlocuriRezervate;
	Eveniment eveniment;
	Clienti client;
public:

	Rezervari() {
		locuriRezervate = nullptr;
		nrlocuriRezervate = 0;
	}

	Rezervari( int* locuriRezervate, int nrlocuriRezervate,Clienti& client, Eveniment& eveniment) {
		if (locuriRezervate != nullptr && nrlocuriRezervate > 0)
		{
			this->locuriRezervate = new int[nrlocuriRezervate];
			this->nrlocuriRezervate = nrlocuriRezervate;
			for (int i = 0; i < nrlocuriRezervate; i++)
			{
				this->locuriRezervate[i] = locuriRezervate[i];
			}
		}
		else
		{
			this->locuriRezervate = nullptr;
			this->nrlocuriRezervate = 0;
		}
		this->eveniment = eveniment;
		this->client = client;
		
	}

	Rezervari(const Rezervari& r) {
		if (r.locuriRezervate != nullptr && r.nrlocuriRezervate > 0) {
			this->nrlocuriRezervate = r.nrlocuriRezervate;
			this->locuriRezervate = new int[r.nrlocuriRezervate];
			for (int i = 0; i < r.nrlocuriRezervate; i++) {
				this->locuriRezervate[i] = r.locuriRezervate[i];
			}

		}
		else {
			this->locuriRezervate = nullptr;
			this->nrlocuriRezervate = 0;
		}
		this->eveniment = r.eveniment;
		this->client = r.client;
	}

	~Rezervari() {
		if (locuriRezervate != nullptr) {
			delete[]locuriRezervate;
			locuriRezervate = nullptr;
		}
	}

	int* getlocuriRezervate();
	int getnrlocuriRezervate();
	Eveniment getEveniment();
	Clienti getClient();
	void setlocuriRezervate(int*, int);
	void setEveniment(Eveniment);
	void setClient(Clienti);
	int getRand(int);
	int getLoc(int);


	Rezervari& operator=(const Rezervari&);
	bool operator==(Rezervari);
	bool operator!();


	friend ostream& operator<<(ostream& out, Rezervari r);
	friend istream& operator>>(istream& in, Rezervari& r);

	virtual float pretTotal();
	virtual void oferta();
	friend class cumparaBilet;
	
};

