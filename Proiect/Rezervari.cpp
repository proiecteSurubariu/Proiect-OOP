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
		cout << endl << "Numarul de locuri rezervate: ";
		out << r.nrlocuriRezervate;
		cout << endl << "Locurile rezervate sunt: ";
		for (int i = 0; i < r.nrlocuriRezervate; i++) {
			out << r.locuriRezervate[i] << " ";
		}
	}
	else cout << endl << "Nu exista locuri rezervate";
	cout << endl;
	cout << "Evenimentul este: ";
	out << r.eveniment;
	cout << endl;
	return out;

}
istream& operator>>(istream& in, Rezervari& r) {
	//Momentan am facut asa pentru testare, in partea a doua voi gasi o solutie:)
	cout << "1." << r.eveniment << endl;
	cout << "Introduceti numarul aferent evenimentului: " << endl;
	int x = 0;
	cin >> x;
	switch (x)
	{
	case 1:
		cout << r.eveniment << endl;
	default:

		break;
	}

	cout << "Numarul de locuri rezervate: " << endl;
	cin >> x;
	if (x < 1)cout << "Numar invalid.";
	else r.nrlocuriRezervate = x;

	if (r.nrlocuriRezervate > 0) {
		if (r.locuriRezervate != nullptr) {
			delete[]r.locuriRezervate;
		}

		r.locuriRezervate = new int[r.nrlocuriRezervate];
		cout << "Locurile rezervate: " << endl;
		for (int i = 0; i < r.nrlocuriRezervate; i++) {
			in >> r.locuriRezervate[i];
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
		cout << "Datele introduse sunt invalide" << endl;
	}

}
void Rezervari::setEveniment(Eveniment e) {
	if (e.getLocatieEveniment().length() > 0 && e.getNumeEveniment().length() > 0 && e.getPretEveniment() > 0 &&e.getDataEveniment().length()==10 && e.getOraEveniment().length()==5) {
		this->eveniment = e;
	}
	else {
		cout << endl << "Evenimentul nu este valid." << endl;
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


