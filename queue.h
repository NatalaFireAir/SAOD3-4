#ifndef QUEUE
#define QUEUE

#include "mycollection.h"

class Queue : public MyCollection {
private:
    int c;
    int m;
public:
    Queue();
    Queue (Queue *q);
    ~Queue();

    virtual void addElem (int val);  //enQueue()
    virtual void removeElem();     //dequeue()
    virtual void removeAllElem();
    virtual int getElem();
    virtual int getSize();
    virtual bool isEmpty();
    virtual void fillInAscendingOrder(int count);      //в порядке возрастания
    virtual void fillInDescendingOrder(int count);     //в порядке убывания
    virtual void print();

    virtual int seriesNumberCount();
    virtual int controlSumCount();
    int front();
};
#endif // QUEUE


