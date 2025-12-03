#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

// Function template 'iter' that applies a given F function to each element of T array
template <typename T, typename F>
void iter(T* array, std::size_t length, F function) {
    for (std::size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}

// Overloaded version for const T arrays
// Subject says the function should accept const T&
template <typename T, typename F>
void iter(const T* array, std::size_t length, F function) {
    for (std::size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}
#endif // ITER_HPP