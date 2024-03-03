#include <iostream>
#include "CountingSort.h"

//Udfra pseudokoden på wikisiden
void CountingSort::countingSort(int input[], int size, int k) {
    int* count = new int[k + 1];
    int output[k];

    for (int i = 0; i < size; ++i) {
        int j = input[i];
        count[j]++;
    }

    for (int i = 1; i <= k; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
        int j = input[i];
        count[j]--;
        output[count[j]] = input[i];
    }

    for (int i = 0; i < k; ++i) {
        input[i] = output[i];
    }
}
