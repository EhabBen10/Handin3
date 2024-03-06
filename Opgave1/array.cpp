#include <vector>
#include <iostream>

bool recursive_search(std::vector<int> A, int value, int index)
{
    // base case
    if (index == A.size())
    {
        return false;
    }
    // base case
    if (A[index] == value)
    {
        return true;
    }
    return recursive_search(A, value, index + 1);
}
// the big oh here is O(n) because we are iterating through the array

std::pair<int, int> recursive_min_max(std::vector<int> &A, int index = 0, int min_val = INT_MAX, int max_val = INT_MIN)
{
    if (index == A.size())
    {
        return std::make_pair(min_val, max_val);
    }
    min_val = std::min(min_val, A[index]);
    max_val = std::max(max_val, A[index]);
    return recursive_min_max(A, index + 1, min_val, max_val);
}
// it is O(n) because we are iterating through the array

int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5};
    int x = 3;
    std::cout << (recursive_search(A, x, 0) ? "True" : "False") << std::endl; // Output: True
    auto min_max = recursive_min_max(A, 0);
    std::cout << "Min: " << min_max.first << ", Max: " << min_max.second << std::endl; // Output: Min: 1, Max: 5
    return 0;
}