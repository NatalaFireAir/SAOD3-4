#include <iostream>
#include <cstdlib>
#include <ctime>

#include "stack.h"
#include "queue.h"
#include "sorting.h"

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    try {
        Queue queue;
        queue.fillbyRand(10);

        Queue *queue1 = new Queue(queue);
        Sorting::mergeSort(queue1);
        delete queue1;

        Queue *queue2 = new Queue(queue);
        Sorting::radixSort(queue2, 10);
        delete queue2;
    } catch (const string &e) {
        cout<<e<<'\n';
    }
    return 0;
}

