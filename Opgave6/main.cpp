#include "CountingSort.cpp"

using namespace std;

int main() {
    int array[] = {6,5,4,3,2,7,8,1,9};
    int size = sizeof(array) / sizeof(array[0]);
    int k = 9;

    CountingSort sort;
    sort.countingSort(array, size, k); //Arrayet, dets størrelse og den maksimale værdi i array'et

    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    cout << std::endl;

    return 0;
}