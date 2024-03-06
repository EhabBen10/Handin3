#include "quick_sort.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

template <typename Comparable>
void show(vector<Comparable> v)
{
    cout << "[";
    for (Comparable i : v)
        cout << i << ", ";
    cout << "]" << endl;
}

int main()
{
    int n_values[] = {10, 100, 1000, 10000};

    for (int n : n_values)
    {
        vector<int> values(n);
        cout << values.size() << endl;
        // Generate Random values
        auto f = []() -> int
        {
            auto v = rand() % 10000;
            return v;
        };

        // Fill up the vector
        generate(values.begin(), values.end(), f);

        // Get starting timepoint
        auto start = high_resolution_clock::now();
        insertionSort(values);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function when insertSort: ";
        cout << duration.count() << endl;

        start = high_resolution_clock::now();
        quickSort(values);
        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function when quickinsert: ";
        cout << duration.count() << endl;

        start = high_resolution_clock::now();
        sort(values.begin(), values.end());
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function when stl sort: ";
        cout << duration.count() << endl;
    }

    return 0;
}