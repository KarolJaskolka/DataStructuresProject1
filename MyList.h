#ifndef MYLIST_H
#define MYLIST_H

#include "ElementList.h"

class MyList{
public:

    ElementList *head;
    ElementList *current;
    int length;

    MyList();
    ~MyList();

    void pushFirst(int value);
    void pushLast(int value);
    void pushIndex(int value,int index);

    void popFirst();
    void popLast();
    void popIndex(int index);
    void popValue(int value);

    ElementList* findElement(int value);
    void replaceElement(int old_value, int new_value);
    void searchElement(int value);

    void show();
    void loadData();
    void loadRandomData(int amount);
    void clearData();

};



#endif // MYLIST_H_INCLUDED

