#include "cumparaBilet.h"


void cumparaBilet::menu() {
m:
	int choice;

	cout << "\t\t\t\t ________________________________________ \n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|         Emitere Bilet Menu             |\n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|________________________________________|\n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|   1) Client                            |\n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|   2) Exit                              |\n";
	cout << "\t\t\t\t|                                        |\n";
	cout << "\t\t\t\t|________________________________________|\n";
	cout << endl;
	cout << endl;
	cout << "\n\t\t\t Va rog selectati un numar! ";
	cout << endl << "\n\t\t\t";
	cin >> choice;
	switch (choice)

	{

	case 1: {
		system("CLS");
		cumparator();
	}

	case 2: {
		system("CLS");
		exit(0);
	}
	default:
	{
		system("CLS");
		cout << endl;

		cout << "Va rugam selecctati din optiunile date.";
		cout << endl;
		cout << endl;
	}

	}
	goto m;

}

void cumparaBilet::cumparator() {
m:
	int choice;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t ____________________ \n";
	cout << "\t\t\t|      Client       |\n";
	cout << "\t\t\t|___________________|\n";
	cout << "\t\t\t| 1) Cumpara Bilet  |\n";
	cout << "\t\t\t|___________________|\n";
	cout << "\t\t\t| 2) Mergi inapoi   |\n";
	cout << "\t\t\t|___________________|\n";
	cout << endl;
	cout << endl;
	cout << "\n\t\t\t Introduceti numarul:  ";
	cout << endl << "\n\t\t\t";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		evenimente();
		int x;
		string choice1;
	n:
		cout << endl;
		cout << "\n\n\t\tDoriti sa cumparati bilet la unul dintre evenimentele disponibile?" << endl;
		cout << "\n\n\t\tIntroduceti y/n." << endl;
		cout << endl << "\n\n\t\t";
		cin >> choice1;
		if (choice1 == "y") x = 1;
		else if (choice1 == "n") x = 0;
		else x = 2;

		switch (x) {
		case 1:
			cumparare();
		case 0:
			system("cls");
			menu();
		case 2:
			system("cls");
			cout << "\n\n\t\tIntroduceti date valide." << endl;
			goto n;
		}

	}
	case 2: {
		system("cls");
		menu();
	}

	default:
		system("cls");
		cout << "\n\n\t\tIntroduceti date valide." << endl;

	}

	goto m;
}

void cumparaBilet::evenimente() {
	cout << "\n\n\t\tEvenimentele disponibile sunt:" << endl;
	Eveniment e1("Film", "Cinema", "12.02.2023", "13:00", 25);
	cout << "\n\n\t\t1." << e1;
	Eveniment e2("Meci", "Stadion", "16.03.2023", "19:00", 45);
	cout << "\n\n\t\t2." << e2;
	Eveniment e3("Comedie", "Teatru", "26.03.2023", "19:30", 30);
	cout << "\n\n\t\t3." << e3;
}

void cumparaBilet::cumparare() {
	Eveniment e1("Film", "Cinema", "12.02.2023", "13:00", 25);
	Eveniment e2("Meci", "Stadion", "16.03.2023", "19:00", 45);
	Eveniment e3("Comedie", "Teatru", "26.03.2023", "19:30", 30);
	Film f1;
	system("cls");
	Clienti c1;
	cout << "\n\n\t\t";
	Rezervari r1;
	evenimente();

	int x = 0;
	cout << endl << "\n\n\t\t";
	do {
		cout << "\n\n\t\tIntroduceti numarul aferent evenimentului: " << endl;
		cout << endl << "\n\n\t\t";
		cin >> x;
		system("cls");
		if (x < 1 || x>3) cout << "\n\n\t\tIntroduceti date valide." << endl;
	} while (x < 1 || x>3);
	cout << "\t\t" << endl;
	if (x == 1) {
		f1 = citireFilm();
				}
					
		cout << f1;
		int x1 = 1;
		do
		{
			x1=1;
			cin >> r1;
			int nr = r1.getnrlocuriRezervate();
			
			if (nr > 25 || nr < 1) {
				cout << "\n\n\t\tNumarul de locuri rezervate nu este valid."<<endl;
				x1 = 0;
			}
			else 
				for (int i = 0; i < nr&&x1==1; i++) {
					int l=r1.getLoc(i);
					int r=r1.getRand(i);
					int ocup = f1.getLoc(r, l);
					if (ocup == 1) {
						x1 = 0;
						cout << "\n\n\t\tLocurile rezervate nu sunt disponibile." << endl;
					}
			}

		} while (x1 == 0);

		if (x1 == 1) {
			int nr = r1.getnrlocuriRezervate();
			for (int i = 0; i < nr && x1 == 1; i++) {
				int l = r1.getLoc(i);
				int r = r1.getRand(i);
				f1.setLoc(r, l, 1);
			}
			scriereFilm(f1);
		}
		
	


	if (x == 1)r1.eveniment = e1;
	else if (x == 2)r1.eveniment = e2;
	else if (x == 3)r1.eveniment = e3;
	cout << r1.getEveniment();


}

Film cumparaBilet::citireFilm() {
	fstream film;
	int a;
	Film f1;
	film.open("locuriFilm.txt", ios::in);
	
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				film >> a;
				f1.setLoc(i, j, a);
				cout << f1.getLoc(i, j);
			}
	}
		film.close();
	return f1;
}


void cumparaBilet::scriereFilm(Film f) {
	fstream film;
	film.open("locuriFilm.txt", ios::out | ios::trunc);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int a = f.getLoc(i, j);
			film << a << " ";
		}

	}
	film.close();
}