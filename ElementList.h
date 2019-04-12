#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H

class ElementList{

public:

    ElementList *next;
    int value;

    ElementList(int value_arg);
    ~ElementList();

};

#endif // ELEMENTLIST_H_INCLUDED

