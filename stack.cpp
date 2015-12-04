#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

Stack::Stack() {
    head = 0;
    tail = 0;
}
Stack::~Stack() {
    while (head) {
        tail = head->next;
        delete head;
        head = tail;
    }
}
//добавление элемента
void Stack::addElem (int val) {
    Node* temp = new Node;
    temp->elem = val;
    if (tail == 0) {
        tail = temp;
    } else {
        temp -> next=tail;
        tail = temp;
    }
}
//удаление элемента
void Stack::removeElem() {
    if (isEmpty()) {
        throw string("Stack is empty!");
    }
    Node* delptr = tail;
    tail = tail->next;
    delete delptr;
}
//освободить стек
void Stack::removeAllElem() {
    while (!isEmpty()) {
        Node* delptr = tail;
        tail = tail->next;
        delete delptr;
    }
}
//извлечение элемента из стека
int Stack::getElem() {
    if (isEmpty()) {
        throw string("Stack is empty!");
    }
    Node* ptr = tail;
    tail = tail->next;
    int val = ptr->elem;
    delete ptr;
    return val;
}
//возвращает количество элементов в стеке
int Stack::getSize() {
    int s = 0;
    for (Node* ptr = tail; ptr != 0; ptr = ptr->next) {
        s++;
    }
    return s;
}

int Stack::top() {
    if (isEmpty()) {
        throw string("Stack is empty!");
    }
    return tail->elem;
}

// заполнение стека возрастающими числами
void Stack::fillInAscendingOrder(int count) {
    for (int i = count; i > 0; i--) {
        addElem(i);
    }
}

// заполнение стека убывающими числами
void Stack::fillInDescendingOrder(int count) {
    for (int i = 1; i <= count; i++) {
        addElem(i);
    }
}
//вывод стека в консоль
void Stack::print() {
    if (isEmpty()) {
        throw string("Stack is empty!");
    }
    for (Node* ptr = tail; ptr != 0; ptr = ptr->next) {
        cout << ptr->elem <<" ";
    }
    cout<<'\n';
}
//возвращает true, если стек пуст
bool Stack::isEmpty() {
    return tail == 0;
}
//возвращает количество серий в стеке
int Stack::seriesNumberCount() {
    int seriesNumber = 1;
    Node* ptr = tail;
    bool thisSeries;
    //определение, возрастает или убывает первая серия
    if (ptr->elem <= (ptr-1)->elem) {
        thisSeries = true;          //возрастание
    } else {
        thisSeries = false;         //убывание
    }
    for (Node* ptr = tail; ptr->next!= 0; ptr = ptr->next){
        if ((ptr->elem <= ptr->next->elem) != thisSeries) {
            seriesNumber ++;
            thisSeries = !thisSeries;
        }
    }
    return seriesNumber;
}
//возвращает контрольную сумму стека
int Stack::controlSumCount() {
    int sum = 0;
    for (Node* ptr = tail; ptr != 0; ptr = ptr->next) {
        sum += ptr->elem;
    }
    return sum;
}

