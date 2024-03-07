#include <iostream>
#include <fstream>
using namespace std;

const int kolumny = 20;
int strony[kolumny];
int liczbaRamek;
int liczbaZastapien = 0;
bool czyJuzJest = false;
int najdawniejsza = 0;

int main() {
    ifstream plik("dane2.txt"); // Otwiera plik do odczytu
    for (int i = 0; i < kolumny; i++) plik >> strony[i];
    plik >> liczbaRamek; // Wczytanie 2 linii z pliku do zmiennej
    plik.close();   // Zamyka plik

    int ramki[liczbaRamek][liczbaRamek];
    for (int i = 0; i < liczbaRamek; i++) ramki[1][i] = i+1; // Dodanie wiersza z kolejnoscia uzycia do tablicy ramek 
    for (int i = 0; i < liczbaRamek; i++) ramki[0][i] = strony[i]; // Wypelnienie pustych ramek
    for (int i = 0; i < liczbaRamek; i++) cout << ramki[0][i] << " "; // Wyswietlanie aktualnych zawartosci ramek
    cout << "Ramki po 3 wejsciach "  << endl;

    for (int i = liczbaRamek; i < kolumny; i++) { // Glowna petla po stronach
        for (int j = 0; j < liczbaRamek; j++) {
            if(ramki[0][j] == strony[i]) czyJuzJest = true; // Sprawdzenie czy dana strona juz jest w ktorejs z ramek
        }
        if(!czyJuzJest){ // Zmiana ramek
            for (int l = 1; l < liczbaRamek; l++) { // Proces decyzyjny, ktora ramka byla zmieniona najdawniej
                if (ramki[1][l] < ramki[1][najdawniejsza]) najdawniejsza = l;
            }
            ramki[1][najdawniejsza] += 3; // Zmiana numeracji ramek
            ramki[0][najdawniejsza] = strony[i]; // Zastepowanie ramek
            liczbaZastapien++; // Zapis zastapienia strony
        }
        najdawniejsza = 0;
        czyJuzJest = false;
        for (int k = 0; k < liczbaRamek; k++) cout << ramki[0][k] << " "; // Wyswietlanie aktualnych zawartosci ramek
        cout << "Ramki po "<< i+1 <<" wejsciach " << endl;
    }
    cout << "Liczba zastapionych stron "<< liczbaZastapien << endl; // // Wyswietlanie liczby zastapionych stron
    ofstream plikk; // Przesyla raport programu do pliku
    plikk.open("wynikLRU.txt");
    plikk << "Ilosc zastapionych stron dla metody LRU: " << liczbaZastapien<< endl;
    plikk.close();
    return 0;
}