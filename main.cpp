#include <iostream>
#include <cstdlib>
#include <ctime>

#include "stack.h"
#include "queue.h"
#include "sorting.h"

using namespace std;

int main() {
    srand(time(NULL));
    try {
        Queue queue;
        cout << "Lab3\n";
        cout << "QUEUE:\n";
        cout << "инициализация случайными числами\n";
        queue.fillbyRand(20);
        queue.print();
        queue.removeAllElem();
        cout << "инициализация в порядке возрастания\n";
        queue.fillInAscendingOrder(20);
        queue.print();
        queue.removeAllElem();
        cout << "инициализация в порядке убывания\n";
        queue.fillInDescendingOrder(20);
        queue.print();
        cout << "\n";

        Stack stack;
        cout << "STACK:\n";
        cout << "инициализация случайными числами\n";
        stack.fillbyRand(20);
        stack.print();
        stack.removeAllElem();
        cout << "инициализация в порядке возрастания\n";
        stack.fillInAscendingOrder(20);
        stack.print();
        stack.removeAllElem();
        cout << "инициализация в порядке убывания\n";
        stack.fillInDescendingOrder(20);
        stack.print();

        cout << "\n\n";
        cout << "Lab4";
        queue.removeAllElem();
        queue.fillbyRand(10);

        Queue *queue1 = new Queue(queue);
        Sorting::mergeSort(queue1);
        Sorting::mergeSort(queue1);

        Queue *queue2 = new Queue(queue);
        Sorting::radixSort(queue2, 10);
        Sorting::radixSort(queue2, 10);

    } catch (const string &e) {
        cout<<e<<'\n';
    }
    return 0;
}

