#include <iostream>
#include <cstring>
#include <math.h>

#include "sorting.h"

using namespace std;

//статические переменные:
//счетчик процедур сравнения элементов
int Sorting::c;
//счетчик процедур перемещения элементов в очередь
int Sorting::m;

Sorting::Sorting() {
    c = 0;
    m = 0;
}

//возвращает true, если а больше, чем b
bool Sorting::isLarger(int a, int b){
    c++;
    if(a > b) return true;
    else return false;
}

//Алгоритм слияния
void Sorting::merge(Queue *aQueue, Queue *bQueue, Queue *cQueue) {
    //Пока есть элементы в обеих очередях:
    while (!( aQueue->isEmpty() || bQueue->isEmpty() ) ) {
        //определение, в какой из очередей первый элемент меньше
        //и перемещение его в общую очередь
        if (isLarger(aQueue->front(), bQueue->front())) {
            cQueue->addElem(bQueue->getElem());
            m++;
        } else {
            cQueue->addElem(aQueue->getElem());
            m++;
        }
    }
    //Перемещение оставшихся элементов из непустой очереди
    if (aQueue->isEmpty()) {
        while (!bQueue->isEmpty()) {
            cQueue->addElem(bQueue->getElem());
            m++;
        }
    } else {
        while (!aQueue->isEmpty()) {
            cQueue->addElem(aQueue->getElem());
            m++;
        }
    }
}

//Процедура сортировки слиянием
void Sorting::mergeSortProcedure(Queue *originalQueue) {
    int size = originalQueue->getSize();
    //условие принудительного выхода из функции.
    if (size < 2) return;
    //временные очереди-контейнеры для двух половин сортируемой очереди
    Queue tempHalf1;
    Queue tempHalf2;
    for(int i = 0; i < size/2; i++) {
        tempHalf1.addElem(originalQueue->getElem());
        m++;
    }
    for(int i = 0; i < size -(size/2); i++) {
        tempHalf2.addElem(originalQueue->getElem());
        m++;
    }
    //рекурсивный вызов функции для каждой половины сортируемой очереди
    mergeSortProcedure(&tempHalf1);
    mergeSortProcedure(&tempHalf2);
    Queue temp = Queue();
    //слияние
    merge(&tempHalf1, &tempHalf2, &temp);
    for(int i = 0; i < size; i++) {
        originalQueue->addElem(temp.getElem());
        m++;
    }
}
//Сортировка очереди методом слияния
void Sorting::mergeSort(Queue *queue) {
    int controlSum = queue->controlSumCount();
    char *name = "mergeSort";
    cout << "\n";
    queue->print();
    mergeSortProcedure(queue);
    //вывод результатов сортировки
    cout << name<<":      C = " << c << "     M = " << m << "\n";
    queue->print();
    if (queue->seriesNumberCount() == 1 && queue->controlSumCount() == controlSum) {
        cout << "Correct sorting result \n\n";
    }
    c = 0;
    m = 0;
}

//Сортировка очереди цифровым методом
void Sorting::radixSort(Queue *queue, const int scale ) { //SCALE - система счисления
    //в данном примере сортируется последовательность чисел представленных в десятичной системе
    int controlSum = queue->controlSumCount();
    char *name = "mergeSort";
    queue->print();

    int n;
    int k;
    //создание массива указателей на объекты очереди,
    //используемые в сортировке в качестве промежуточных контейнеров
    Queue *queueDigArray[scale];
    for (int i =0; i < scale; i++) {
        queueDigArray[i] = new Queue;
    }
    //число итераций следует ограничеть максимальным количеством разрядов
    //чесел в сортируемой очереди
    for (int i = 0; i < 4; i++) {
        while (!queue->isEmpty()) {
            n = queue->getElem();
            //k является i-й цифрой в числе n
            k = (n/(int)pow(scale, i))%scale;
            //распределение значений сортируемой очереди по промежуточным контейнерам
            queueDigArray[k]->addElem(n);
            m++;
        }
        for (int j=0; j < scale; j++) {
            while (!queueDigArray[j]->isEmpty()) {
                //перемещение значений из промежуточных контейнеров в сортируемую очередь
                queue->addElem(queueDigArray[j]->getElem());
                m++;
            }
        }
    }
    for (int i =0; i < 10; i++) {
        delete queueDigArray[i];
    }
    //вывод результатов сортировки
    cout << name<<":      C = " << c << "     M = " << m << "\n";
    queue->print();
    if (queue->seriesNumberCount() == 1 && queue->controlSumCount() == controlSum) {
        cout << "Correct sorting result \n\n";
    }
    c = 0;
    m = 0;
}

