#include "Rezervari.h"
#include<iostream>

Rezervari& Rezervari::operator=(const Rezervari& r) {
	if (this != &r) {

		if (r.locuriRezervate != nullptr && r.nrlocuriRezervate > 0) {
			this->nrlocuriRezervate = r.nrlocuriRezervate;
			this->locuriRezervate = new int[r.nrlocuriRezervate];
			for (int i = 0; i < r.nrlocuriRezervate; i++) {
				this->locuriRezervate[i] = r.locuriRezervate[i];
			}

		}

		this->eveniment = r.eveniment;
		this->client = r.client;
	}

	return *this;

}
bool Rezervari::operator==(Rezervari r) {
	if (this->nrlocuriRezervate == r.nrlocuriRezervate) return true;
	return false;
}
bool Rezervari::operator!() {
	return nrlocuriRezervate <= 0;
}


ostream& operator<<(ostream& out, Rezervari r) {

	if (r.nrlocuriRezervate > 0 && r.locuriRezervate != nullptr) {
		cout << endl << "\n\n\t\tNumarul de locuri rezervate: ";
		out << r.nrlocuriRezervate;
		cout << endl << "\n\n\t\tLocurile rezervate sunt: ";
		for (int i = 0; i < r.nrlocuriRezervate; i++) {
			out << r.locuriRezervate[i] << " ";
		}
	}
	else cout << endl << "\n\n\t\tNu exista locuri rezervate";
	cout << endl;
	cout << "\n\n\t\tEvenimentul este: ";
	out << r.eveniment;
	cout << endl;

	cout << "\n\n\t\tClientul este: ";
	out << r.client;
	cout << endl;
	return out;

}
istream& operator>>(istream& in, Rezervari& r) {
	
	
	int x = 0;
	int rand;
	int loc;
	cout << "\n\n\t\tAlegeti cate locuri doriti sa rezervati: " << endl;
	cout << endl << "\n\n\t\t";
	cin >> x;
	if (x < 1)cout << "\n\n\t\tNumar invalid.";
	else r.nrlocuriRezervate = x;

	if (r.nrlocuriRezervate > 0) {
		if (r.locuriRezervate != nullptr) {
			delete[]r.locuriRezervate;
		}

		r.locuriRezervate = new int[r.nrlocuriRezervate];
		cout << "\n\n\t\tLocurile rezervate: " << endl;
		for (int i = 0; i < r.nrlocuriRezervate; i++) {
			cout << endl << "\n\n\t\tRand: ";
			
			cin >> rand;
			cout << endl << "\n\n\t\tLoc: ";
			
			cin >> loc;
			cout << endl << "\n\n\t\t";
			 r.locuriRezervate[i]=rand*10+loc;
			 
			cout << " ";
		}
	}
	else r.locuriRezervate = nullptr;
	return in;
}


int* Rezervari::getlocuriRezervate() {
	int* copy = new int[nrlocuriRezervate];
	for (int i = 0; i < nrlocuriRezervate; i++) {
		copy[i] = locuriRezervate[i];
	}
	return copy;
}
int Rezervari::getnrlocuriRezervate() {
	int copy = 0;
	copy = nrlocuriRezervate;
	return copy;
}
Eveniment Rezervari::getEveniment() {
	Eveniment copy = eveniment;
	return copy;
}
Clienti Rezervari::getClient() {
	Clienti copy = client;
	return copy;
}
int Rezervari::getRand(int i) {
	return locuriRezervate[i] / 10 - 1;
}
int Rezervari::getLoc(int i) {
	return locuriRezervate[i] % 10 - 1;
}


void Rezervari::setlocuriRezervate(int* locuriRezervate, int nrlocuriRezervate) {
	if (locuriRezervate != nullptr && nrlocuriRezervate > 0) {
		if (this->locuriRezervate != nullptr) {
			delete[] this->locuriRezervate;
		}
		this->nrlocuriRezervate = nrlocuriRezervate;
		this->locuriRezervate = new int[nrlocuriRezervate];
		for (int i = 0; i < nrlocuriRezervate; i++) {
			this->locuriRezervate[i] = locuriRezervate[i];
		}

	}
	else {
		cout << endl;
		cout << "\n\n\t\tDatele introduse sunt invalide" << endl;
	}

}
void Rezervari::setEveniment(Eveniment e) {
	if (e.getLocatieEveniment().length() > 0 && e.getNumeEveniment().length() > 0 && e.getPretEveniment() > 0 &&e.getDataEveniment().length()==10 && e.getOraEveniment().length()==5) {
		this->eveniment = e;
	}
	else {
		cout << endl << "\n\n\t\tEvenimentul nu este valid." << endl;
	}
}

void Rezervari::setClient(Clienti e) {
	if (strlen(e.getNumeClient()) > 1 && strlen(e.getPrenumeClient()) > 1 && strlen(e.getNrDeTelefonClient()) == 10  ) {
		this->client = e;
	}
	else {
		cout << endl << "\n\n\t\tClientul nu este valid." << endl;
	}
}


float Rezervari::pretTotal()
{
	float pret = 0;
	pret = nrlocuriRezervate * eveniment.getPretEveniment();
	return pret;
}
void Rezervari::oferta()
{
	if (nrlocuriRezervate > 9) eveniment.setPretEveniment(eveniment.getPretEveniment() * 0.9);
}


