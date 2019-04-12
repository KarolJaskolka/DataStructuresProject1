#ifndef MYHEAP_H
#define MYHEAP_H

class MyHeap{

public:

    int *table;
    int length;



    MyHeap();
    ~MyHeap();

    void push(int value);
    void pop(int value);
    void pushWithoutFix(int value);
    void popWithoutFix(int value);
    int findValue(int value);
    void fix_down(int index);
    void fix_up(int index);
    void createHeap();

    void show();
    void show31();
    void loadData();
    void clearData();
    void loadRandomData(int amount);

};

#endif // MYHEAP

