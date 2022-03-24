#include <iostream>
#include <windows.h>

using namespace std;

struct pracownicy {
    string imie;
    string nazwisko;
    string stanowisko;
    string zatrodnienie;
    int pensja_B;
};

int main()
{
    int ilosc = 0;
    int ilosc2 = ilosc + 1;
    int forma;
    int wybor;
    int usun_prac;
    int edyt_stan;
    string nowe_stanowisko;
    pracownicy* prac = new pracownicy[ilosc];


    setlocale(LC_CTYPE, "Polish");

    while (true) {
        cout << "\t\tMENU" << endl;
        cout << "1. Dodaj pracownika\n";
        cout << "2. Wyświetl pracowników\n";
        cout << "3. Usuń pracownika\n";
        cout << "4. Edytuj stanowisko pracownika\n";
        cout << "5. Wyjście\n";
        cout << "Co chcesz zrobić: ";
        cin >> wybor;
        if (wybor == 1) {
            pracownicy* newPrac = new pracownicy[ilosc2];
            copy(prac, prac + min(ilosc, ilosc2), newPrac);
            delete[] prac;
            prac = newPrac;
            for (ilosc; ilosc < ilosc2; ilosc++) {
                cout << "Podaj imie: ";
                cin >> prac[ilosc].imie;
                cout << "Podaj nazwisko: ";
                cin >> prac[ilosc].nazwisko;
                cout << "Podaj stanowisko: ";
                cin >> prac[ilosc].stanowisko;
                while (true) {
                    cout << "Podaj forme zatrudnienia: \n";
                    cout << "1-etat \n";
                    cout << "2-b2b\n";
                    cin >> forma;
                    if (forma == 1) {
                        prac[ilosc].zatrodnienie = "etat";
                        break;
                    }else if (forma == 2) {
                        prac[ilosc].zatrodnienie = "b2b";
                        break;

                    }else {
                        cout << "Podaj poprawny numer!\n";
                    }
                }
                cout << "Podaj pensje brutto: ";
                cin >> prac[ilosc].pensja_B;
            }
            ilosc2++;
        }else if (wybor == 2) {
            for (int i = 0; i < ilosc; i++) {
                cout << endl;
                if(prac[i].imie!=""){
                    cout << "Imie pracownika: " << prac[i].imie << endl;
                    cout << "Nazwisko pracownika: " << prac[i].nazwisko << endl;
                    cout << "Stanowisko pracownika: " << prac[i].stanowisko << endl;
                    cout << "Forma zatrudnienia: " << prac[i].zatrodnienie << endl;
                    cout << "Pensja brutto pracownika: " << prac[i].pensja_B << endl;
                    if (forma == 1) {
                        cout << "Pensja netto pracownika: " << (prac[i].pensja_B * 0.67) << endl;
                    }else {
                        cout << "Pensja netto pracownika: " << (prac[i].pensja_B * 0.9) << endl;

                    }
                } 
            }
            Sleep(2000);
        }else if (wybor == 3) {
            while (true) {
                cout << "Wyjście do panelu - 0\n";
                cout << "Ktorego pracownika chcesz zwolnić: ";
                cin >> usun_prac;
                if (usun_prac > ilosc || usun_prac < 0) {
                    cout << "Nie ma takiego pracownika!\n";
                }
                else if (usun_prac == 0) {
                    break;
                }else {
                    prac[usun_prac - 1].imie = "";
                    cout << "Zwolniono pracownika!" << endl;
                    break;
                }
            }
        }else if (wybor == 4) {
            cout << "Ktorego pracownika stanowisko chcesz edytowac: ";
            cin >> edyt_stan;
            if (edyt_stan > ilosc || edyt_stan < 0) {
                cout << "Nie ma takiego pracownika!\n";
                Sleep(2000);

            }else {
                cout << "Na jakie stanowsiko chcesz zamienic: ";
                cin >> nowe_stanowisko;
                prac[edyt_stan - 1].stanowisko = nowe_stanowisko;
            }
        }else if (wybor == 5) {
            cout << "Wyjście z programu";
            break;
        }
        system("cls");
    }
}