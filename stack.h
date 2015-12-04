#ifndef STACK
#define STACK

#include "mycollection.h"

class Stack : public MyCollection {
public:
    Stack();
    ~Stack();

    virtual void addElem(int val);   //push()
    virtual void removeElem();      //pop()
    virtual void removeAllElem();
    virtual int getElem();
    virtual int getSize();
    virtual bool isEmpty();
    virtual void fillInAscendingOrder(int count);      //в порядке возрастания
    virtual void fillInDescendingOrder(int count);     //в порядке убывания
    virtual void print();

    virtual int seriesNumberCount();
    virtual int controlSumCount();

    int top();
};
#endif // STACK

