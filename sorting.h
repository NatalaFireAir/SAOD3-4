#ifndef SORTING
#define SORTING

#include "queue.h"

class Sorting {
private:
    static int c;
    static int m;
    static void merge(Queue *aQueue, Queue *bQueue, Queue *cQueue);
    static void mergeSortProcedure(Queue *originalQueue);
    static bool isLarger(int a, int b);
public:
    Sorting();
    static void mergeSort(Queue *queue);
    static void radixSort(Queue *queue, const int scale);
};
#endif // SORTING

