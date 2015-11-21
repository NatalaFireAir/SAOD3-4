#ifndef COLLECTION
#define COLLECTION

class MyCollection {
protected:
    struct Node {
        Node* next;
        int elem;
        Node():elem(NULL), next(NULL) {
        }
    };
    Node* head;
    Node* tail;

public:
    virtual void addElem(int val);
    int getElem();
    void removeElem();
    bool isEmpty();
    int getSize();    
    void print();

    void fillInAscendingOrder(int count);      //в порядке возрастания
    void fillInDescendingOrder(int count);     //в порядке убывания
    void fillbyRand(int count);

    int seriesNumberCount();
    int controlSumCount();
};
#endif // COLLECTION

