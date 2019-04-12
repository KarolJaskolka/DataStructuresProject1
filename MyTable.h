#ifndef MYTABLE_H
#define MYTABLE_H

class MyTable{

public:
    int* table;
    int length;



    MyTable();
    ~MyTable();

    void pushIndex(int index, int value);
    void pushFirst(int value);
    void pushLast(int value);

    void popFirst();
    void popLast();
    void popIndex(int index);
    void popValue(int value);

    int findElement(int value);
    void replaceElement(int old_value,int new_value);

    void show();
    void loadData();
    void loadRandomData(int amount);
    void clearData();

};

#endif // MYTABLE

