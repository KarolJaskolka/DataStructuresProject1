#include "Menu.h"
#include "MyHeap.h"
#include "MyList.h"
#include "MyTable.h"
#include "ElementList.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// funkcje do mierzenia czasu wykonania operacji, ze strony
// http://jaroslaw.mierzwa.staff.iiar.pwr.edu.pl/pamsi/debug_and_time.pdf

LARGE_INTEGER startTimer()
{
    LARGE_INTEGER start;
    DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
    QueryPerformanceCounter(&start);
    SetThreadAffinityMask(GetCurrentThread(), oldmask);
    return start;
}
LARGE_INTEGER endTimer()
{
    LARGE_INTEGER stop;
    DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
    QueryPerformanceCounter(&stop);
    SetThreadAffinityMask(GetCurrentThread(), oldmask);
    return stop;
}

LARGE_INTEGER performanceCountStart,performanceCountEnd;

void options(){

    system("cls");

    cout << endl;
    cout << "0. Koniec" << endl;cout << endl;
    cout << "1. Tablica" << endl;
    cout << "2. Lista" << endl;
    cout << "3. Kopiec" << endl;
    cout << endl;
    cout << "4. Generator liczb do pliku" << endl;cout << endl;
    cout << "Wybor : ";

}

void menuTable(){

    MyTable *myTable = new MyTable();

    int value, index, old_value, choice = 1;

    while(choice){

        system("cls");

        myTable->show();

        cout << endl;
        cout << "0.Koniec" << endl;
        cout << "1.Dodaj na poczatek" << endl;
        cout << "2.Dodaj na koniec" << endl;
        cout << "3.Dodaj w wybrane miejsce" << endl;
        cout << "4.Usun na poczatku" << endl;
        cout << "5.Usun na koncu" << endl;
        cout << "6.Usun w wybranym miejscu" << endl;
        cout << "7.Usun wartosc" << endl;
        cout << "8.Wyszukaj wartosc" << endl;
        cout << "9.Zamien wartosc (Jesli nie ma dodaj na poczatek)" << endl;
        cout << "10.Zaladuj dane z pliku\n" << endl;
        cout << "Choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Dodaj na poczatek wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->pushFirst(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 2:
                cout << "Dodaj na koniec wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->pushLast(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 3:
                cout << "Dodaj w miejscu [Index] : ";
                cin >> index;
                cout << "Wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->pushIndex(index,value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 4:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->popFirst();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 5:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->popLast();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 6:
                cout << "Usun wartosc w miejscu nr : ";
                cin >> index;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->popIndex(index);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 7:
                cout << "Usun wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->popValue(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 8:
                cout << "Wyszukaj wartosc : ";
                cin >> value;

                if(myTable->findElement(value) != -1){

                    cout << "Znaleziono pod indeksem nr [";
                    performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                    myTable->findElement(value);
                    performanceCountEnd = endTimer(); //zapamietujemy koniec czasu
                    cout << myTable->findElement(value);
                    cout << "]" << endl;
                }
                else{ cout << "Nie znaleziono" << endl; }

                break;

            case 9:
                cout << "Wartosc do zamiany : ";
                cin >> old_value;
                cout << "Nowa wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->replaceElement(old_value,value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;
            case 10:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myTable->loadData();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            default:
                break;
        }
        double timeCounter = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
        cout << "Czas:" << timeCounter << " ns" <<endl;
        cout << "Enter" << endl;
        cin.get();cin.get();
    }

    delete myTable;

}

void menuList(){

    MyList *myList = new MyList();

    int value, index, old_value, choice = 1;

    while(choice){

        system("cls");

        myList->show();

        cout << endl;
        cout << "0.Koniec" << endl;
        cout << "1.Dodaj na poczatek" << endl;
        cout << "2.Dodaj na koniec" << endl;
        cout << "3.Dodaj w wybrane miejsce" << endl;
        cout << "4.Usun na poczatku" << endl;
        cout << "5.Usun na koncu" << endl;
        cout << "6.Usun w wybranym miejscu" << endl;
        cout << "7.Usun wartosc" << endl;
        cout << "8.Wyszukaj wartosc" << endl;
        cout << "9.Zamien wartosc (Jesli nie ma dodaj na poczatek)" << endl;
        cout << "10.Zaladuj dane z pliku\n" << endl;
        cout << "Choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Dodaj na poczatek wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->pushFirst(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 2:
                cout << "Dodaj na koniec wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->pushLast(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 3:
                cout << "Dodaj w miejscu [Index] : ";
                cin >> index;
                cout << "Wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->pushIndex(value,index);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 4:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->popFirst();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 5:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->popLast();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 6:
                cout << "Usun wartosc w miejscu nr : ";
                cin >> index;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->popIndex(index);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 7:
                cout << "Usun wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->popValue(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 8:
                cout << "Wyszukaj wartosc : ";
                cin >> value;
                myList->searchElement(value);
                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->findElement(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 9:
                cout << "Wartosc do zamiany : ";
                cin >> old_value;
                cout << "Nowa wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->replaceElement(old_value,value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;
            case 10:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myList->loadData();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            default:
                break;
        }
        double timeCounter = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
        cout << "Czas:" << timeCounter << " ns" <<endl;
        cout << "Enter" << endl;
        cin.get();cin.get();
    }

    delete myList;

}

void menuHeap(){


    MyHeap *myHeap = new MyHeap();

    int value, choice = 1;

    while(choice){

        system("cls");

        myHeap->show31();

        cout << endl;
        cout << "0.Koniec" << endl;
        cout << "1.Dodaj wartosc" << endl;
        cout << "2.Usun wartosc" << endl;
        cout << "3.Wyszukaj wartosc" << endl;
        cout << "4.Zaladuj dane z pliku\n" << endl;
        cout << "Choice : ";
        cin >> choice;

        switch(choice){
            case 1:

                cout << "Dodaj wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myHeap->push(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;
            case 2:

                cout << "Usun wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myHeap->pop(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;

            case 3:

                cout << "Wyszukaj wartosc : ";
                cin >> value;

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myHeap->findValue(value);
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                // metoda zwraca indeks elementu
                // jesli nie znajdzie zwroci -1
                if(myHeap->findValue(value) >= 0){
                    cout << "Znaleziono" << endl;
                }
                else{
                    cout << "Nie znaleziono" << endl;
                }
                break;

            case 4:

                performanceCountStart = startTimer(); //zapamietujemy czas poczatkowy
                myHeap->loadData();
                performanceCountEnd = endTimer(); //zapamietujemy koniec czasu

                break;
            default:

                break;
			}
        double timeCounter = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
        cout << "Czas:" << timeCounter << " ns" <<endl;
        cout << "Enter" << endl;
        cin.get();cin.get();
    }

    delete myHeap;

}

void menuNumbersGenerator(){

    int number;
    int range;
    cout << "Podaj ilosc liczb do wygenerowania : ";
    cin >> number;
    cout << "Podaj zakres liczb do wygenerowania od 0 do : ";
    cin >> range;
    // generowanie liczb
    generator(number,range);

    cout << "Gotowe!" << endl;
    cin.get();cin.get();

}

void generator(int length,int range){

    srand(time(NULL));

    fstream plik;
    // otwarcie pliku
    plik.open("liczby.txt",ios::out);
    // pierwsza linia pliku przechowuje ilosc elementow
    plik << length;
    // generowanie liczb
    for(int i=0;i<length;i++){
        plik << "\n" << rand()%range + 1;
    }
    // zamkniecie pliku
    plik.close();
}
