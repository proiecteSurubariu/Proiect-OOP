#include<iostream>
#include "Eveniment.h"
#include"Clienti.h"
#include"Rezervari.h"
#include<string>
using namespace std;
 

int main() {
	//Eveniment
	Eveniment e1;
	cout << e1;
	Eveniment e2("nume1", "aici",20);
	cout << e2;
	Eveniment e3 = e2;
	cout << e3;
	//cin >> e2;
	e1.setNumeEveniment("");

	int n[]{ 2,4,5 };

	//Rezervari
	Rezervari r1;
	Rezervari r2(n, 3, e3);
	Rezervari nou(n, 3, e3);


	Rezervari r3 = r2;
	r3 = r2;
	cout << r2<<endl;
	cout << nou<<endl;

	e3.setNumeEveniment("Altnume");
	cout << r2<<endl;
	cout << nou<<endl;

	/*cin >> r2;*/
	cout << r2;
	int* vec = new int[3];
	vec = r2.getlocuriRezervate();
	for (int i = 0; i < 3; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	cout << r2.getnrlocuriRezervate() << endl;
	cout << r2.getEveniment() << endl;
	Rezervari* r = new Rezervari[3];
	r[0] = r2;
	r[1] = r3;
	r[2] = r1;


	//Clienti
	Clienti c1;
	Clienti nul;
	Clienti c2("Ion", "Vasile", "0769237959", r, 3);
		cout << endl;
	Clienti c3 = c2;
	c1 = c2;
	Clienti c4("Maria", "Vasile", "0729995449");
	cout<<c2;
	cout << c4;
	//cin >> c3;
	cout << endl;
	cout<<c2.getNumeClient();
	cout << endl;
	cout << endl;
	cout << nul.getNumeClient();
	cout << endl;
	cout << endl;
	cout << nul.getPrenumeClient();
	cout << endl;
	cout << endl;
	cout << nul.getNrDeTelefonClient();
	cout << endl;
	cout << endl;
	nul.setNumeClient("Nume");
	cout << nul.getNumeClient()<<endl;
	cout << Clienti::getContor();
	Clienti* c = new Clienti[3];
	c[0] = c2;
	c[1] = c2;
	c[2] = c2;
	c2.getNumarIdentificareClient();
	cout << endl;
	cout<<c2.sumaTotalaDePlata();
	cout << endl;
	cout << Clienti::sumaTotalaClienti(c,3)<<endl;
	Rezervari* vector=new Rezervari[3];
	vector = c2.getRezervari();
	cout << vector[1].pretTotal()<<endl;
	try
	{
		cout << c2.discount(99, 0);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	cout << e2.verificareLocatie("aici")<<endl;
	cout << e2.pretCinemarti() << endl;
	cout << r2.pretTotal() << endl;

	cout << (e1 < e2) << endl;
	
	
	
	cout << (r1 == r2) << endl;
	cout << !r2 << endl;

	cout << (c1 + c2);

	 
	 cout << c2<<endl;
	 cout << (string)c2<<endl;
	 cout << (e1++) << endl;
	 cout << (++e1) << endl;

	// cin >> e1;
	 cout << e1 << endl;
	 cout << r1 << endl;
	 //cin >> r1;
	 cout << r1<<endl;
	 Clienti no;
	 cout << no << endl;
	 //cin >> no;
	 cout << no<< endl;
	cout<< c2.getNrDeTelefonClient()<<endl;
	cout << no.getNrDeTelefonClient();

}