#include <iostream>
#include <numeric>
#include "swap_element.h"


int main() {
    // Example usage with a vector
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int index1 = 1;
    int index2 = 3;

    // Swap elements in the vector using the generic algorithm
     std::swap_elements(numbers, index1, index2);

    // Display the modified vector
    for (int num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    // Example used with a list
    std::list<double> values = {1.1, 2.2, 3.3, 4.4, 5.5};
    auto index3 = 1;
    auto index4 = 3;
    // Swap elements in the list using the generic algorithm
    swap_elements(values, index3, index4);

    // Display the modified list
    for (double val : values) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    return 0;
}


