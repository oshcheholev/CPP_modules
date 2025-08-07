#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* array, size_t length, void (*function)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        function(array[i]);
    }
}


#endif // ITER_HPP