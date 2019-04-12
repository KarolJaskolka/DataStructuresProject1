#include "MyTable.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

MyTable::MyTable(){
    table = NULL;
    length = 0;
}

MyTable::~MyTable(){
    delete table;
}

void MyTable::pushIndex(int index, int value){

    // sprawdzenie czy podany indeks nie wykracza poza zakres tablicy
    // jesli wykracza
    if(index > length || index < 0){
        cout << "Indeks poza zakresem tablicy" << endl;
    }
    // jesli nie
    else{
        // utworzenie nowej tablicy
        int *new_table = new int[length+1];
        // iterator dla starej tablicy
        int j = 0;
        // przekopiowanie elementow i dodanie nowego
        for(int i = 0; i<length+1; i++){
            // jesli inny indeks od podanego
            if(i != index){
                // skopiowanie elementu
                new_table[i] = table[j];
                // zwiekszenie iteratora dla starej tablicy
                j++;
            }
            // dodanie nowego elementu
            else{
                new_table[i] = value;
            }
        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zwiekszenie dlugosci tablicy
        length++;
    }
}

void MyTable::pushFirst(int value){

        // utworzenie nowej tablicy
        int *new_table = new int[length+1];
        // wstawienie pierwszego elementu
        new_table[0] = value;
        // przekopiowanie elementow starej tablicy
        for(int i = 0; i<length; i++){
            // zaczynajac od elementu o indeksie 1
            // w nowej tablicy
            new_table[i+1] = table[i];
        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zwiekszenie dlugosci tablicy
        length++;

}
void MyTable::pushLast(int value){

        // utworzenie nowej tablicy
        int *new_table = new int[length+1];
        // przekopiowanie elementow starej tablicy
        for(int i = 0; i<length; i++){
            new_table[i] = table[i];
        }
        // wstawienie ostatniego elementu
        new_table[length] = value;
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zwiekszenie dlugosci tablicy
        length++;

}

void MyTable::popIndex(int index){

    // sprawdzenie czy podany indeks nie wykracza poza zakres tablicy
    if(index >= length || index < 0){
        cout << "Indeks poza zakresem tablicy" << endl;
    }
    else{
        // utworzenie nowej tablicy
        int *new_table = new int[length-1];
        // iterator dla nowej tablicy
        int j = 0;

        for(int i=0;i<length;i++){
            // przekopiowanie elementow o indeksie innym
            // niz podany do usuniecia
            if(i != index){

                new_table[j] = table[i];
                // zwiekszenie iteratora dla new_table
                j++;

            }

        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zmniejszenie dlugosci tablicy
        length--;
    }
}
void MyTable::popFirst(){

    if(length > 0){
        // utworzenie nowej tablicy
        int *new_table = new int[length-1];
        // przekopiowanie elementow poza pierwszym
        for(int i=0;i<length-1; i++){
            // table[i+1] po zaczynamy kopiowanie od
            // elementu 1, a nie 0
            new_table[i] = table[i+1];
        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zmniejszenie dlugosc tablicy
        length--;
    }

}
void MyTable::popLast(){

    if(length > 0){
        // utworzenie nowej tablicy
        int *new_table = new int[length-1];
        // przekopiowanie elementow poza ostatnim
        for(int i=0;i<length-1; i++){

            new_table[i] = table[i];

        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zmniejszenie dlugosc tablicy
        length--;
    }

}
int MyTable::findElement(int value){
    // sprawdzenie czy istnieje element o podanej wartosci
    for(int i=0;i<length;i++){
        // jesli tak
        if(table[i] == value){
            // zwrocenie indeksu na ktorym znajduje sie podana wartosc
            return i;
        }
    }
    // zwrocenie -1 (poniewaz nie ma takiego indeksu w tablicy
    return -1;
}
void MyTable::replaceElement(int old_value, int new_value){

    // sprawdzenie pod jakim indeksem znajduje sie szukany element
    int index = findElement(old_value);
    // jesli funkcja zwrocila -1 to nie znaleziono elementu
    if(index == -1){
        // dodanie nowego elementu na poczatek
        pushFirst(new_value);
    }
    // zamiana wartosci o podanym indeksie
    else{
        table[index] = new_value;
    }
}
void MyTable::popValue(int value){

    // sprawdzenie pod jakim indeksem znajduje sie szukany element
    int index = findElement(value);
    // jesli funkcja zwrocila -1 to nie znaleziono elementu
    if(index == -1){
        cout << "Nie ma takiego elementu" << endl;
    }
    // usuniecie elementu o podanej wartosci
    else{
        popIndex(index);
    }
}
void MyTable::loadData(){
    fstream plik;
    plik.open( "liczby.txt", ios::in );
    plik >> length;
    delete table;
    table = new int[length];
    for(int i=0;i<length;i++){
        plik >> table[i];
    }
    plik.close();
}

void MyTable::show(){
    cout << "Tablica : [";
    // wyswietlenie elementow tablicy
    for(int i=0;i<length;i++){
        cout << table[i] << " ";
    }
    // wyswietlenie dlugosci tablicy
    cout << "] Ilosc elementow: ";
    cout << length << endl;
}

void MyTable::clearData(){
    delete table;
    table = NULL;
    length = 0;
}
void MyTable::loadRandomData(int amount){
    // wyczysczenie tablicy
    clearData();
    srand(time(NULL));
    // dodanie podanej ilosci elementow
    for(int i=0;i<amount;i++){
        pushFirst(rand());
    }
}
