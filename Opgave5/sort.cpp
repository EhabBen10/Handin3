#include <iostream>
#include "sort.h"

vector<int> lowToHighSort(vector<int> vector) {
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
