#include "MyHeap.h"
#include <cmath>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

MyHeap::MyHeap(){
    table = NULL;
    length = 0;
}

MyHeap::~MyHeap(){
    delete table;
}

void MyHeap::push(int value){

        // utworzenie nowej tablicy kopca
        int *new_table = new int[length+1];
        // przekopiowanie elementow starej tablicy kopca
        for(int i = 0; i<length; i++){
            new_table[i] = table[i];
        }
        // wstawienie ostatniego elementu
        new_table[length] = value;
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zwiekszenie dlugosci tablicy kopca
        length++;
        // naprawa kopca w gore
        fix_up(length-1);

}
void MyHeap::pushWithoutFix(int value){

        // utworzenie nowej tablicy kopca
        int *new_table = new int[length+1];
        // przekopiowanie elementow starej tablicy kopca
        for(int i = 0; i<length; i++){
            new_table[i] = table[i];
        }
        // wstawienie ostatniego elementu
        new_table[length] = value;
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zwiekszenie dlugosci tablicy kopca
        length++;

}
void MyHeap::pop(int value){

    int index = findValue(value);

    if(index >= 0){

        table[index] = table[length-1];

        // utworzenie nowej tablicy kopca
        int *new_table = new int[length-1];
        // przekopiowanie elementow poza ostatnim
        for(int i=0;i<length-1; i++){

            new_table[i] = table[i];

        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zmniejszenie dlugosc tablicy kopca
        length--;
        // naprawa kopca w dol
        fix_down(index);
        // naprawa kopca w gore
        fix_up(index);
    }
    else{
        //
        cout << "Nie ma takiego elementu" << endl;
    }

}
void MyHeap::popWithoutFix(int value){

    int index = findValue(value);

    if(index >= 0){

        table[index] = table[length-1];

        // utworzenie nowej tablicy kopca
        int *new_table = new int[length-1];
        // przekopiowanie elementow poza ostatnim
        for(int i=0;i<length-1; i++){

            new_table[i] = table[i];

        }
        // zwolnienie pamieci
        delete table;
        // ustawienie nowej tablicy w miejsce starej
        table = new_table;
        // zmniejszenie dlugosc tablicy kopca
        length--;

    }
    else{
        cout << "Nie ma takiego elementu" << endl;
    }

}
int MyHeap::findValue(int value){
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
// budowanie kopca
void MyHeap::createHeap(){

    for(int i=1;i<length;i++){
        fix_up(i);
    }

}
// naprawa kopca w gore
void MyHeap::fix_up(int index){

    if(index < length && index >= 0 ){
        // sprawdzenie czy dziecko ma wieksza wartosc niz rodzic
        if(table[index] > table[(index-1)/2]){
            // jesli tak
            // zamiana
            int temp = table[index];
            table[index] = table[(index-1)/2];
            table[(index-1)/2] = temp;
            // naprawa w gore
            // sprawdzenie nowego rodzica
            fix_up((index-1)/2);
        }
    }

}
void MyHeap::fix_down(int index){

    if((2*index + 1) < length ){
        int parent = table[index];
        int childOne = table[2*index + 1];
        int childSecond;
        if(2*index + 2 < length){
            childSecond = table[2*index + 2];
        }
        else{
            childSecond = childOne;
        }

        // sprawdzenie ktory potomek jest wiekszy
        if(childOne >= childSecond){
            // sprawdzenie czy potomek jest wiekszy od rodzica
            if(childOne > parent){
                // zamiana
                int temp = table[index];
                table[index] = table[2*index + 1];
                table[2*index + 1] = temp;
                // dalsza naprawa kopca w dol
                fix_down(2*index + 1);
            }

        }
        else{
            // sprawdzenie czy potomek jest wiekszy od rodzica
            if(childSecond > parent){
                // zamiana
                int temp = table[index];
                table[index] = table[2*index + 2];
                table[2*index + 2] = temp;
                // dalsza naprawa kopca w dol
                fix_down(2*index + 2);
            }
        }
    }

}
void MyHeap::show(){
    //
}
// ustawienie kursora na ekranie
void setPosition(int x, int y)
{
    // struktura biblioteki windows.h
    COORD c;
    // przypisanie X
    c.X=x;
    // przypisanie Y
    c.Y=y;
    // ustawienie kursora
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void MyHeap::show31(){

    //wyswietlenie kopca

    setPosition(80,2); if (length < 1) cout<<"_"; else cout<<table[0];

    setPosition(42,6); if (length < 2) cout<<"_"; else cout<<table[1];
    setPosition(117,6); if (length < 3) cout<<"_"; else cout<<table[2];

    setPosition(25,10); if (length < 4) cout<<"_"; else cout<<table[3];
    setPosition(60,10); if (length < 5) cout<<"_"; else cout<<table[4];
    setPosition(100,10); if (length < 6) cout<<"_"; else cout<<table[5];
    setPosition(135,10); if (length < 7) cout<<"_"; else cout<<table[6];

    int X = 15;
    int Y = 14;
    int index = 7;

    for(int i=0;i<8;i++){

        setPosition(X,Y);

        if (length < index+1){
            cout<<"_";
        }
        else{
            cout<<table[index];
        }
        if(i %2 != 0){
            X += 23;
        }else{
            X += 15;
        }

        index++;

    }

    X = 5;
    Y = 18;
    index = 15;

    for(int i=0;i<16;i++){

        setPosition(X,Y);

        if (length < index+1){
            cout<<"_";
        }
        else{
            cout<<table[index];
        }

        X += 10;
        index++;

    }


cout << endl;cout << endl;

}
void MyHeap::loadData(){
    // zwolnienie pamieci
    delete table;
    table = NULL;
    length = 0;
    // zaladowanie danych z pliku
    int number;
    int value;
    fstream plik;
    plik.open( "liczby.txt", ios::in );
    plik >> number;

    for(int i=0;i<number;i++){
        plik >> value;
        push(value);
    }
    plik.close();
}
void MyHeap::clearData(){
    delete table;
    table = NULL;
    length = 0;
}
void MyHeap::loadRandomData(int amount){

    clearData();

    srand(time(NULL));

    for(int i=0;i<amount;i++){
        push(rand());
    }

}
