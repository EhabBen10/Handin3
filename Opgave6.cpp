
#include <iostream>
#include <vector>
std::vector<int> CountingSort(const std::vector<int>& input, int key) {
    // Tjek om input-vektoren er tom
    if (input.empty()) {
        std::cerr << "Error: Tom vektor" << std::endl;
        return {};
    }
    
    // Tæller-array og output-array
    //listen benyttes af vektoren, hvor alle elementerene i listen sættes til 0
    std::vector<int> count(key + 1, 0);
    std::vector<int> output(input.size());
    //Beregn histogram af keys
    for (int i = 0; i < input.size(); ++i) {
        int j = input[i];
        count[j]++;
    }
    //Udfør præfikssum på tælle-array
    //Præfikssummen bruges til at bestemme de endelige positioner af keys i det sorterende array
    for (int i = 1; i <= key; ++i) {
        count[i] += count[i - 1];
    }
    //Placer elementer på deres sorteringspositioner i output-array
    for (int i = input.size() - 1; i >= 0; --i) {
    // Henter keyvalue
    int keyvalue = input[i];
    // Opdater tælle-arrayet
    count[keyvalue]--;
    // Placer elementet i output-arrayet
    output[count[keyvalue]] = keyvalue;
}
    return output;
}
int main() {
    
    std::vector<int> input = {4, 2, 1, 3, 0, 5, 4};
    int key = *std::max_element(input.begin(), input.end());
    std::vector<int> sorteretArray = CountingSort(input, key);
    // Udskriver det sorteret array
    std::cout << "Det sorteret array er: ";
    for (int num : sorteretArray) {
        std::cout << num << " ";
    }
    return 0;
}
