#include <iostream>
#include <cstring>
#include <cstdlib>

#include "mycollection.h"

using namespace std;

// Переопределяется в классах-наследниках
void MyCollection::addElem(int val){}

// заполнение списка случайными числами
void MyCollection::fillbyRand(int count) {
    for (int i = count; i > 0; i--) {
        addElem(rand()%10000);
    }
}
