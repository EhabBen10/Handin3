#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
#include <vector>
using namespace std;

template <typename Comparable>
vector<int> selectionSort(vector<Comparable> vector) {
    int n = vector.size();
    for (int i = 0; i < n - 1; i++) {
        int minimum = i;
        for (int j = i + 1; j < n; j++) {
            if (vector[j] < vector[minimum]) {
                minimum = j;
            }
        }
        if (minimum != i) {
            int temporary = vector[i];
            vector[i] = vector[minimum];
            vector[minimum] = temporary;
        }
    }
    return vector;
}
#endif
