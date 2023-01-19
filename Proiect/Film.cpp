#include "Film.h"

ostream& operator<<(ostream& out, Film f) {

	cout << "\n\n\t\tLocurile libere sunt marcate cu 0:\n\n" << endl;
	cout << "\t\t     ---------" << endl;
	cout << "\t\t    |  ECRAN  |  " << endl;
	cout << "\t\t     ---------" << endl;
	cout << "\t\t********LOC***" << endl;
	cout << "\t\t*    1 2 3 4 5" <<endl;
	cout << "\t\t*   ----------"<<endl ;
	
		char nume1[6];
	char nume2[6];
	strcpy_s(nume1, 6, "RAND*");
	strcpy_s(nume2, 6, "12345");
	for (int i = 0; i < 5; i++)
	{
		cout << "\t\t";
		cout << nume1[i] << " ";
		cout << nume2[i] <<"|"<<" ";
		for (int j = 0; j < 5; j++) {

			out << f.locuri[i][j] << " ";
		}

		out << endl;
	}
	out << endl;

	return out;
}



ofstream& operator<<(ofstream& of, Film f) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "\t\t" << endl;
			of << f.locuri[i][j] ;
		}
	}
	return of;
 }

istream& operator>>(istream& in, Film& f) {
	cout << "\n\n\t\tLocuri:";
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cout << "\t\t"<<endl;
			in >> f.locuri[i][j];
		}
	}
	return in;
}

ifstream& operator>>(ifstream& fi, Film& f) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "\t\t" << endl;
			fi >> f.locuri[i][j];
		}
	}
	return fi;
}

int Film::getLoc(int i,int j) {
	
	if (i >= 0 && j < 5 &&i<5&&j>=0) {
		int a = locuri[i][j];
		return a;
	}
	return -1;
	
}

void Film::setLoc(int i,int j,int a) {
	if (i >= 0 && j < 5 && i < 5 && j >= 0 && (a == 0 || a == 1)) {
		locuri[i][j] = a;
	}
	
}