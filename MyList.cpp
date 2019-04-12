#include "ElementList.h"
#include "MyList.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

MyList::MyList(){
    // podstawienie za glowe NULL
    head = NULL;
    // podstawienie za zmienna do przeszukiwania NULL
    current = NULL;
    // podstawienie za dlugosc listy 0
    length = 0;

}
MyList::~MyList(){
    while(head != NULL){
        popFirst();
    }
}

void MyList::pushFirst(int value){

    // sprawdzenie czy pierwszy element jest rowny NULL
    if(head == NULL){
        // utworzenie nowego elementu na miejscu pierwszego
        head = new ElementList(value);
    }
    else{
        // przechowanie glowy
        current = head;
        // ustawienie w miejscu glowy nowego elementu
        head = new ElementList(value);
        // ustawienie wskaznika na kolejny element na poprzednia glowe
        head->next = current;
    }
    // zwiekszenie dlugosci listy
    length++;

}
void MyList::pushLast(int value){

    // sprawdzenie czy pierwszy element jest rowny NULL
    if(head == NULL){
        // utworzenie nowego elementu na miejscu pierwszego
        head = new ElementList(value);
    }
    else{
        // ustawienie glowy na obecny element
        current = head;
        // dopoki istnieje nastepny element
        while(current->next != NULL){
            // ustawienie nastepnego elementu na obecny
            current = current->next;
        }
        // po zakonczeniu while current jest ostatnim elementem
        // ustawienie wskaznika na nowy element ktory stanie sie ostatnim
        current->next = new ElementList(value);
    }
    // zwiekszenie dlugosci listy
    length++;
}
void MyList::pushIndex(int value,int index){

    current = head;
    ElementList *prev;
    // sprawdzenie czy podany indeks nie wykracza poza dlugosc listy
    // ale pozostawiajac mozliwosc dodania nowego elementu na koniec
    if(index > length || index < 0){
       cout << "Indeks poza rozmiarem listy" << endl;
    }
    // dodanie na poczatek
    else if(index == 0){
        pushFirst(value);
    }
    // dodanie na koniec
    else if(index == length){
        pushLast(value);
    }
    // dodanie w srodku
    else{
        // ustawienie prev  na element poprzedzajacy podany indeks
        // oraz current na element znajdujacy sie na podanym indeksie
        for(int i=0;i<index;i++){
            prev = current;
            current = current->next;
        }
        // utworzenie nowego elementu
        ElementList *new_element = new ElementList(value);
        // ustawienie poprzedniego elementu zeby wskazywal na nowy
        prev->next = new_element;
        // ustawienie aby nowy element wskazywal na element ktory znajdowal sie predzej na jego pozycji
        new_element->next = current;
        // zwiekszenie dlugosci listy
        length++;
    }
}
void MyList::popFirst(){

    // jesli istnieje pierwszy element
    if(head != NULL){
        // przechowanie nowej glowy
        ElementList *temp = head->next;
        // usuniecie starej glowy
        delete head;
        // ustawienie nowej glowy
        head = temp;

        length--;

    }
    // wyswietlenie informacji
    else{
        cout << "Lista jest pusta" << endl;
    }

}
void MyList::popLast(){

    // wskazniki do przechowywania elementow
    ElementList *temp;
    // sprawdzenie czy glowa jest rozna od NULL
    if(head != NULL){
        // sprawdzenie czy glowa jest jedynym(ostatnim) elementem
        if(head->next == NULL){
            temp = head;
            // zwolnienie pamieci
            delete temp;
            // ustawienie wskaznika glowy na NULL
            head = NULL;
        }
        else{
            temp = head;
            current = head;
            // dopoki temp nie jest ostatnim elementem
            while(temp->next != NULL){
                // ustawienie current na obecny element
                current = temp;
                // ustawienie temp na nastepny element
                temp = temp->next;
            }
            // po zakonczeniu while temp wskazuje na ostatni element
            // a current na przedostatni
            // ustawienie wskaznika current na NULL
            current->next = NULL;
            // zwolnienie pamieci
            delete temp;

        }
        length--;
    }
    // wyswietlenie informacji
    else{
        cout << "Lista jest pusta" << endl;
    }
}
void MyList::popIndex(int index){

    // sprawdzenie czy podany indeks nie wykracza poza dlugosc listy
    if(index < 0 || index >= length){
        cout << "Nie ma elementu o tym indeksie\n";
    }

    else{
        // usuniecie pierwszego elementu
        if(index == 0){
            popFirst();
        }
        // usuniecie ostatniego elementu
        else if(index == length-1){
            popLast();
        }
        // usuniecie elementu ze srodka
        else{
            // tymczasowy wskaznik
            ElementList *temp = head;
            // ustawienie current na poprzedni element niz wskazany ideksem
            // ustawienie temp na element ze wskazanym indeksem
            for(int i=0;i<index;i++){
                current = temp;
                temp = temp->next;
            }
            // jesli temp->next wskazuje na jakis element
            // ustawienie zeby current wskazywal na temp->next
            if(temp->next != NULL){
                current->next = temp->next;
                delete temp;
            }
            // jesli nie ustawienie zeby current wskazywal na NULL
            else{
                current->next = NULL;
                delete temp;
            }
            // zmniejszenie dlugosci listy
            length--;
        }

    }
}
void MyList::popValue(int value){

    ElementList *temp = findElement(value);
    ElementList *prev;
    current = head;
    ElementList *pnext;

    // sprawdzenie czy znaleziony element to glowa
    if(temp == current){
        // usuniecie pierwszego elementu
        popFirst();
    }
    // sprawdzenie czy zwrocony element jest rozny od NULL
    else if(temp != NULL){
        // wyszukanie elementu o pdanej wartosci
        // i ustawienie go jako current
        while(current->value != temp->value){
            prev = current;
            current = current->next;
        }
        pnext = current->next;

        prev->next = pnext;
        current = NULL;
        // zwolnienie pamieci
        delete temp;
    }
    else{
        cout << "Nie ma takiego elementu" << endl;
    }
}
ElementList* MyList::findElement(int value){

    // ustawienie obecnego elementu na glowe
    current = head;
    // dopoki obecny element jest rozny od NULL
    while(current != NULL){
        // jesli wartosc elementu jest rowna podanej zwroc wskaznik na ten element
        if(current->value == value){
            return current;
        }
        // przesuniecie obecnego elementu na nastepny
        current = current->next;
    }
    // jesli nie znaleziono zwroc NULL
    return NULL;
}
// metoda findElement wyswietlajaca informacje na ekranie
void MyList::searchElement(int value){

    bool found = false;
    // ustawienie obecnego elementu na glowe
    current = head;
    // dopoki obecny element jest rozny od NULL
    while(current != NULL){
        // jesli wartosc elementu jest rowna podanej zwroc wskaznik na ten element
        if(current->value == value){
            cout << "Znaleziono" << endl;
            found = true;
            break;
        }
        // przesuniecie obecnego elementu na nastepny
        current = current->next;
    }
    // jesli nie znaleziono zwroc NULL
    if(!found){
        cout << "Nie znaleziono" << endl;
    }

}
void MyList::replaceElement(int old_value, int new_value){

    // jesli findElement nie jest NULL
    if(findElement(old_value) != NULL){
        // podstawienie za current elementu o wartosci old_value
        current = findElement(old_value);
        // zmiana wartosci
        current->value = new_value;
    }
    // jesli jest NULL
    else{
        // dodanie na poczatek
        pushFirst(new_value);
    }
}
void MyList::show(){
    // ustawienie obecnego elementu na glowe
    current = head;
    // wyswietlenie listy
    cout << "Lista : [";
    // dopoki obecny element jest rozny od NULL
    while(current != NULL){
        // wyswietlenie wartosci obecnego elementu
        cout << current->value << " ";
        // przesuniecie obecnego elementu na nastepny
        current = current->next;
    }
    // wyswietlenie dlugosci tablicy
    cout << "] Ilosc elementow : ";
    cout << length << endl;
}
void MyList::loadData(){

    // zwolnienie pamieci
    while(head != NULL){
        popFirst();
    }
    // zaladowanie danych z pliku
    int number;
    int value;
    fstream plik;
    plik.open( "liczby.txt", ios::in );
    plik >> number;

    for(int i=0;i<number;i++){
        plik >> value;
        pushLast(value);
    }
    plik.close();

}
void MyList::clearData(){
    while(head != NULL){
        popFirst();
    }
}
void MyList::loadRandomData(int amount){
    clearData();
    srand(time(NULL));
    for(int i=0;i<amount;i++){
        pushFirst(rand());
    }
}
