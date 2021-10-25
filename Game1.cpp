#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
 
int main()
{
	srand(time(NULL));

	int gracze, x[4], y[4], a = 0, b, e[4] = { 0 };
	int punkty = 0;
	string gracz[4], d;

poczatek:

	cout << "Podaj ilosc graczy (2 - 4): ";
	cin >> gracze;
	if (gracze > 4) {
		cout << "Podaj poprawna ilosc graczy!" << endl << endl;
		Sleep(2000);
		system("cls");
		goto poczatek;

	}
	cout << "Jest " << gracze << " graczy" << endl;

	for (int i = 0; i < gracze; i++) {
		cout << "Podaj nick gracza " << i + 1 << ": ";
		cin >> gracz[i];

	}
	cout << endl;
	for (int rundy = 0; rundy < 6; rundy++) {
		for (int i = 0; i < gracze; i++) {
			cout << "Rzut gracza: " << gracz[i] << endl << endl;
			x[i] = rand() % 6 + 1;
			y[i] = rand() % 6 + 1;
			cout << "Wylosowanie liczby: " << "Pierwsza liczba - " << x[i] << " Druga liczba - " << y[i] << endl;
			if (x[i] == 6 && y[i] == 6) {
				cout << "Trafiono 2 szostki! Dodatkowy rzut" << endl;
				x[i] = rand() % 6 + 1;
				y[i] = rand() % 6 + 1;
				cout << "Wylosowanie liczby: " << "Pierwsza liczba - " << x[i] << "Druga liczba - " << y[i] << endl;
				x[i] = x[i] + 12;
			}
			else if ((x[i] + y[i]) % 2 == 0) {
				cout << "Dodatkowy punkt do wyniku za wynik parzysty!" << endl << endl;
				x[i] += 1;
			}
			else if (x[i] == 1 && y[i] == 1) {
				cout << "Wypadly dwie jedynki - 0 punktow" << endl;
				x[i] = 0;
				y[i] = 0;
			}
			for (int j = 0; j < i; j++) {
				if (x[i] + y[i] == x[j] + y[j]) {
					cout << "Remis z graczem " << gracz[j] << ", powtorny rzut dla obu graczy" << endl << endl;
					cout << "Rzuca gracz " << gracz[j] << endl;
					x[j] = rand() % 6 + 1;
					y[j] = rand() % 6 + 1;
					cout << "Wylosowana liczba to: " << x[j] << " i " << y[j] << endl << endl;
					cout << "Rzuca gracz " << gracz[i] << endl;
					x[i] = rand() % 6 + 1;
					y[i] = rand() % 6 + 1;
					cout << "Wylosowana liczba to: " << x[i] << " i " << y[i] << endl;
					if (x[i] + y[i] == x[j] + y[j]) {
						cout << "Nikt nie dostal punkow!" << endl;
						x[i] = 0;
						y[i] = 0;
						x[j] = 0;
						x[j] = 0;
					}
				}
				a = 0;
				cout << endl << endl;
			}
		}
		for (int i = 0; i < gracze; i++) {
			if (a < x[i] + y[i]) {
				b = i;
				a = x[i] + y[i];
				d = gracz[i];
			}
		}
		cout << "Wygral: " << d << endl;
		e[b]++;
		cout << "Rundy wygrane przez graczy" << endl;
		for (int i = 0; i < gracze; i++) {
			cout << gracz[i] << "-" << e[i] << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < gracze; i++) {
		if (e[i] > a)
		{
			a = e[i];
			d = e[i];
		}
	}
	cout << "Wygrywa: " << d;
}