#include <iostream>
#include <cstring>
#include <cstdlib>


#include "mycollection.h"

using namespace std;

// Переопределяется в классах-наследниках
void MyCollection::addElem(int val){}

// заполнение списка возрастающими числами
void MyCollection::fillInAscendingOrder(int count) {
    for (int i = 1; i <= count; i++) {
        addElem(i);
    }
}

// заполнение списка убывающими числами
void MyCollection::fillInDescendingOrder(int count) {
    for (int i = count; i > 0; i--) {
        addElem(i);
    }
}

// заполнение списка случайными числами
void MyCollection::fillbyRand(int count) {
    for (int i = count; i > 0; i--) {
        addElem(rand()%10000);
    }
}
