#ifndef STACK
#define STACK

#include "mycollection.h"

class Stack : public MyCollection {
public:
    Stack();
    ~Stack();

    virtual void addElem(int val);   //push()
    virtual void removeElem();      //pop()
    virtual int getElem();
    virtual int getSize();
    virtual bool isEmpty();
    virtual void print();

    virtual int seriesNumberCount();
    virtual int controlSumCount();

    int top();
};
#endif // STACK

