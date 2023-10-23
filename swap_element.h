#ifndef SWAP_ELEMENT_H
#define SWAP_ELEMENT_H

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

/*
This templated function swaps two elements in a container based on their
indices. It provides a way to perform swaps on different types of
containers, including arrays, vectors, and lists.
*/
namespace std _GLIBCXX_VISIBILITY(default){
template <typename Container>
typename Container::value_type swap_elements(Container &container, size_t index1, size_t index2) {
    auto it1 = std::next(container.begin(), index1);
    auto it2 = std::next(container.begin(), index2);
    
    if (it1 != container.end() && it2 != container.end()) {
        std::iter_swap(it1, it2);
        return *it1;
    } else {
        std::cerr << "Invalid indices for element swapping." << std::endl;
        return typename Container::value_type();
    }
}
}

#endif // SWAP_ELEMENT_H
