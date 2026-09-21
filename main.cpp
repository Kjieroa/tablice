#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class osoba {
private:
    string imie;
    string nazwisko;
    int nr;

public:
    // funkcja wczytuje dane osoby z pliku.
    void wpisz(ifstream &plik) {
        plik >> imie;
        plik >> nazwisko;
        plik >> nr;
    }

    // funkcja wyœwietla dane osoby na ekranie
    void wyswietl() {
        cout << imie << " " << nazwisko << " " << nr << endl;
    }
};

class klasa {
private:
    string nazwa;
    string wychowawca;
    osoba tablica[30];

public:
    // funkcja pobiera od u¿ytkownika nazwê klasy i nazwisko wychowawcy
    void wpisz() {
        cout << "Podaj nazwe klasy: ";
        cin >> nazwa;

        cout << "Podaj nazwisko wychowawcy: ";
        cin >> wychowawca;
    }

    // funkcja otwiera plik i wczytuje dane
    void wczytajOsoby() {
        ifstream plik("uczniowie.txt");

        if (!plik) {
            cout << "Nie mozna otworzyc pliku!" << endl;
            return;
        }

        for (int i = 0; i < 30; i++) {
            tablica[i].wpisz(plik);
        }

        plik.close();
    }

    // funkcja wyswietla dane wszystkich uczniow znajduj¹cych sie w tablicy
    void wyswietlOsoby() {
        for (int i = 0; i < 30; i++) {
            tablica[i].wyswietl();
        }
    }
};

int main() {
    klasa k;

    k.wpisz();

    k.wczytajOsoby();

    cout << endl << "Lista uczniow:" << endl;
    k.wyswietlOsoby();

    return 0;
}
