#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

Queue::Queue() {
    head = 0;
    tail = 0;
}
Queue::Queue(Queue *q) {
    head = 0;
    tail = 0;
    for (int i = 0; i < q->getSize(); i++) {
        addElem(q->getElem());
    }
}
Queue::~Queue() {
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
}

//добавление элемента
void Queue::addElem (int val) {
    Node* temp = new Node;
    temp->elem = val;
    if (isEmpty()) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

//удаление элемента
void Queue::removeElem() {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    Node* delPtr = head;
    head = head->next;
    delete delPtr;
}
void Queue::removeAllElem() {
    while (!isEmpty()) {
        Node* delPtr = head;
        head = head->next;
        delete delPtr;
    }
}
//извлечение элемента из очереди
int Queue::getElem() {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    Node* ptr = head;
    head = head->next;
    int val = ptr->elem;
    return val;
}

//возвращает количество элементов в очереди
int Queue::getSize() {
    int s = 0;
    for (Node* ptr = head; ptr != 0; ptr = ptr->next) {
        s++;
    }
    return s;
}

//возвращает значение первого элемента очереди, не извлекая его
int Queue::front(){
    if (isEmpty()) {
        string("Queue is empty");
    }
    return head->elem;
}

// заполнение очереди возрастающими числами
void Queue::fillInAscendingOrder(int count) {
    for (int i = 1; i <= count; i++) {
        addElem(i);
    }
}

// заполнение очереди убывающими числами
void Queue::fillInDescendingOrder(int count) {
    for (int i = count; i > 0; i--) {
        addElem(i);
    }
}

//вывод очереди в консоль
void Queue::print() {
    if (isEmpty()) {
        string("Queue is empty");
    }
    for (Node* ptr = head; ptr != 0; ptr = ptr->next) {
        cout<< ptr->elem << " ";
    }
    cout << "\n";
}

//возвращает true, если очередь пуста
bool Queue::isEmpty() {
    return head == 0;
}

//возвращает количество серий в очереди
int Queue::seriesNumberCount() {
    int seriesNumber = 1;
    Node* ptr = head;
    bool thisSeries;
    //определение, возрастает или убывает первая серия
    if (ptr->elem <= ptr->next->elem) {
        thisSeries = true;                //возрастание
    } else {
        thisSeries = false;               //убывание
    }
    for (ptr = head; ptr->next != 0; ptr = ptr->next) {
        if ((ptr->elem <= ptr->next->elem) != thisSeries) {
            seriesNumber ++;
            thisSeries = !thisSeries;
        }
    }
    return seriesNumber;
}

//возвращает контрольную сумму очереди
int Queue::controlSumCount() {
    int sum = 0;
    for (Node* ptr = head; ptr != 0; ptr = ptr->next) {
        sum += ptr->elem;
    }
    return sum;
}
