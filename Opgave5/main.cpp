#include "sort.cpp"

int main() {
    vector<int> numbers = {64, 25, 12, 22, 11};

    cout << "Before: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;
    
    numbers = lowToHighSort(numbers);
    
    cout << "After: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}